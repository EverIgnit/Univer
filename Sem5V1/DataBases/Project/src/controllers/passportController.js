import passport from 'passport';
import User from '../database/models/users.js';
import log from '../middleware/postgres-log.js';

class PassportController {

    async login(req, res, next) {
        await passport.authenticate('local', async function (err, user, info) {
            if (err) {
                console.log(err);
                return next(err);
            }
            if (!user)
                return res
                    .status(404)
                    .json('Incorrect username or password');
            req.logIn(user, (err) => {
                if (err) return res.status(404).json(err);
                return res.status(200).json('You logged');
            });
        })(req, res, next);

    }

    async logout(req, res) {
        try {
            await req.logout();
            return res.status(200).json('You Logout');
        } catch (error) {
            return res.status(404).json(error);
        }
    }

    async register(req, res) {
        try {
            const old_user = await User.findOne({ where: { login: req.body.login } });
            if (old_user)
                return res.status(409).json("This username is alredy in use, please, use anouther");
            log(null, "INSERT", "users", req.body);
            const user = await User.create({
                login: req.body.login,
                password: req.body.password,
                role: "user"
            });
            await req.logIn(user, err => {
                return err
                    ? res.status(404).json(err)
                    : res
                        .status(200)
                        .json('You create new account and logged in');
            });
        } catch (error) {
            return res.status(404).json(error);
        }
    }
}

export default PassportController;
