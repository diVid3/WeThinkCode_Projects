// Basically all code that does not directly interact with the database or views
// goes into controllers. An example, backend validation before committing to
// database.

const userModel = require('../models/user');

module.exports.registerUser = (req) => {
  let promise = new Promise((resolve, reject) => {

    if (req.body.name == "" ||
      req.body.email == "" ||
      req.body.username == "" ||
      req.body.password == "") {
        reject('Need all register fields.');
    }

    let newUser = {
      name: req.body.name,
      email: req.body.email,
      username: req.body.username,
      password: req.body.password
    };

    userModel.addUser(newUser, (err, msg) => {
      if (err === 1) {
        let obj = {success: false, msg: msg}
        resolve(obj);
      }
      else {
        let obj = {success: true, msg: msg}
        resolve(obj);
      }
    });
  });

  return promise;
}
