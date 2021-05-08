//import { Model, INTEGER, STRING } from 'sequelize';
import sequelize from '../sequelize.js';
import pkg from 'sequelize';
const { Model, INTEGER, STRING } = pkg;

class User extends Model { }

User.init(
    {
        id: {
            type: INTEGER,
            primaryKey: true,
            autoIncrement: true
        },
        login: { type: STRING, field: 'login' },
        password: { type: STRING, field: 'password' },
        role: { type: STRING, field: 'role' },
    },
    {
        sequelize: sequelize,
        modelName: 'users',
    },
);

console.log('User =', User === sequelize.models.users);

export default User;
