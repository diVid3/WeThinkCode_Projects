// const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');
// const config = require('../config/database');
const mongocon = require('../config/mongocon');
const ObjectID = require('mongodb').ObjectID;

// User schema.
// const UserSchema = mongoose.Schema({
//     name: {
//         type: String
//     },
//     email: {
//         type: String,
//         required: true
//     },
//     username: {
//         type: String,
//         required: true
//     },
//     password: {
//         type: String,
//         required: true
//     }
// });

// The above schema is not exported. The schema is used in conjunction with the
// mongoose.model() method as to return a model associated with the name given
// in this case 'derp'. The name is only used as an identifier for mongoose.

// User is only set here for conveniece.
// const User = module.exports = mongoose.model('derp', UserSchema);

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

    // The passed in id is incorrect, instead of just being the id
    // string, it should be: ObjectId("5c2aa3bb3980573cc5fa167e"),
    // not: "5c2aa3bb3980573cc5fa167e".

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
