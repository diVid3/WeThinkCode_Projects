// Basically all code that does not directly interact with the database or views
// goes into controllers. An example, backend validation before committing to
// database.

const userModel = require('../models/user');

function needMoreRegDetails(req) {
  if (req.body.name == '' ||
  req.body.email == '' ||
  req.body.username == '' ||
  req.body.password == '') {
    let detailedString = 'Not all req values were received ' +
    'in order to register user. Empty req string.';
    let frontRes = {
      success: false,
      msg: 'Oops! Something went wrong. Please try again.'
    }
    return({detailedString, frontRes});
  }

  if (req.body.name == null ||
  req.body.email == null ||
  req.body.username == null ||
  req.body.password == null) {
    let detailedString = 'Not all req values were received ' +
    'in order to register user. Missing req property.';
    let frontRes = {
      success: false,
      msg: 'Oops! Something went wrong. Please try again.'
    }
    return({detailedString, frontRes});
  }
  return (false);
}

module.exports.registerUser = (req) => {
  let promise = new Promise((resolve, reject) => {

    let reqDetailCheck = needMoreRegDetails(req);
    if (reqDetailCheck) { reject(reqDetailCheck); }

    let newUser = {
      name: req.body.name,
      email: req.body.email,
      username: req.body.username,
      password: req.body.password
    };

    // Insert validation here, failure to validate would be resolved.

    // double add bug?

    userModel.addUser(newUser, (err, msg) => {
      if (err === 1) { resolve({success: false, msg: msg}); }
      else { resolve({success: true, msg: msg}); }
    });
  });

  return promise;
}


