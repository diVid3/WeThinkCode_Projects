const express = require('express');
const router = express.Router();
const passport = require('passport');
const jwt = require('jsonwebtoken');
const config = require('../config/database');

// User here is the mongoose model instance exported from models/user. User
// will also include the methods exported from /models/user. These User methods
// will need to be replaced/changed.
const User = require('../models/user');

router.post('/register', (req, res, next) => {
    let newUser = {
        name: req.body.name,
        email: req.body.email,
        username: req.body.username,
        password: req.body.password
    };

    // User.addUser(req.app.locals.db, newUser, (errMsg) => {
    User.addUser(newUser, (errMsg) => {
        if (err) {
            let errObj = { success: false, msg: errMsg }
            res.json(errObj);
        }
        else res.json({success: true, msg: 'User registered.'});
    });
});

// The mongoose model instance prototype utilized here.
// router.post('/register', (req, res, next) => {
//     let newUser = new User({
//         name: req.body.name,
//         email: req.body.email, 
//         username: req.body.username,
//         password: req.body.password
//     });

    // Method exported from models/user.js. Arguments passed
    // in originates from mongoose's .save method.
//     User.addUser(newUser, (err, user) => {
//         if (err) { res.json({success: false, msg: 'Failed to register user.'}); }
//         else { res.json({success: true, msg: 'User registered.'}); }
//     });
// });

// Client authentication is required so that they may
// aquire a token to unlock protected routes.
router.post('/authenticate', (req, res, next) => {
    const username = req.body.username;
    const password = req.body.password;
    
    // user is returned by mongoose's .findOne method.
    // User.getUserByUsername(req.app.locals.db, username, (err, user) => {
    User.getUserByUsername(username, (err, user) => {
        if (err) throw err;
        if (!user) return res.json({success: false, msg: 'User not found.'});
        
        // Continue if user was returned.
        User.comparePassword(password, user.password, (err, isMatch) => {
            if (err) throw err;
            if (isMatch) {
                // user is not serializable due to it being a mongoose
                // object, the payload should be a plain object,
                // hence why toJSON() is used.
                const token = jwt.sign(user, config.secret, {expiresIn: 604800});
                res.json({ // json response is for client profile info.
                    success: true,
                    token: `JWT ${token}`,
                    user: {
                        id: user._id,
                        name: user.name,
                        username: user.username,
                        email: user.email
                    }
                });
            }
            else return res.json({success: false, msg: 'Incorrect password.'});
        });
    });
});

// passport.authenticate('jwt', {session: false}) is used to protect a route
// by requiring a client to provide a valid json web token via the authorization
// header. req.user is set by passport when authentication is successful.
// 
// From app.js the passport method (different from passport middleware) is
// required and instantly passed in passport (which is the passport middleware
// instance). That will invoke passport.use() which will set the passport
// strategy to be used when passport.authenticate is called as in below. That
// is a roundabout way to do it though.
// 
// You can instead set the passport strategy straight in app.js. That will re-
// quire the getUserById method in the users model.
router.get('/profile', passport.authenticate('jwt', {session: false}), (req, res, next) => {
    res.json({user: req.user});
});

module.exports = router;
