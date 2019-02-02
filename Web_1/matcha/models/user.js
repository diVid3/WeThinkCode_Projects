const bcrypt = require('bcryptjs');
const mongocon = require('../config/mongocon');
const ObjectID = require('mongodb').ObjectID;

// getUserById() and getUserByUsername() can't be rewritten asynchronously as
// they are used elsewhere. Same with comparePassword().

// getUserById is mainly used by passport.js. This does not create a new _id.
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

module.exports.getDocByVerifyToken = async (verifyToken) => {
  try {
    let db = mongocon.getDb();
    let doc = await db.collection('users').findOne({verifyToken});
    return doc;
  }
  catch (err) {
    throw new Error(err);
  }
}

module.exports.isUserVerified = async (username) => {
  try {
    let db = mongocon.getDb();
    let doc = await db.collection('users').findOne({username});
    if (doc.verified == 1)
      return true;
    return false;
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

// This returns an array of documents. It would be best to use lastSeenId
// with a limit to implement pagination, but lastSeenId makes use of the
// Natural order of ObjectId, which can be out of order within a time frame
// of a second, which could mean that if searching for documents by _id >
// lastSeenId, one would risk missing documents that fit the bill. Hence, I'll
// be relying skip + limit for pagination, in theory, performance should be ok
// as search queries make use of geospatial indexing, which would limit scan
// size, this is assuming the client won't request a ridiculous location range.
// Which in the real world, would happen rarely, however, this could be an
// avenue of attack in order to slow down other legitimate queries. One always
// limit the location search range, however, this is not an ideal solution.
// 
// Apparently, using lastSeenId is fine even though the "natural ascending
// order" might be broken by sub second entries because the id will still be
// unique, it will just end up at another point as the user pages through the
// data.
// 
// UPDATE: Nevermind, scratch the above, the search complexity is not kind
// towards forward paging. Had to resort to using skip.
module.exports.searchUsers = async (searchObj) => {
  try {
    let db = mongocon.getDb();

    var cursor = await db.collection('users').find(
      {
        $and: [
          {
            ipinfoLoc: {
              $near: {
                $geometry: {
                  type: "Point",
                  coordinates: [searchObj.userLong, searchObj.userLat]
                },
                $minDistance: searchObj.locationLow,
                $maxDistance: searchObj.locationHigh
              }
            }
          },
          {
            $and: [{ fameRating: { $gte: searchObj.fameLow } }, { fameRating: { $lte: searchObj.fameHigh } }]
          },
          {
            $and: [{ age: { $gte: searchObj.ageLow } }, { age: { $lte: searchObj.ageHigh } }]
          },
          {
            interests: { $in: searchObj.interestArr }
          }
        ]
      }
    ).sort(searchObj.sort).skip(searchObj.skip).limit(searchObj.limit);

    return (await cursor.toArray());
  }
  catch (err) {
    throw new Error(err);
  }
}

// ------------------------------------------------------------------------ //
