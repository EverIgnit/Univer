//import { MongoClient } from "mongodb";

import pkg from 'mongodb';
const { MongoClient } = pkg;

export default async function (name, op_type, table_name, data) {
    let postgres = {
        date: new Date(),
        user_name: name || 'unauthorized',
        op_type: op_type,  // тип операции
        table_name: table_name,
        save_data: data || null    // сохраняемые данные (хранить в виде объекта)
    }
    const mongoClient = new MongoClient("mongodb://localhost:27017/", { useNewUrlParser: true, useUnifiedTopology: true });
    mongoClient.connect(async function (err, client) {
        if (err) {
            console.log(err);
            return 1;
        }
        const db = client.db("finance");
        const collection = db.collection("postgres");
        collection.insertOne(postgres, async function (err, result) {
            await client.close();
        });
    });
}
