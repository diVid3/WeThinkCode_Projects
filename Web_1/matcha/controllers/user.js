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
  req.body.gender == null ||
  req.body.email == null || req.body.password == null ||
  req.body.firstName == '' || req.body.lastName == '' ||
  req.body.username == '' || req.body.age == '' ||
  req.body.gender == '' ||
  req.body.email == '' || req.body.password == '')
    return true;
  return false;
}

module.exports.registerUser = async (req, res, next) => {
  let newUser = {
    firstName: req.body.firstName,
    lastName: req.body.lastName,
    username: req.body.username,
    age: req.body.age,
    gender: req.body.gender,
    email: req.body.email,
    password: req.body.password
  }
  let userExists = 'Username already exists. Please try another one.';
  let emailExists = 'Email already exists. Please try another one.';
  let fillMsg = 'Please fill in all fields.';
  let userRegistered = 'You\'re registered! You may now login.';
  let exitOnDupUsername = 0;
  let exitOnDupEmail = 0;

  // Validation checks.
  if (hasAllRegisterProperties(req))
    return res.json({ success: false, msg: fillMsg });

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
  userModel.addUserAsync(newUser)
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
      id: user._id,
      name: user.name,
      username: user.username,
      email: user.email
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
