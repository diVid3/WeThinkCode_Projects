const mongocon = require('./config/mongocon');

// All modules that are required here need the DB connection to be established
// first in order to have access to the _db variable obtained from the getDB
// function.
mongocon.connectToServer((connectedToDb) => {
    if (!connectedToDb) return false;

    const express = require('express');
    const path = require('path');
    const bodyParser = require('body-parser');
    const cors = require('cors');
    const passport = require('passport');

    const app = express();
    
    const port = 3000;

    // Enables CORS.
    app.use(cors());

    // body-parser extracts the entire body portion of an incoming request stream
    // and exposes it on req.body. The .json method returns middleware that only
    // parses json and only looks at requests where the Content-Type header matches
    // the type option.
    app.use(bodyParser.json());

    // Statically serves everything within __dirname/public folder from current 
    // directory. When no directory to serve from is specified, current directory
    // is used, as in this case.
    app.use(express.static(path.join(__dirname, 'public')));

    // Initializes the passport middleware.
    app.use(passport.initialize());

    // This will enable persistent login sessions. passport.session() acts as a 
    // middleware to alter the req object and change the 'user' value that is
    // currently the session id (from the client cookie) into the true deserialized
    // user object. To allow this to work correctly you must include
    // passport.serializeUser and passport.deserializeUser functions in your
    // custom code.
    app.use(passport.session());

    app.get('/', (req, res) => {
        res.send('Invalid Endpoint.');
    });

    // Bringing in and executing router calls in routes/user.
    const user = require('./routes/user');

    // This will let routes entered as localhost:3000/user/* be handled by the
    // user router. The user constant here is an express router instance.
    app.use('/user', user);

    // Statically serving the images folder.
    app.use(express.static(path.join(__dirname, 'user_files')));

    // Self-invoking with a passed variable. This is an exported method from
    // config/passport.js.
    require('./config/passport')(passport);

    // After the angular app has been built and exported to the public folder, this
    // line will ensure that all route requests that differ from the route requests
    // on the backend (here) goes to the front end app, which will be hosted on the
    // same port after the angular app has been built and exported to the public
    // folder, the front end entry file is as of now public/index.html.
    // app.get('*', (req, res) => { 
    //     res.sendFile(path.join(__dirname, 'public/index.html'));
    // });

    app.listen(port, () => {
        console.log(`Started server on port ${port}`);
    });
});
