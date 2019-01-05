const mongoClient = require('mongodb').MongoClient;
const config = require('../config/database');

var _db;

// mongoClient.connect(config.database, { useNewUrlParser: true }, (err, client) => {
//     if (err) console.log(`Database error: ${err}`);
//     app.locals.db = client.db('matcha');
//     console.log('app.locals.db is: ' + app.locals.db);
//     app.locals.db.collection('users').findOne({"username": "evert"}, (err, user) => {
//         console.log(user);
//     });
//     console.log(`Connected to database ${config.database}`);
// });

// module.exports = {
//     connectToServer: (callback) => {
//         mongoClient.connect(config.database, { useNewUrlParser: true }, (err, client) => {
//             if (err) { callback(err); }
//             else {  }
//         });
//     },
//     getDb: () => { return _db }
// }

module.exports.connectToServer = (callback) => {
    mongoClient.connect(config.database, { useNewUrlParser: true }, (err, client) => {
        if (err) { console.log(`Database error: ${err}`); }
        else { _db = client.db('matcha'); }
        console.log(`Connected to database ${config.database}`);
        callback(true);
    });
}

module.exports.getDb = () => { return _db; }
