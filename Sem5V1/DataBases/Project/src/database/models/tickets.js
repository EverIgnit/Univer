//import { Model, INTEGER, BOOLEAN } from 'sequelize';
import sequelize from '../sequelize.js';


import pkg from 'sequelize';
const { Model, INTEGER, BOOLEAN } = pkg;


class Ticket extends Model { }

Ticket.init(
    {
        id: {
            type: INTEGER,
            primaryKey: true,
            autoIncrement: true
        },
        half_free: { type: BOOLEAN, field: 'half_free' },
        package_freight: { type: BOOLEAN, field: 'package_freight' },
        carriage_id: { type: INTEGER, field: "carriage_id" },
        user_id: { type: INTEGER, field: "user_id" }
    },
    {
        sequelize: sequelize,
        modelName: 'tickets',
    },
);

console.log('Ticket =', Ticket === sequelize.models.tickets);

export default Ticket;
