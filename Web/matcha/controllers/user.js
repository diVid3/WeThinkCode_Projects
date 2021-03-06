// Basically all code that does not directly interact with the database or views
// goes into controllers. An example, backend validation before committing to
// database, this is assuming that the validation logic does not include busi-
// ness logic.

const userModel = require('../models/user');
const jwt = require('jsonwebtoken');
const config = require('../config/database');
// const path = require('path');
const fs = require('fs');
const nodemailer = require('nodemailer');
const uuidv4  = require('uuid/v4');
const bcrypt = require('bcryptjs');
const faker = require('faker');

// ------------------------------------------------------------------------ //

// db.derps.insert(
//   {
//     loc: { type: "Point", coordinates: [-73.88, 40.78] },
//     name: "La Guardia Airport",
//     category: "Airport"
//   }
// );

// Converts the location string from ipinfo.io to a GeoJSON object.
function ipinfoLocToGeoJSON(ipinfoLocString) {
  let numArr = ipinfoLocString.split(',');
  let longitude = parseFloat(numArr[1]);
  let latitude = parseFloat(numArr[0]);
  return ({ type: "Point", coordinates: [longitude, latitude] });
}

// This might not be needed due to angular interpolation.
function escapeSpecChars(string) {
  return string
  // .replace(/&/g, "&amp;")
  // .replace(/</g, "&lt;")
  // .replace(/>/g, "&gt;")
  // .replace(/"/g, "&quot;")
  // .replace(/'/g, "&#039;");
}

function hasAllRegisterProperties(req) {
  if (
  req.body.firstName == null || req.body.lastName == null ||
  req.body.username == null || req.body.age == null ||
  req.body.gender == null || req.body.sexuality == null ||
  req.body.ipinfoLoc == null ||
  req.body.email == null || req.body.password == null ||
  req.body.firstName == '' || req.body.lastName == '' ||
  req.body.username == '' || req.body.age == '' ||
  req.body.gender == ''|| req.body.sexuality == '' ||
  req.body.ipinfoLoc == '' ||
  req.body.email == '' || req.body.password == '')
    return false;
  return true;
}

