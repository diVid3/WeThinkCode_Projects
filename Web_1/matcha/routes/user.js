const express = require('express');
const router = express.Router();
const passport = require('passport');
const userController = require('../controllers/user');

// Routes

router.post('/register', userController.registerUser);

router.post('/authenticate', userController.authenticateUser);

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
// 
// Need to be logged in order to access /profile, otherwise no token is pre-
// sented.
router.get('/profile', passport.authenticate('jwt', {session: false}),
userController.getUserProfile);

module.exports = router;
