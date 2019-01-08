const express = require('express');
const router = express.Router();
const passport = require('passport');
const jwt = require('jsonwebtoken');
const config = require('../config/database');

// User here is the mongoose model instance exported from models/user. User
// will also include the methods exported from /models/user. These User methods
// will need to be replaced/changed.
const User = require('../models/user');
const userController = require('../controllers/user');

// router.post('/register', (req, res, next) => {
//     let newUser = {
//         name: req.body.name,
//         email: req.body.email,
//         username: req.body.username,
//         password: req.body.password
//     };

//     User.addUser(newUser, (err, errMsg) => {
//         if (err === 1) {
//             let errObj = { success: false, msg: errMsg }
//             res.json(errObj);
//         }
//         else res.json({success: true, msg: 'User registered.'});
//     });
// });

router.post('/register', (req, res, next) => {
  userController.registerUser(req).then((obj) => {
    res.json(obj)
  })
  .catch((errObj) => {
    res.json(errObj.frontRes);
    console.log(errObj.detailedString);
  });
});

// Client authentication is required so that they may
// aquire a token to unlock protected routes.
// user is returned by mongodb's findOne() method.
router.post('/authenticate', (req, res, next) => {
  const username = req.body.username;
  const password = req.body.password;
    
  User.getUserByUsername(username, (err, user) => {
    if (err) throw err;
    if (!user) return res.json({success: false, msg: 'User not found.'});
    
    // Continue if user was returned.
    User.comparePassword(password, user.password, (err, isMatch) => {
      if (err) throw err;
      if (isMatch) {
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
router.get('/profile', passport.authenticate('jwt', {session: false}),
(req, res, next) => {
  res.json({user: req.user});
});

module.exports = router;
