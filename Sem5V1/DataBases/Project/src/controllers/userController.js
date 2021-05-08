import UserRepository from '../repositories/UserRepository.js';

const userRepository = new UserRepository();

class UserController {

    async getUser(req, res) {
        try {
            return res
                .status(200)
                .json(await userRepository.getUser(req.body, req.user.name));
        } catch (error) {
            console.log(error);
            return res.status(404).json(error);
        }
    }

    async updateUser(req, res) {
        try {
            return res
                .status(200)
                .json(await userRepository.updateUser(req.user, req.body));
        } catch (error) {
            console.log(error);
            return res.status(404).json(error);
        }
    }

    async deleteAccount(req, res) {
        try {
            return res
                .status(200)
                .json(await userRepository.deleteAccount(req.user));
        } catch (error) {
            console.log(error);
            return res.status(404).json(error);
        }
    }


}

export default UserController;
