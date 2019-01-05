// The passport strategy to use.
const JwtStrategy = require('passport-jwt').Strategy;

// This object will be used to extract JWT from header.
const ExtractJwt = require('passport-jwt').ExtractJwt;

const User = require('../models/user');
const config = require('../config/database');

// The user variable is passed in via getUserById, the done function
// is provided by JwtStrategy constructor. This configures how
// authentication is to be done on the server.
module.exports = function (passport) {
    let opts = {};
    opts.jwtFromRequest = ExtractJwt.fromAuthHeaderWithScheme("jwt");
    opts.secretOrKey = config.secret;

    // jwt_payload is what the client produces. It's required
    // to unlock protected routes.
    passport.use(new JwtStrategy(opts, (jwt_payload, done) => {

        // user here represents a mongoose query object. However
        // returning done can be done by any method. For instance,
        // as long as the payload ID results in a hit in the DB,
        // authentication is done. There is a MAJOR problem here,
        // this method requires res.app object, only available on
        // routes.
        console.log(jwt_payload);
        User.getUserById(jwt_payload._id, (err, user) => {
            console.log(jwt_payload._id);
            console.log(`\n\n\n`);
            console.log(`user is: ${user}`);
            if (err) return done(err, false);
            if (user) return done(null, user); // user is a document.
            else return done(null, false);
        });
    }));
}
