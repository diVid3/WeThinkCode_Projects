const bcrypt = require('bcryptjs');
const mongocon = require('../config/mongocon');
const ObjectID = require('mongodb').ObjectID;

// getUserById() and getUserByUsername() can't be rewritten asynchronously as they 
// are used elsewhere. Same with comparePassword().

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

// Async functions.

// Used to see if username already exists.
module.exports.getDocByUsername = async (username) => {
  let db = mongocon.getDb();
  let doc = await db.collection('users').findOne({username});
  return doc;
}

// Used to see if email already exists.
module.exports.getDocByEmail = async (email) => {
  let db = mongocon.getDb();
  let doc = await db.collection('users').findOne({email});
  return doc;
}

// Adds a user to the database.
module.exports.addUserAsync = async (newUser) => {
  let db = mongocon.getDb();
  let salt = bcrypt.genSaltSync(10);
  let hash = bcrypt.hashSync(newUser.password, salt);
  newUser.password = hash;
  await db.collection('users').insertOne(newUser);
}

// ------------------------------------------------------------------------ //
