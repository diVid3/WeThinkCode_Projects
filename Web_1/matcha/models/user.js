const bcrypt = require('bcryptjs');
const mongocon = require('../config/mongocon');
const ObjectID = require('mongodb').ObjectID;

// getUserById() and getUserByUsername() can't be rewritten asynchronously as
// they are used elsewhere. Same with comparePassword().

// getUserById is mainly used by passport.js.
// Don't rewrite.
module.exports.getUserById = (id, callback) => {
  let db = mongocon.getDb();
  db.collection('users').findOne({"_id": new ObjectID(id)}, callback);
}

// Don't rewrite.
module.exports.getUserByUsername = (username, callback) => {
  let db = mongocon.getDb();
  db.collection('users').findOne({"username": username}, callback);
}

// This function is used by the authentication route in routes/users.js.
// Don't rewrite.
module.exports.comparePassword = (candidatePassword, actualHashedPw,
  callback) => {
    bcrypt.compare(candidatePassword, actualHashedPw, (err, isMatch) => {
      if (err) throw err;
      callback(null, isMatch);
    });
  }

// ------------------------------------------------------------------------ //

// Functions rewritten to return promises via async.

module.exports.getDocByUsername = async (username) => {
  try {
    let db = mongocon.getDb();
    let doc = await db.collection('users').findOne({username});
    return doc;
  }
  catch (err) {
    throw new Error(err);
  }
}

module.exports.getDocByEmail = async (email) => {
  try {
    let db = mongocon.getDb();
    let doc = await db.collection('users').findOne({email});
    return doc;
  }
  catch (err) {
    throw new Error(err);
  }
}

module.exports.getDocByResetToken = async (resetToken) => {
  try {
    let db = mongocon.getDb();
    let doc = await db.collection('users').findOne({resetToken});
    return doc;
  }
  catch (err) {
    throw new Error(err);
  }
}

// Adds a user to the database.
module.exports.addUserAsync = async (newUser) => {
  try {
    let db = mongocon.getDb();
    let salt = bcrypt.genSaltSync(10);
    let hash = bcrypt.hashSync(newUser.password, salt);
    newUser.password = hash;
    await db.collection('users').insertOne(newUser);
  }
  catch (err) {
    throw new Error(err);
  }
}

// This is used as a reminder of whether the GeoIndex has been created or not.
module.exports.addIndexCreatedState = async (collection) => {
  try {
    let db = mongocon.getDb();
    await db.collection(collection).insertOne({geoIndexCreated: 1});
  }
  catch (err) {
    throw new Error(err);
  }
}

// This is simply to test whether the GeoIndex has been created.
module.exports.getIndexCreatedState = async (collection) => {
  try {
    let db = mongocon.getDb();
    let cursor = await db.collection(collection).find({});
    return cursor.hasNext();
  }
  catch (err) {
    throw new Error(err);
  }
}

// This errors out due to _id being litteraly written.
// module.exports.replaceUpdatedUserAsync = async (criteria, updatedUser) => {
//   try {
//     let db = mongocon.getDb();
//     await db.collection('users').replaceOne(criteria, updatedUser);
//   }
//   catch (err) {
//     throw new Error(err);
//   }
// }

module.exports.updateUserAsync = async (criteria, fieldsToUpdate) => {
  try {
    let db = mongocon.getDb();
    await db.collection('users').updateOne(criteria, fieldsToUpdate);
  }
  catch (err) {
    throw new Error(err);
  }
}

module.exports.comparePasswordAsync = async (plainPw, actualHash) => {
  try {
    let isMatch = await bcrypt.compare(plainPw, actualHash);
    return isMatch;
  }
  catch (err) {
    throw new Error(err);
  }
}

// Function to create a geospatial index after user registration. This
// uses ComputedPropertyName to enable locName to be used as key.
module.exports.createGeoIndex = async (locName) => {
  try {
    let db = mongocon.getDb();
    await db.collection('users').createIndex({[locName]: "2dsphere"});
  }
  catch (err) {
    throw new Error(err);
  }
}

// ------------------------------------------------------------------------ //
