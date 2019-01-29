const express = require('express');
const router = express.Router();
const passport = require('passport');
const userController = require('../controllers/user');
const multer = require('multer');
const path = require('path');
const uuidv4  = require('uuid/v4');

// ------------------------------------------------------------------------ //

// Configuring multer middleware.
const storage = multer.diskStorage({
  destination: (req, file, cb) => {
    cb(null, 'user_files/images');
  },
  filename: (req, file, cb) => {
    cb(null, uuidv4() + path.extname(file.originalname));
  }
});

const upload = multer({
  storage: storage,
  fileFilter: (req, file, cb) => {
    checkFileType(file, cb);
  }
}).array('pictures', 5);

function checkFileType(file, cb) {
  const fileExtensions = /jpeg|jpg/;
  const validExtension = fileExtensions.test(path.extname(file.originalname)
    .toLowerCase());
  const validMime = fileExtensions.test(file.mimetype);
  
  if (validExtension && validMime)
    return cb(null, true);
  else
    return cb('Only .jpeg and .jpg images are allowed.');
}

// ------------------------------------------------------------------------ //

router.post('/register', userController.registerUser);

router.post('/authenticate', userController.authenticateUser);

router.post('/reset', userController.reset);

router.post('/reset-password', userController.resetPassword);

router.post('/update-password', userController.updatePassword);

router.post('/verify', userController.verifyAccount);

router.post('/search', userController.searchUsers);

router.get('/gen-dummies', userController.generateAccounts);

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

// Will Need to Use multer here.
// router.post('/edit', passport.authenticate('jwt', {session: false}),
// userController.editUserProfile);

// router.post('/edit', upload.array('pictures', 5), userController.editUserProfile);

// Need to manually pass req and res to the controller as the calling of next
// by multer has little effect due to bodyparser only recognizing Content-Type
// headers, multer uses multipart form data.
router.post('/edit', (req, res) => {
  upload(req, res, (err) => {
    if (err)
      res.json({ success: false, msg: err });
    else
      userController.editUserProfile(req, res);
  });
});

// router.post('/editProfileData', passport.authenticate('jwt', {session: false}),
// userController.editUserProfileData);

///TODO REMOVE
// router.get('/add', (req, res) => {
//   if (req.query.token) {
//     console.log(req.query.token);
//   }
// });

module.exports = router;
