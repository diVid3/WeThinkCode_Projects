const mongoose = require('mongoose');
const bcrypt = require('bcryptjs');
const config = require('../config/database');

// User schema.
const UserSchema = mongoose.Schema({
    name: {
        type: String
    },
    email: {
        type: String,
        required: true
    },
    username: {
        type: String,
        required: true
    },
    password: {
        type: String,
        required: true
    }
});

// User is only set here for conveniece.
const User = module.exports = mongoose.model('User', UserSchema);

// The result will be passed to the callback by .findById.
// .findById returns a mongoose query object.
module.exports.getUserById = function (id, callback) {
    User.findById(id, callback);
}

// The result will be passed to the callback by .findOne.
module.exports.getUserByUsername = function (username, callback) {
    const query = {username};
    User.findOne(query, callback);
}

// newUser here represents a newly instantiated mongoose model.
// The callback here will need 3 parameters as .save passes 3,
// namely: (error, the saved document, rows affected).
module.exports.addUser = function (newUser, callback) {
    bcrypt.genSalt(10, (err, salt) => {
        bcrypt.hash(newUser.password, salt, (err, hash) => {
            if (err) throw err;
            newUser.password = hash;
            newUser.save(callback);
        });
    });
}

// This function is used by the authentication route in routes/users.js.
module.exports.comparePassword = function (candidatePassword, actualHashedPw, callback) {
    bcrypt.compare(candidatePassword, actualHashedPw, (err, isMatch) => {
        if (err) throw err;
        callback(null, isMatch);
    });
}
