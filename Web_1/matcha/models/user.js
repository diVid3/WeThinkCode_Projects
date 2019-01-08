const bcrypt = require('bcryptjs');
const mongocon = require('../config/mongocon');
const ObjectID = require('mongodb').ObjectID;

// getUserById is mainly used by passport.js
module.exports.getUserById = (id, callback) => {
  let db = mongocon.getDb();
  db.collection('users').findOne({"_id": new ObjectID(id)}, callback);
}

module.exports.getUserByUsername = (username, callback) => {
  let db = mongocon.getDb();
  db.collection('users').findOne({"username": username}, callback);
}

module.exports.addUser = (newUser, callback) => {
  let db = mongocon.getDb();

  db.collection('users').findOne({username: newUser.username}).then((result) => {
    if (result !== null) { callback(1, 'Username already exists.'); return false; }
  });

  db.collection('users').findOne({email: newUser.email}).then((result) => {
    if (result !== null) { callback(1, 'Email already exists.'); return false; }
  });

  // Not checking for err here, bad habit, but meh.
  // Could also restructure but meh.
  bcrypt.genSalt(10, (err, salt) => {
    if (err) { callback(1, 'Oops! Something went wrong.'); return false }
    bcrypt.hash(newUser.password, salt, (err, hash) => {
      if (err) { callback(1, 'Oops! Something went wrong.'); return false }
      newUser.password = hash;
      db.collection('users').insertOne(newUser, (insertErr, res) => {
        if (insertErr) {
          callback(1, 'Oops! Something went wrong.');
          return false;
        }
        callback(0, 'You\'re registered!'); return false;
      });
    });
  });
}

// This function is used by the authentication route in routes/users.js.
module.exports.comparePassword = function (candidatePassword, actualHashedPw,
callback) {
  bcrypt.compare(candidatePassword, actualHashedPw, (err, isMatch) => {
    if (err) throw err;
    callback(null, isMatch);
  });
}
