import TicketRepository from '../repositories/ticketRepository.js';

const ticketRepository = new TicketRepository();

class TicketController {

    async getPassagers(req, res) {
        try {
            return res
                .status(200)
                .json(await ticketRepository.getPassagers(req.body, req.user.name));
        } catch (error) {
            console.log(error);
            return res.status(404).json(error);
        }
    }

    async buyTicket(req, res) {
        try {
            return res
                .status(200)
                .json(await ticketRepository.buyTicket(req.user, req.body));
        } catch (error) {
            console.log(error);
            return res.status(404).json(error);
        }
    }

    async ticketsHistory(req, res) {
        try {
            return res
                .status(200)
                .json(await ticketRepository.ticketsHistory(req.user));
        } catch (error) {
            console.log(error);
            return res.status(404).json(error);
        }
    }
    async returnTicket(req, res) {
        try {
            return res
                .status(200)
                .json(await ticketRepository.returnTicket(req.body, req.user));
        } catch (error) {
            console.log(error);
            return res.status(404).json(error);
        }
    }

}

export default TicketController;