// signalObj is passed by reference.
function registerUserInfoValid(req, res, signalObj) {
  let fillMsg = "Please fill in all input fields.";
  let invalidTypeMsg = "Your input types are incorrect.";
  let firstNameTooLong = "First name is too long.";
  let firstNameTooShort = "First name is too short.";
  let lastNameTooLong = "Last name is too long.";
  let lastNameTooShort = "Last name is too short.";
  let usernameTooLong = "Username is too long.";
  let usernameTooShort = "Username is too short.";
  let usernameNotMixed = "Username must contain digits.";
  let correctAgeMsg = "You need to be older than 18 to register.";
  let invalidGenderMsg = "Invalid gender.";
  let invalidSexuality = "Invalid sexuality.";
  let incorrectLocFormat = "ipinfoLocString isn\'t formatted correctly.";
  let incorrectLocSplit = "ipinfoLocString doesn\'t split correctly.";
  let emailTooLong = "Entered email is too long";
  let incorrectEmail = "Entered email is incorrect.";
  let passwordTooLong = "Entered password is too long";
  let passwordTooShort = "Entered password is too short";
  let passwordWeak = "Entered password is weak, try mixing cases, digits and special characters.";

  // Check if all fields filled in.
  if (hasAllRegisterProperties(req) == false)
    return res.json({ success: false, msg: fillMsg });

  // Check types.
  if (
  typeof req.body.firstName != 'string' ||
  typeof req.body.lastName != 'string' ||
  typeof req.body.username != 'string' ||
  typeof req.body.age != 'number' ||
  typeof req.body.gender != 'string' ||
  typeof req.body.sexuality != 'string' ||
  typeof req.body.ipinfoLoc != 'string' ||
  typeof req.body.email != 'string' ||
  typeof req.body.password != 'string')
    return res.json({ success: false, msg: invalidTypeMsg });
  
  let firstNameLength = req.body.firstName.length;
  let lastNameLength = req.body.lastName.length;
  let usernameLength = req.body.username.length;

  // Check firstName, lastName and username.
  if (firstNameLength > 32)
    return res.json({ success: false, msg: firstNameTooLong });
  if (firstNameLength < 2)
    return res.json({ success: false, msg: firstNameTooShort });
  if (lastNameLength > 32)
    return res.json({ success: false, msg: lastNameTooLong });
  if (lastNameLength < 2)
    return res.json({ success: false, msg: lastNameTooShort });
  if (usernameLength > 32)
    return res.json({ success: false, msg: usernameTooLong });
  if (usernameLength < 2)
    return res.json({ success: false, msg: usernameTooShort });
  if (/\d/.test(req.body.username) == false)
    return res.json({ success: false, msg: usernameNotMixed });

  // Check age.
  if (req.body.age < 18)
    return res.json({ success: false, msg: correctAgeMsg });

  // Check gender.
  if (
  req.body.gender != 'Male' &&
  req.body.gender != 'Female' &&
  req.body.gender != 'Other')
    return res.json({ success: false, msg: invalidGenderMsg });

  // Check sexuality.
  if (
  req.body.sexuality != 'Heterosexual' &&
  req.body.sexuality != 'Homosexual' &&
  req.body.sexuality != 'Bisexual')
    return res.json({ success: false, msg: invalidSexuality });

  // Check ipinfoLoc
  if (req.body.ipinfoLoc.includes(',') == false)
    return res.json({ success: false, msg: incorrectLocFormat });
  let numArr = req.body.ipinfoLoc.split(',');
  if (numArr.length != 2)
    return res.json({ success: false, msg: incorrectLocSplit });

  // Check valid email.
  if (req.body.email.length > 64)
    return res.json({ success: false, msg: emailTooLong });
  let re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  // console.log(re.test(req.body.email.toLowerCase()));
  if (re.test(req.body.email.toLowerCase()) == false)
    return res.json({ success: false, msg: incorrectEmail });

  // Check password strength.
  let passwordLength = req.body.password.length;
  if (passwordLength > 1024) // For buffer overflow?
    return res.json({ success: false, msg: passwordTooLong });
  if (passwordLength < 7)
    return res.json({ success: false, msg: passwordTooShort });
  if (
  /[a-z]+/.test(req.body.password) == false ||
  /[A-Z]+/.test(req.body.password) == false ||
  /[0-9]+/.test(req.body.password) == false ||
  /[^\[\]${*}()\\+|?<>!@`#,%.&*-]+/.test(req.body.password) == false)
    return res.json({ success: false, msg: passwordWeak });

  // Signalling that input passed.
  signalObj.passedInputValidation = true;
}

async function sendVerifyToken(emailAddress, verifyToken) {
  await userModel.updateUserAsync(
    { 'email' : emailAddress },
    {
      $set: {
        'verifyToken' : verifyToken
      }
    }
  );

  // Nodemailer options.
  let mailOptions = {
    from: '"Matcha" <11smtptest11@gmail.com>',
    to: `${emailAddress}`,
    subject: "Verify Account | Matcha",
    text: `Please click on this link to verify your account:
    http://localhost:4200/verify/${verifyToken}`
  };
  await transporter.sendMail(mailOptions);
}

module.exports.registerUser = async (req, res, next) => {
  let userExists = 'Username already exists. Please try another one.';
  let emailExists = 'Email already exists. Please try another one.';
  let userRegistered = "You\'re registered! To verify your registration, follow the instructions in the email we've sent you.";

  // Input validation.
  let signalObj = { passedInputValidation: false }; // Passed by reference.
  registerUserInfoValid(req, res, signalObj);
  if (signalObj.passedInputValidation == false)
    return;

  // Generating token for verifying account.
  let verifyToken = uuidv4();
  
  // Generating user profile.
  let newUser = {
    firstName: escapeSpecChars(req.body.firstName),
    lastName: escapeSpecChars(req.body.lastName),
    username: escapeSpecChars(req.body.username),
    age: req.body.age,
    gender: req.body.gender,
    sexualPreference: req.body.sexuality,
    biography: 'I like trains!',
    interests: ["Matcha"],
    pictures: [
      "../../../assets/default-avatar3-small.png",
      "../../../assets/default-avatar3-small.png",
      "../../../assets/default-avatar3-small.png",
      "../../../assets/default-avatar3-small.png"
    ],
    avatar: "../../../assets/default-avatar3-small.png",
    ipinfoLoc: ipinfoLocToGeoJSON(req.body.ipinfoLoc),
    fameRating: 0,
    resetToken: '',                                 // Used for pw reset.
    verifyToken: verifyToken,                       // Used for verification.
    verified: 0,                                    // Need to verify.
    email: req.body.email,
    password: req.body.password,
  }

  let exitOnDupUsername = 0;
  let exitOnDupEmail = 0;

  // Checking if already registered.
  await Promise.all([
    userModel.getDocByUsername(newUser.username),
    userModel.getDocByEmail(newUser.email)
  ])
  .then((values) => {
    if (values[0]) return (exitOnDupUsername = 1);
    else if (values[1]) return (exitOnDupEmail = 1);
  })
  .catch((error) => {
    console.log(error);
  });

  // Exiting if already registered.
  if (exitOnDupUsername)
    return res.json({ success: false, msg: userExists });
  else if (exitOnDupEmail)
    return res.json({ success: false, msg: emailExists });

  // Registering user, also creates a geospatial index if one does not exist.
  userModel.addUserAsync(newUser)
  .then(async () => {
    let geoIndexCreated = await
      userModel.getIndexCreatedState('geoIndexCreated');
    if (geoIndexCreated == false) {
      await userModel.createGeoIndex("ipinfoLoc");
      await userModel.addIndexCreatedState('geoIndexCreated');
    }
    res.json({ success: true, msg: userRegistered });
  });

  // Sync not needed.
  sendVerifyToken(newUser.email, verifyToken);
}

// ------------------------------------------------------------------------ //

module.exports.authenticateUser = async (req, res, next) => {
  if (req.body.username == '' || req.body.password == '' ||
  req.body.username == null || req.body.password == null)
    return res.json({ success: false, msg: 'Please fill in all fields.' });

  const username = req.body.username;
  const password = req.body.password;

  // Check if user exists.
  let user = await userModel.getDocByUsername(escapeSpecChars(username));
  if (!user) return res.json({success: false, msg: 'User not found.'});

  // Check if user is verified.
  let userVerified = await userModel.isUserVerified(username);
  if (!userVerified) return res.json({ success: false, msg: 'User account not verified.' });

  // Check if correct password.
  let passwordMatch = await userModel.comparePasswordAsync(password,
    user.password);
  if (passwordMatch) {
    let token = jwt.sign(user, config.secret, {expiresIn: 604800});
    let authUser = {
      id: user._id,
      firstName: user.firstName,
      lastName: user.lastName,
      username: user.username,
      email: user.email,
      age: user.age,
      gender: user.gender,
      sexualPreference: user.sexualPreference,
      biography: user.biography,
      interests: user.interests,
      pictures: user.pictures,
      avatar: user.avatar,
      ipinfoLoc: user.ipinfoLoc,
      fameRating: user.fameRating
    }
    let resObj = {
      success: true,
      token: `JWT ${token}`,
      user: authUser // Nested.
    }
    res.json(resObj); // JSON response is for client profile info.
  }
  else return res.json({success: false, msg: 'Incorrect password.'});
}

// ------------------------------------------------------------------------ //

// Sends back profile info, this was actually stored in the token itself.
// req.user is set when passport.js calls done(null, user). That user object
// is retrieved by getUserById() in config/passport.js.
module.exports.getUserProfile = (req, res, next) => {
  res.json({user: req.user});
}

// ------------------------------------------------------------------------ //

// This is to check whether all updatedUser info is present. updatedUser is
// pretty much a new profile form, so same checks.
function hasAllUpdateProperties(updatedUser) {
  if (
    updatedUser.firstName == null || updatedUser.lastName == null ||
    updatedUser.username == null || updatedUser.age == null ||
    updatedUser.gender == null || updatedUser.sexualPreference == null ||
    updatedUser.ipinfoLoc == null ||
    updatedUser.email == null || updatedUser.password == null ||
    updatedUser.firstName == '' || updatedUser.lastName == '' ||
    updatedUser.username == '' || updatedUser.age == '' ||
    updatedUser.gender == ''|| updatedUser.sexualPreference == '' ||
    updatedUser.ipinfoLoc == '' ||
    updatedUser.email == '' || updatedUser.password == '')
      return false;
    return true;
}

// Checks whether the updated profile input is valid or not.
function updatedUserInfoValid(updatedUser, res, signalObj) {
  let fillMsg = "Please fill in all input fields.";
  let firstNameTooLong = "First name is too long.";
  let firstNameTooShort = "First name is too short.";
  let lastNameTooLong = "Last name is too long.";
  let lastNameTooShort = "Last name is too short.";
  let emailTooLong = "Entered email is too long";
  let incorrectEmail = "Entered email is incorrect.";
  let invalidGenderMsg = "Invalid gender.";
  let invalidSexuality = "Invalid sexuality.";
  let biographyTooLong = "Your biography is too long";

  // Checking if all fields present.
  if (hasAllUpdateProperties(updatedUser) == false)
    return res.json({ success: false, msg: fillMsg });

  let firstNameLength = updatedUser.firstName.length;
  let lastNameLength = updatedUser.lastName.length;

  // Check firstName, lastName and username.
  if (firstNameLength > 32)
    return res.json({ success: false, msg: firstNameTooLong });
  if (firstNameLength < 2)
    return res.json({ success: false, msg: firstNameTooShort });
  if (lastNameLength > 32)
    return res.json({ success: false, msg: lastNameTooLong });
  if (lastNameLength < 2)
    return res.json({ success: false, msg: lastNameTooShort });

  // Check valid email.
  if (updatedUser.email.length > 64)
    return res.json({ success: false, msg: emailTooLong });
  let re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  if (re.test(updatedUser.email.toLowerCase()) == false)
    return res.json({ success: false, msg: incorrectEmail });

  // Check gender.
  if (
    updatedUser.gender != 'Male' &&
    updatedUser.gender != 'Female' &&
    updatedUser.gender != 'Other')
      return res.json({ success: false, msg: invalidGenderMsg });

  // Check sexuality.
  if (
    updatedUser.sexualPreference != 'Heterosexual' &&
    updatedUser.sexualPreference != 'Homosexual' &&
    updatedUser.sexualPreference != 'Bisexual')
      return res.json({ success: false, msg: invalidSexuality });

  // Check biography.
  if (updatedUser.biography.length > 1024)
    return res.json({ success: false, msg: biographyTooLong });

  signalObj.passedInputValidation = true;
}

module.exports.editUserProfile = async (req, res, next) => {
  let updatedUser = JSON.parse(req.body.updatedUserProfile);

  // Validating updated user profile info. res is used to send back messages
  // upon failure, signalObj is used to hold the failure state.
  let signalObj = { passedInputValidation: false };
  updatedUserInfoValid(updatedUser, res, signalObj);
  if (signalObj.passedInputValidation == false)
    return;

  // Updating image paths to point to locally stored images. Also deleting if
  // need be.
  let dirnameArr = __dirname.split('/');
  let dirnameArrLength = dirnameArr.length;
  let pathToMatcha = '/';
  for (let i = 1; i < dirnameArrLength - 1; i++)
    pathToMatcha += (dirnameArr[i] + '/');

  let filesArrLength = req.files.length;
  if (filesArrLength >= 1) {
    if (!updatedUser.avatar.includes('../../../')) {
      let stringArr = updatedUser.avatar.split('/');
      let delPath = pathToMatcha + 'user_files/' + 'images/' + stringArr[4];
      fs.unlink(delPath, (err) => {console.log(err)});
    }
    updatedUser.avatar = ('http://localhost:3000/' + req.files[0].path).replace('/user_files', '');
  }
  if (filesArrLength >= 2)
    for (let i = 1; i < filesArrLength; i++) {
      if (!updatedUser.pictures[i - 1].includes('../../../')) {
        let stringArr = updatedUser.pictures[i - 1].split('/');
        let delPath = pathToMatcha + 'user_files/' + 'images/' + stringArr[4];
        fs.unlink(delPath, (err) => {console.log(err)});
      }
      updatedUser.pictures[i - 1] = ('http://localhost:3000/'
      + req.files[i].path).replace('/user_files', '');
    }

  await userModel.updateUserAsync(
    { 'username' : updatedUser.username },
    {
      $set: {
        'firstName' : updatedUser.firstName,
        'lastName' : updatedUser.lastName,
        'email' : updatedUser.email,
        'gender' : updatedUser.gender,
        'sexualPreference' : updatedUser.sexualPreference,
        'biography' : updatedUser.biography,
        'interests' : updatedUser.interests,
        'ipinfoLoc' : updatedUser.ipinfoLoc,
        'avatar' : updatedUser.avatar,
        'pictures' : updatedUser.pictures
      }
    }
  );

  res.json({success: true, msg: 'Profile updated!'});
}

// ------------------------------------------------------------------------ //

// Setting up a nodemailer transporter.
let transporter = nodemailer.createTransport({
  host: "smtp.gmail.com",
  port: 587,
  secure: false,
  auth: {
    user: '11smtptest11@gmail.com',
    pass: '@smtpTest123'
  },
  tls: {
    rejectUnauthorized: false
  }
});

module.exports.reset = async (req, res, next) => {
  let emailTooLong = "Entered email is too long";
  let incorrectEmail = "Entered email is incorrect.";

  // Check valid email.
  if (req.body.enteredEmail.length > 64)
    return res.json({ success: false, msg: emailTooLong });
  let re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  if (re.test(req.body.enteredEmail.toLowerCase()) == false)
    return res.json({ success: false, msg: incorrectEmail });

  // Check if email exists, if not, don't let user know as that can be used
  // to find valid emails.
  let doc = await userModel.getDocByEmail(req.body.enteredEmail);
  if (!doc) {
    // Sync not needed.
    setTimeout(() => {
      res.json({success: true, msg: 'Reset email sent, check your mail!'});
    }, 2000);
    return;
  }

  let resetToken = uuidv4();
  await userModel.updateUserAsync(
    { 'email' : req.body.enteredEmail },
    {
      $set: {
        'resetToken' : resetToken
      }
    }
  );

  // Nodemailer options.
  let mailOptions = {
    from: '"Matcha" <11smtptest11@gmail.com>',
    to: `${req.body.enteredEmail}`,
    subject: "Reset Password | Matcha",
    text: `Please click on this link to reset your password:
    http://localhost:4200/reset-password/${resetToken}`
  };

  await transporter.sendMail(mailOptions);
  res.json({success: true, msg: 'Reset email sent, check your mail!'});
}

// ------------------------------------------------------------------------ //

module.exports.resetPassword = async (req, res, next) => {
  // Need to verify if received token is valid by checking against db.
  // let resetToken = req.body.resetToken;
  let doc = await userModel.getDocByResetToken(req.body.resetToken);
  if (!doc) {
    res.json({success: false, msg: 'Reset token is invalid.'});
    return;
  }
  res.json({success: true, msg: 'Reset token valid.'});
}

// ------------------------------------------------------------------------ //

module.exports.updatePassword = async (req, res, next) => {
  let fillMsg = "Please fill in all input fields.";
  let passwordTooLong = "Entered password(s) is too long";
  let passwordTooShort = "Entered password(s) is too short";
  let passwordWeak = "Entered password(s) is weak, try mixing cases, digits and special characters.";
  let passwordsNotMatch = "Your passwords do not match.";
  let passwordResetMsg = "Password reset! You may now login.";

  let newPassword = req.body.newPassword;
  let newConfirmedPassword = req.body.newConfirmedPassword;
  let resetToken = req.body.resetToken;

  if (newPassword == '' || newConfirmedPassword == '' ||
  newPassword == null || newConfirmedPassword == null) {
    res.json({ success: false, msg: fillMsg });
    return;
  }

  // Check password strength.
  let passwordLength = newPassword.length;
  if (passwordLength > 1024) // For buffer overflow?
    return res.json({ success: false, msg: passwordTooLong });
  if (passwordLength < 7)
    return res.json({ success: false, msg: passwordTooShort });
  if (
  /[a-z]+/.test(newPassword) == false ||
  /[A-Z]+/.test(newPassword) == false ||
  /[0-9]+/.test(newPassword) == false ||
  /[^\[\]${*}()\\+|?<>!@`#,%.&*-]+/.test(newPassword) == false)
    return res.json({ success: false, msg: passwordWeak });

  if (newPassword != newConfirmedPassword)
    return res.json({ success: false, msg: passwordsNotMatch });

  // Need to encrypt password before persisting it.
  let salt = bcrypt.genSaltSync(10);
  let hash = bcrypt.hashSync(newPassword, salt);
  
  // Updating/resetting user password.
  await userModel.updateUserAsync(
    { 'resetToken' : resetToken },
    {
      $set: {
        'password' : hash,
        'resetToken' : ''
      }
    }
  );

  res.json({ success: true, msg: passwordResetMsg });
}

// ------------------------------------------------------------------------ //

module.exports.verifyAccount = async (req, res, next) => {
  let verifyToken = req.body.verifyToken;

  // Need to get doc by verifyToken, check if exists.
  let doc = await userModel.getDocByVerifyToken(verifyToken);
  if (!doc) {
    res.json({success: false, msg: 'Verify token is invalid.'});
    return;
  }

  // Updating verified status.
  await userModel.updateUserAsync(
    { 'verifyToken' : verifyToken },
    {
      $set: {
        'verified' : 1,
        'verifyToken' : ''
      }
    }
  );

  res.json({success: true, msg: 'Account verified! You may now login.'});
}

// ------------------------------------------------------------------------ //

// firstName: escapeSpecChars(req.body.firstName),
// lastName: escapeSpecChars(req.body.lastName),
// username: escapeSpecChars(req.body.username),
// age: req.body.age,
// gender: req.body.gender,
// sexualPreference: req.body.sexuality,
// biography: 'I like trains!',
// interests: ["Matcha"],
// pictures: [
//   "../../../assets/default-avatar3-small.png",
//   "../../../assets/default-avatar3-small.png",
//   "../../../assets/default-avatar3-small.png",
//   "../../../assets/default-avatar3-small.png"
// ],
// avatar: "../../../assets/default-avatar3-small.png",
// ipinfoLoc: ipinfoLocToGeoJSON(req.body.ipinfoLoc),
// fameRating: 0,
// resetToken: '',
// verifyToken: verifyToken,
// verified: 0,
// email: req.body.email,
// password: req.body.password
// 
// WTC: Latitude: -26.205275 | Longitude: 28.040176
// 
// Few clicks east:
//   Latitude: -26.204787 | Longitude: 28.072079    Right increases longitude.
// Few clicks west:
//   Latitude: -26.205018 | Longitude: 28.005284    Left decreases longitude.
// Few clicks north:
//   Latitude: -26.182329 | Longitude: 28.039179    Up decreases latitude.
// Few clicks south:
//   Latitude: -26.228079 | Longitude: 28.04126     Down increases latitude.
// 
// ipinfoLoc : {
// 	type : "Point",
// 	coordinates : [
// 		27.986925245748125,
// 		-26.160563093139757
// 	]
// }

// Controller to generate dummy accounts. Verified needs to be set to 1.
module.exports.generateAccounts = async (req, res, next) => {
  if (req.query == undefined || req.query == null ||
    req.query.amount == undefined || req.query.amount == null)
    return res.send("Could not create dummy profiles, missing get parameters.");

  let genDummyAmount = parseFloat(req.query.amount);

  if (isNaN(genDummyAmount))
    return res.send("Could not create dummy profiles, passed in dummy amount is not a number.");

  // Loop to generate dummy accounts, one big loop.
  for (let i = 0; i < genDummyAmount; i++) {

    // Generating a gender.
    let fakeGender = "Male";
    let fakeGenderNum = faker.random.number({min: 1, max: 3, precision: 1});
    if (fakeGenderNum == 1)
      fakeGender = "Male";
    if (fakeGenderNum == 2)
      fakeGender = "Female";
    if (fakeGenderNum == 3)
      fakeGender = "Other";

    // Generating a sexual preference.
    let fakeSexPref = "Heterosexual";
    let fakeSexPrefNum = faker.random.number({min: 1, max: 3, precision: 1});
    if (fakeSexPrefNum == 1)
      fakeSexPref = "Heterosexual";
    if (fakeSexPrefNum == 2)
      fakeSexPref = "Homosexual";
    if (fakeSexPrefNum == 3)
      fakeSexPref = "Bisexual";

    // Generating fake interest array.
    let interestList = [
      "Matcha",
      "Sports",
      "Art",
      "Gaming",
      "Traveling",
      "Music",
      "Cooking",
      "Reading",
      "Computers",
      "Movies"
    ];
    let interestAmountNum = faker.random.number({min: 1, max: 10, precision: 1});
    let fakeInterestArr = [];
    for (let i = 0; i < interestAmountNum; i++) {
      let pickInterestNum = faker.random.number({min: 0, max: 9, precision: 1});
      switch (interestList[pickInterestNum]) {
        case "Matcha":
          if (fakeInterestArr.includes("Matcha") == false)
            fakeInterestArr.push("Matcha");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Sports":
          if (fakeInterestArr.includes("Sports") == false)
            fakeInterestArr.push("Sports");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Art":
          if (fakeInterestArr.includes("Art") == false)
            fakeInterestArr.push("Art");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Gaming":
          if (fakeInterestArr.includes("Gaming") == false)
            fakeInterestArr.push("Gaming");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Traveling":
          if (fakeInterestArr.includes("Traveling") == false)
            fakeInterestArr.push("Traveling");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Music":
          if (fakeInterestArr.includes("Music") == false)
            fakeInterestArr.push("Music");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Cooking":
          if (fakeInterestArr.includes("Cooking") == false)
            fakeInterestArr.push("Cooking");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Reading":
          if (fakeInterestArr.includes("Reading") == false)
            fakeInterestArr.push("Reading");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Computers":
          if (fakeInterestArr.includes("Computers") == false)
            fakeInterestArr.push("Computers");
          else {
            i = i - 1;
            continue;
          }
          break;
        case "Movies":
          if (fakeInterestArr.includes("Movies") == false)
            fakeInterestArr.push("Movies");
          else {
            i = i - 1;
            continue;
          }
          break;
        // Don't want default case as each push needs to be unique.
      }
    }
    
    // Generating fake ipinfoLoc.
    // Decreasing precision to e.g. 0.1 will increase distances apart.
    let fakeLong = parseFloat(Number(faker.random.number({
      min: 27.98, max: 28.13, precision: 0.0000000000000001
    })).toFixed(15));
    let fakeLat = parseFloat(Number(faker.random.number({
      min: -26.1, max: -26.3, precision: 0.0000000000000001
    })).toFixed(15));
    let fakeIpinfoLoc = {
      type: "Point",
      coordinates: [
        fakeLong,     // Float.
        fakeLat       // Float.
      ]
    }

    // Creating fakeUser object.
    let fakeUser = {
      firstName: await faker.name.firstName(),
      lastName: await faker.name.lastName(),
      username: await faker.internet.userName(this.firstName, this.lastName),
      age: faker.random.number({min: 18, max: 45, precision: 1}),
      gender: fakeGender,
      sexualPreference: fakeSexPref,
      biography: "I'm a fake user but I still like trains!",
      interests: fakeInterestArr,
      pictures: [
        await faker.image.imageUrl(),
        await faker.image.imageUrl(),
        await faker.image.imageUrl(),
        await faker.image.imageUrl()
      ],
      avatar: await faker.image.avatar(),
      ipinfoLoc: fakeIpinfoLoc,
      fameRating: 0,
      resetToken: "",
      verifyToken: "",
      verified: 1,
      email: await faker.internet.email(),
      password: "12345"
    }

    let exitOnDupUsername = 0;
    let exitOnDupEmail = 0;
    
    // Checking if already registered.
    await Promise.all([
      userModel.getDocByUsername(fakeUser.username),
      userModel.getDocByEmail(fakeUser.email)
    ])
    .then((values) => {
      if (values[0]) return (exitOnDupUsername = 1);
      else if (values[1]) return (exitOnDupEmail = 1);
    })
    .catch((error) => {
      console.log(error);
    });

    // Skipping if duplicate username or email.
    if (exitOnDupUsername)
      continue;
    else if (exitOnDupEmail)
      continue;

    // Registering user, also creates a geospatial index if one does not exist.
    userModel.addUserAsync(fakeUser)
    .then(async () => {
      let geoIndexCreated = await
        userModel.getIndexCreatedState('geoIndexCreated');
      if (geoIndexCreated == false) {
        await userModel.createGeoIndex("ipinfoLoc");
        await userModel.addIndexCreatedState('geoIndexCreated');
      }
    });
    // for-loop ends here.
  }

  res.send("Dummy accounts made!");
}

// ------------------------------------------------------------------------ //

module.exports.searchUsers = async (req, res, next) => {
  let missingValues = "You're missing required values.";
  let notANumber = "An entered value is not a number.";
  let lastSeendIdBroken = "The lastSeedId is broken.";
  let interestArrayBroken = "The tag/interest array is not an array.";
  let interestArrayEmpty = "The tag/interest array is empty.";
  let interestArrayTooFull = "The tag/interest array has more than 10 values.";
  let interestArrayValuesBroken = "The tag/interest array values are incorrect";
  let negativeNumbers = "Can't enter negative values.";
  let ageLower18 = "The entered age can't be lower than 18.";
  let locHighCantBeLower = "The higher location value can't be lower than the lower location value.";
  let fameHighCantBeLower = "The higher fame value can't be lower than the lower fame value.";
  let ageHighCantBeLower = "The higher age value can't be lower than the lower age value.";

  let searchObj = req.body;

  // Need to validate the search request before calling db.
  // If values undefined or null, use defaults.
  console.log(searchObj);

  // Default Search Options.
  // 
  // { userLong: 28.040176,
  //   userLat: -26.205275,
  //   locationHigh: 100000,
  //   locationLow: 1,
  //   fameHigh: 999999,
  //   fameLow: 0,
  //   ageHigh: 100,
  //   ageLow: 18,
  //   interestArr:
    //  [ 'Matcha',
    //    'Sports',
    //    'Art',
    //    'Gaming',
    //    'Traveling',
    //    'Music',
    //    'Cooking',
    //    'Movies',
    //    'Computers',
    //    'Reading' ],
  //   limit: 5,
  //   lastSeenId: null }

  if (
  searchObj.fameHigh == null || searchObj.fameHigh == undefined ||
  searchObj.fameLow == null || searchObj.fameLow == undefined ||
  searchObj.ageHigh == null || searchObj.ageHigh == undefined ||
  searchObj.ageLow == null || searchObj.ageLow == undefined ||
  searchObj.locationHigh == null || searchObj.locationHigh == undefined ||
  searchObj.locationLow == null || searchObj.locationLow == undefined)
    return res.json({success: false, msg: missingValues});

  // Setting default search values.
  if (searchObj.interestArr == null || searchObj.interestArr == undefined)
    searchObj.interestArr = [ 'Matcha', 'Sports', 'Art', 'Gaming', 'Traveling',
      'Music', 'Cooking', 'Movies', 'Computers', 'Reading' ];
  if (searchObj.userLong == null || searchObj.userLong == undefined)
    searchObj.userLong = 28.040176;
  if (searchObj.userLat == null || searchObj.userLat == undefined)
    searchObj.userLat = -26.205275;
  if (searchObj.limit == null || searchObj.limit == undefined)
    searchObj.limit = 5;
  if (searchObj.lastSeenId == undefined)
    searchObj.lastSeenId = null;
  if (searchObj.locationHigh == null || searchObj.locationHigh == undefined)
    searchObj.locationHigh = 100000;
  if (searchObj.locationLow == null || searchObj.locationLow == undefined)
    searchObj.locationLow = 1;
  if (searchObj.fameHigh == null || searchObj.fameHigh == undefined)
    searchObj.fameHigh = 999999;
  if (searchObj.fameLow == null || searchObj.fameLow == undefined)
    searchObj.fameLow = 0;
  if (searchObj.ageHigh == null || searchObj.ageHigh == undefined)
    searchObj.ageHigh = 100;
  if (searchObj.ageLow == null || searchObj.ageLow == undefined)
    searchObj.ageLow = 18;
  if (searchObj.locationLow == 0)
    searchObj.locationLow = 1;

  if (
  typeof searchObj.userLong != "number" ||
  typeof searchObj.userLat != "number" ||
  typeof searchObj.locationHigh != "number" ||
  typeof searchObj.locationLow != "number" ||
  typeof searchObj.fameHigh != "number" ||
  typeof searchObj.fameLow != "number" ||
  typeof searchObj.ageHigh != "number" ||
  typeof searchObj.ageLow != "number" ||
  typeof searchObj.limit != "number")
    return res.json({success: false, msg: notANumber});

  // If searchObj.lastSeenId is truthy, then it can't be null.
  if (searchObj.lastSeenId && typeof searchObj.lastSeenId != "string")
    return res.json({success: false, msg: lastSeendIdBroken});

  if (Array.isArray(searchObj.interestArr) == false)
    return res.json({success: false, msg: interestArrayBroken});

  let arrCount = searchObj.interestArr.length;
  if (arrCount == 0)
    return res.json({success: false, msg: interestArrayEmpty});
  if (arrCount > 10)
    return res.json({success: false, msg: interestArrayTooFull});
  
  // Checking array contents. Could even check for tag matches, but meh.
  for (let i = 0; i < arrCount; i++) {
    if (typeof searchObj.interestArr[i] != "string") {
      return res.json({success: false, msg: interestArrayValuesBroken});
    }
  }

  // Check for negative numbers.
  if (
  searchObj.locationHigh < 0 || searchObj.locationLow < 0 ||
  searchObj.fameHigh < 0 || searchObj.fameLow < 0 ||
  searchObj.ageHigh < 0 || searchObj.ageLow < 0)
    return res.json({success: false, msg: negativeNumbers});

  if (searchObj.ageHigh < 18 || searchObj.ageLow < 18)
    return res.json({success: false, msg: ageLower18});

  // Checking for weird value inversion.
  if (searchObj.locationHigh < searchObj.locationLow)
    return res.json({success: false, msg: locHighCantBeLower});
  if (searchObj.fameHigh < searchObj.fameLow)
    return res.json({success: false, msg: fameHighCantBeLower});
  if (searchObj.ageHigh < searchObj.ageLow)
    return res.json({success: false, msg: ageHighCantBeLower});

  let docArr = await userModel.searchUsers(searchObj);

  res.json({success: true, docs: docArr});
}

// ------------------------------------------------------------------------ //

module.exports.returnRequestedProfile = async (req, res, next) => {
  if (req.query == undefined || req.query == null ||
    req.query.username == undefined || req.query.username == null)
    return res.json({
      success: false, msg: "Could not send requested profile data," +
        " missing get parameters."
    });

  let requestedProfileUsername = req.query.username;
  let user = await userModel.getDocByUsername(requestedProfileUsername);
  if (user)
    res.json({success: true, user});
  else
    res.json({success: false, msg: "User not found."})
}

// ------------------------------------------------------------------------ //

/* Need to build query here.

db.users.find(
  {
    ipinfoLoc: {
      $near: {
        $geometry: {
          type: "Point",
          coordinates: [28.0361622, -26.205649599999997]
        },
        $minDistance: 1,
        $maxDistance: 5000
      }
    }
  }
);

db.users.find(
  {
    firstName: "Evert";
  }
);

db.users.find(
  {
    $and: [
      {},
      {}
    ]
  }
);

---------------- Test Query ----------------
Works!

db.users.find(
  {
    $and: [
      {
        ipinfoLoc: {
          $near: {
            $geometry: {
              type: "Point",
              coordinates: [28.0361622, -26.205649599999997]
            },
            $minDistance: 1,
            $maxDistance: 5000
          }
        }
      },
      {
        firstName: "Evert"
      }
    ]
  }
)

---------------- Test Query 2 ----------------
Returns emtpy?

db.users.find(
  {
    $and: [
      {
        ipinfoLoc: {
          $near: {
            $geometry: {
              type: "Point",
              coordinates: [28.0361622, -26.205649599999997]
            },
            $minDistance: 1,
            $maxDistance: 5000
          }
        }
      },
      {
        $and: [{ fameRating: { $gte: 0 } }, { fameRating: { $lte: 999999 } }]
      },
      {
        $and: [{ age: { $gte: 18 } }, { age: { $lte: 999999 } }]
      },
      {
        interests: { $in: [ "Computers", "Cooking", "Movies" ] }
      }
    ]
  }
)

---------------- Test Query 3 ----------------
This works, distance was just too short.

db.users.find(
  {
    $and: [
      {
        ipinfoLoc: {
          $near: {
            $geometry: {
              type: "Point",
              coordinates: [28.0361622, -26.205649599999997]
            },
            $minDistance: 1,
            $maxDistance: 100000
          }
        }
      },
      {
        $and: [{ fameRating: { $gte: 0 } }, { fameRating: { $lte: 999999 } }]
      },
      {
        $and: [{ age: { $gte: 18 } }, { age: { $lte: 999999 } }]
      },
      {
        interests: { $in: [ "Computers", "Cooking", "Movies", "Matcha", "Outdoors", "Gaming", "Art", "Traveling", "Reading", "Sports" ] }
      }
    ]
  }
)

*/