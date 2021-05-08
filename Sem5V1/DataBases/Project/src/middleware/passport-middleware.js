import User from '../database/models/users.js';

import passport from 'passport';
//const LocalStrategy = require('passport-local').Strategy;

import LocalStrategy from 'passport-local';


passport.use(
    new LocalStrategy(async function (username, password, done) {
        try {
            const user = await User.findOne({
                where: { login: username },
            });
            if (!user) return done(null, false);

            if (user.password === password) return done(null, user);
            return done(null, false);
        } catch (error) {
            console.log(error);
            return error;
        }
    }),
);

passport.serializeUser(async (user, done) => {
    done(null, user);
});

passport.deserializeUser(async (user, done) => {
    const finduser = await User.findOne({
        where: { id: user.id }
    });
    done(null, finduser);
});

export default passport;
