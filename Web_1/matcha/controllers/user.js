// Basically all code that does not directly interact with the database or views
// goes into controllers. An example, backend validation before committing to
// database.

const userModel = require('../models/user');

function hasAllRegisterProperties(req) {
  if (req.body.name == null || req.body.email == null ||
  req.body.username == null || req.body.password == null ||
  req.body.name == '' || req.body.email == '' ||
  req.body.username == '' || req.body.password == '')
    return true;
  return false;
}

module.exports.registerUser = async (req, res, next) => {
  let newUser = {
    name: req.body.name,
    email: req.body.email,
    username: req.body.username,
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
    if (values[0]) { exitOnDupUsername = 1; }
    else if (values[1]) { exitOnDupEmail = 1; }
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
