const mongoClient = require('mongodb').MongoClient;
const config = require('../config/database');

var _db;

module.exports.connectToServer = (callback) => {
    mongoClient.connect(config.database, { useNewUrlParser: true }, (err, client) => {
        if (err) { console.log(`Database error: ${err}`); }
        else {
            _db = client.db('matcha');
            console.log(`Connected to database ${config.database}`);
            callback(true);
        }
    });
}

module.exports.getDb = () => { return _db; }
