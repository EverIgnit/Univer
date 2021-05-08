//import { Model, INTEGER, STRING, BOOLEAN } from 'sequelize';
import sequelize from '../sequelize.js';

import pkg from 'sequelize';
const { Model, INTEGER, STRING, BOOLEAN } = pkg;

class Carriage extends Model { }

Carriage.init(
    {
        id: {
            type: INTEGER,
            primaryKey: true,
            autoIncrement: true
        },
        number: { type: INTEGER, field: 'number' },
        type: { type: STRING, field: 'type' },
        captain: { type: STRING, field: 'captain' },
        smoking: { type: BOOLEAN, field: 'smoking' },
    },
    {
        sequelize: sequelize,
        modelName: 'carriages',
    },
);

console.log('Carriage =', Carriage === sequelize.models.carriages);

export default Carriage;
