import sequelize from './sequelize.js';
import User from './models/users.js';
import Tickets from './models/tickets.js';
import Carriages from './models/carriages.js';

export default async function connect() {
    try {
        await sequelize;
        console.log('Sequelize connected successfully.');
        await sequelize.sync();

        Carriages.hasMany(Tickets, { foreignKey: 'carriage_id' });
        User.hasMany(Tickets, { foreignKey: 'user_id' });

        return 0;
    } catch (error) {
        console.log('Sequelize connect error:', error);
        return 1;
    }
}




