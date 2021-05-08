import User from '../database/models/users.js';
import log from '../middleware/postgres-log.js';

class UserRepository {

    async getUser(options, name) {
        if (options) {
            log(name, "SELECT", "users", null);
            return await User.findOne({ where: options });
        }
        return 'error, no options';
    }

    async updateUser(user, body) {
        if (user && body) {
            log(user.name, "UPDATE", "users", null);
            const old_user = await User.findOne({ where: { id: user.id } });
            const check_new_name = await User.findOne({ where: { login: body.login } });
            if (check_new_name)
                return "this login alredy in use, please change it";
            if (body.login)
                old_user.update({
                    login: body.login
                })
            if (body.password)
                old_user.update({
                    password: body.password
                })
            return "User updated";
        }
        return 'error, no data';
    }

    async deleteAccount(user) {
        if (!user)
            return 'Nothing to delete'
        log(user.name, "DELETE", "users", null);
        await user.destroy();
        return 'User has been deleted successfully';
    }

}

export default UserRepository;
