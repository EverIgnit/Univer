import Ticket from '../database/models/tickets.js';
import log from '../middleware/postgres-log.js';

class TicketRepository {

    async getPassagers(options, name) {
        if (options) {
            log(name, "SELECT", "tickets", null);
            return await Ticket.findAll({ where: options });
        }
        return 'error, no data';
    }

    async buyTicket(user, body) {
        if (user && body) {
            log(user.name, "INSERT", "tickes", null);
            return await Ticket.create({
                user_id: user.id,
                half_free: false,
                package_freight: body.package_freight,
                carriage_id: body.carriage_id
            });
        }
        return 'error, no data';
    }

    async ticketsHistory(user) {
        log(user.name, "SELECT", "tickes", null);
        return await Ticket.findAll({ where: { user_id: user.id } })
    }

    async returnTicket(body, user) {
        if (body && user) {
            const ticket = await Ticket.findOne({ where: { id: body.id, user_id: user.id } });
            if (ticket) {
                log(user.name, "DELETE", "tickets", null);
                await ticket.destroy();
                return 'ticket has been returned successfully';
            }
            return 'This is not yours ticket'
        }
        return "error, no data";
    }
}

export default TicketRepository;
