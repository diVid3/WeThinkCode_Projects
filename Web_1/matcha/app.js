const express = require('express');
const path = require('path');
const bodyParser = require('body-parser');
const cors = require('cors');
const passport = require('passport');
// const mongoose = require('mongoose');
// const mongoClient = require('mongodb').MongoClient;
// const config = require('./config/database');

// Connects to database. When not using mongoose, you can store your db 
// connection in the app.locals variable to access it throughout the app.

// mongoose.connect(config.database, {useNewUrlParser: true});
// mongoose.connection.on('connected', () => {
//     console.log(`Connected to database ${config.database}`);
// });
// mongoose.connection.on('error', (err) => {
//     console.log(`Database error: ${err}`);
// });

const app = express();

const mongocon = require('./config/mongocon');

// mongoClient.connect(config.database, { useNewUrlParser: true }, (err, client) => {
//     if (err) console.log(`Database error: ${err}`);
//     app.locals.db = client.db('matcha');
//     console.log('app.locals.db is: ' + app.locals.db);
//     app.locals.db.collection('users').findOne({"username": "evert"}, (err, user) => {
//         console.log(user);
//     });
//     console.log(`Connected to database ${config.database}`);
// });

// Bringing in and executing router calls in routes/users.
// const users = require('./routes/users');

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

// Self-invoking with a passed variable. This is an exported method from
// config/passport.js.
// require('./config/passport')(passport);

// This will let routes entered as localhost:3000/users/* be handled by the
// users router. The users constant here is an express router instance.
// app.use('/users', users);

app.get('/', (req, res) => {
    res.send('Invalid Endpoint.');
});

// After the angular app has been built and exported to the public folder, this
// line will ensure that all route requests that differ from the route requests
// on the backend (here) goes to the front end app, which will be hosted on the
// same port after the angular app has been built and exported to the public
// folder, the front end entry file is as of now public/index.html.

// app.get('*', (req, res) => { 
//     res.sendFile(path.join(__dirname, 'public/index.html'));
// });

// All modules that are required here need the DB connection to be established
// first in order to have access to the _db variable obtained from the getDB
// function.
mongocon.connectToServer((connectedToDb) => {
    if (!connectedToDb) return false;

    // At this point, the DB connection has been established.

    // Bringing in and executing router calls in routes/users.
    const users = require('./routes/users');

    // This will let routes entered as localhost:3000/users/* be handled by the
    // users router. The users constant here is an express router instance.
    app.use('/users', users);

    // Self-invoking with a passed variable. This is an exported method from
    // config/passport.js.
    require('./config/passport')(passport);

    app.listen(port, () => {
        console.log(`Started server on port ${port}`);
    });
});

// app.listen(port, () => {
//     console.log(`Started server on port ${port}`);
// });
