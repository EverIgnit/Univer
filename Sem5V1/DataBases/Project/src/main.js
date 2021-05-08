import express from 'express';
import server from './server.js';
import router from './routes/index.js';
import connect from './database/connect.js';
import passport from './middleware/passport-middleware.js';
import session from 'express-session';
//const session = require('express-session');

const app = express();
export default app;
//module.exports = app;
async function start() {
    try {
        await connect();
        server();
        app.use(session({ secret: 'cats', resave: true, saveUninitialized: false }));
        app.use(passport.initialize());
        app.use(passport.session());
        app.use(router);
        console.log('app has been started...');
        return 0;
    } catch (error) {
        console.log(error);
        return 1;
    }
}

start();
