const bcrypt = require('bcryptjs');
const mongocon = require('../config/mongocon');
const ObjectID = require('mongodb').ObjectID;

// The result will be passed to the callback by .findById.
// .findById returns a mongoose query object.
//
// module.exports.getUserById = function (id, callback) {
//     User.findById(id, callback);
// }

// getUserById is mainly used by passport.js
module.exports.getUserById = (id, callback) => {
    let db = mongocon.getDb();
    console.log(`getUserById's passed in id is: ${id}`);

    db.collection('users').findOne({"_id": new ObjectID(id)}, callback);
}

// The result will be passed to the callback by .findOne.
// 
// module.exports.getUserByUsername = function (username, callback) {
//     const query = {username};
//     User.findOne(query, callback);
// }

module.exports.getUserByUsername = (username, callback) => {
    let db = mongocon.getDb();
    db.collection('users').findOne({"username": username}, callback);
}

module.exports.addUser = (newUser, callback) => {
    let db = mongocon.getDb();

    if (db.collection('users').findOne({username: newUser.username})) {
        callback('Username already exists.');
        return false;
    }

    if (db.collection('users').findOne({email: newUser.email})) {
        callback('Email already exists.');
        return false;
    }

    // Not checking for err here, bad habit, but meh.
    // Could also restructure but meh.
    bcrypt.genSalt(10, (err, salt) => {
        bcrypt.hash(newUser.password, salt, (err, hash) => {
            newUser.password = hash;
            db.collection('users').insertOne(newUser, (insertErr, res) => {
                if (insertErr) {
                    callback('Oops! Something went wrong.');
                    return false;
                }
            });
        });
    });
}

// newUser here represents a newly instantiated mongoose model.
// The callback here will need 3 parameters as .save passes 3,
// namely: (error, the saved document, rows affected).
// 
// module.exports.addUser = function (newUser, callback) {
//     bcrypt.genSalt(10, (err, salt) => {
//         bcrypt.hash(newUser.password, salt, (err, hash) => {
//             if (err) throw err;
//             newUser.password = hash;
//             newUser.save(callback);
//         });
//     });
// }

// This function is used by the authentication route in routes/users.js.
module.exports.comparePassword = function (candidatePassword, actualHashedPw, callback) {
    bcrypt.compare(candidatePassword, actualHashedPw, (err, isMatch) => {
        if (err) throw err;
        callback(null, isMatch);
    });
}
