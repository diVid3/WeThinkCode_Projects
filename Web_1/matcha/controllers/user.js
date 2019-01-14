// Basically all code that does not directly interact with the database or views
// goes into controllers. An example, backend validation before committing to
// database.

const userModel = require('../models/user');
const jwt = require('jsonwebtoken');
const config = require('../config/database');

// ------------------------------------------------------------------------ //

function hasAllRegisterProperties(req) {
  if (
  req.body.firstName == null || req.body.lastName == null ||
  req.body.username == null || req.body.age == null ||
  req.body.gender == null || req.body.ipinfoLoc == null ||
  req.body.email == null || req.body.password == null ||
  req.body.firstName == '' || req.body.lastName == '' ||
  req.body.username == '' || req.body.age == '' ||
  req.body.gender == '' || req.body.ipinfoLoc == '' ||
  req.body.email == '' || req.body.password == '')
    return false;
  return true;
}

// db.derps.insert(
//   {
//     loc: { type: "Point", coordinates: [-73.88, 40.78] },
//     name: "La Guardia Airport",
//     category: "Airport"
//   }
// );

// Converts the location string from ipinfo.io to a GeoJSON object.
function ipinfoLocToGeoJSON(ipinfoLocString) {
  // if (ipinfoLocString == null || ipinfoLocString == '')
  //   throw new Error('ipinfoLocString was not defined.');
  // if (typeof ipinfoLocString != "string")
  //   throw new Error('ipinfoLocString is not a string.');
  // if (ipinfoLocString.includes(',') == false)
  //   throw new Error('ipinfoLocString isn\'t formatted correctly.');
  let numArr = ipinfoLocString.split(',');
  console.log(numArr);
  // if (numArr.length != 2)
  //   throw new Error('ipinfoLocString doesn\'t split correctly.');
  let longitude = parseFloat(numArr[1]);
  let latitude = parseFloat(numArr[0]);
  return ({ type: "Point", coordinates: [longitude, latitude] });
}

function escapeSpecChars(string) {
  return string
  .replace(/&/g, "&amp;")
  .replace(/</g, "&lt;")
  .replace(/>/g, "&gt;")
  .replace(/"/g, "&quot;")
  .replace(/'/g, "&#039;");
}

function registerUserInfoValid(req) {
  // Remember to check if all input is received if debugging.
  if (hasAllRegisterProperties(req) == false)
    return false;

}

module.exports.registerUser = async (req, res, next) => {
  if (registerUserInfoValid(req) == false)
    return res.json({ success: false, msg: invalidMsg });
  
  let newUser = {
    firstName: escapeSpecChars(req.body.firstName),     // Convert, check length.
    lastName: escapeSpecChars(req.body.lastName),       // Convert, check length.
    username: escapeSpecChars(req.body.username),       // Convert, check length.
    age: req.body.age,                                  // Check negative num, age fits,
    gender: req.body.gender,
    sexualPreference: 'bisexual', // Non req. Don't validate on register.
    biography: '',                // Non req. Don't validate on register.
    interests: [],                // Non req. Don't validate on register.
    pictures: [],                 // Non req. Don't validate on register.
    avatar: [],                   // Non req. Don't validate on register.
    ipinfoLoc: ipinfoLocToGeoJSON(req.body.ipinfoLoc),  // Check using above,
    email: req.body.email,                              // Check if valid email,
    password: req.body.password                         // Check length, mix case,
  }

  let userExists = 'Username already exists. Please try another one.';
  let emailExists = 'Email already exists. Please try another one.';
  let invalidMsg = 'Registry failed, bad user input.';
  let userRegistered = 'You\'re registered! You may now login.';
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

  // Registering user.
  // userModel.addUserAsync(newUser)
  // .then(res.json({ success: true, msg: userRegistered }));
  userModel.addUserAsync(newUser)
  .then(userModel.createGeoIndex("ipinfoLoc"))
  .then(res.json({ success: true, msg: userRegistered }));
}

// ------------------------------------------------------------------------ //

module.exports.authenticateUser = async (req, res, next) => {
  if (req.body.username == '' || req.body.password == '' ||
  req.body.username == null || req.body.password == null)
    return res.json({ success: false, msg: 'Please fill in all fields.' });

  const username = req.body.username;
  const password = req.body.password;

  let user = await userModel.getDocByUsername(username);
  if (!user) return res.json({success: false, msg: 'User not found.'});
  let passwordMatch = await userModel.comparePasswordAsync(password,
    user.password);
  if (passwordMatch) {
    let token = jwt.sign(user, config.secret, {expiresIn: 604800});
    let authUser = { // Can add more profile info here.
      // id: user._id,
      // name: user.name,
      // username: user.username,
      // email: user.email
      id: user._id,
      firstName: user.firstName,
      lastName: user.lastName,
      username: user.username,
      age: user.age,
      gender: user.gender,
      sexualPreference: user.sexualPreference,
      biography: user.biography,
      interests: user.interests,
      pictures: user.pictures,
      avatar: user.avatar,
      ipinofLoc: user.ipinfoLoc,
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



// ------------------------------------------------------------------------ //
