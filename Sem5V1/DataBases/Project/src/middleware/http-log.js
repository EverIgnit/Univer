//import { MongoClient } from "mongodb";

import pkg from 'mongodb';
const { MongoClient } = pkg;

export default async function (req, res, next) {
    let http_log = {
        ip: req.headers['x-forwarded-for'] ||
            req.connection.remoteAddress ||
            req.socket.remoteAddress ||
            (req.connection.socket ? req.connection.socket.remoteAddress : null),
        path: req.path,
        headers: req.headers,
        day: new Date(),
    }
    const mongoClient = new MongoClient("mongodb://localhost:27017/",
        { useNewUrlParser: true, useUnifiedTopology: true });
    mongoClient.connect(async function (err, client) {
        if (err) {
            console.log(err);
            return err;
        }
        const db = client.db("finance");
        const collection = db.collection("http");
        collection.insertOne(http_log, async function (err, result) {
            await client.close();
        });
    });
    next();
};

