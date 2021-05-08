//const Sequelize = require('sequelize');

import Sequelize from 'sequelize';

export default new Sequelize(
    'finance',
    'postgres',
    'postgres2020',
    {
        dialect: 'postgres',
        host: 'localhost',
        dialectOptions: {
            connectTimeout: 1500,
        },
        logging: false,
        define: {
            timestamps: false,
        }
    }
);
