// Basically all code that does not directly interact with the database or views
// goes into controllers. An example, backend validation before committing to
// database, this is assuming that the validation logic does not include busi-
// ness logic.

const userModel = require('../models/user');
const jwt = require('jsonwebtoken');
const config = require('../config/database');
const path = require('path');
const fs = require('fs');

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
  if (req.body.email.length > 32)
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

module.exports.registerUser = async (req, res, next) => {
  let userExists = 'Username already exists. Please try another one.';
  let emailExists = 'Email already exists. Please try another one.';
  let userRegistered = 'You\'re registered! You may now login.';

  // Input validation.
  let signalObj = { passedInputValidation: false }; // Passed by reference.
  registerUserInfoValid(req, res, signalObj);
  if (signalObj.passedInputValidation == false)
    return;
  
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
    email: req.body.email,
    password: req.body.password
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
      console.log('GeoIndex created!');
    }
    res.json({ success: true, msg: userRegistered })
  });
}

// ------------------------------------------------------------------------ //

module.exports.authenticateUser = async (req, res, next) => {
  if (req.body.username == '' || req.body.password == '' ||
  req.body.username == null || req.body.password == null)
    return res.json({ success: false, msg: 'Please fill in all fields.' });

  const username = req.body.username;
  const password = req.body.password;

  let user = await userModel.getDocByUsername(escapeSpecChars(username));
  if (!user) return res.json({success: false, msg: 'User not found.'});
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
      ipinofLoc: user.ipinfoLoc,
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
  if (updatedUser.email.length > 32)
    return res.json({ success: false, msg: emailTooLong });
  let re = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  // console.log(re.test(updatedUser.email.toLowerCase()));
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

  // console.log('===== req.files =====');
  // console.log(req.files);
  // console.log('=====================');

  // console.log('=============================================================');
  // console.log(updatedUser);
  // console.log('=============================================================');

  let updatedUser = JSON.parse(req.body.updatedUserProfile);
  console.log(updatedUser);

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

  // console.log('************************************************************');
  // console.log(updatedUser);
  // console.log('************************************************************');
  res.json({success: true, msg: 'Profile updated!'});
}

// ------------------------------------------------------------------------ //

module.exports.resetPasswordUser = (req, res, next) => {
  // Need to validate enteredEmail.
  console.log(req);
  res.json({success: true, msg: 'Reset email sent, check your mail!'})
}

// ------------------------------------------------------------------------ //
