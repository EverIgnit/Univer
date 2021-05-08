import { Router } from 'express';
//import { json } from 'body-parser';
import pkg from 'body-parser';
const { json } = pkg;

import cookie_parser from 'cookie-parser';
import isAuthenticated from '../middleware/isAuthenticated.js';
import isAdmin from '../middleware/isAdmin.js';
import isCashier from '../middleware/isCashier.js';

import UserController from '../controllers/UserController.js';
import TicketController from '../controllers/TicketController.js';
import PassportController from '../controllers/PassportController.js';

import log from '../middleware/http-log.js';

const router = Router();

router.use(json());
router.use(cookie_parser());

const userController = new UserController();
const ticketController = new TicketController();
const passportController = new PassportController();

async function router_setup() {
    try {

        router.use(log)

        // User-methods

        router.get('/', (req, res) => res.status(201).json('main page'));
        router.get('/getUser', isAdmin, userController.getUser);
        router.put('/updateUser', isAuthenticated, userController.updateUser);
        router.delete('/deleteAccount', isAuthenticated, userController.deleteAccount);

        // Ticket-methods

        router.get('/getPassagers', isCashier, ticketController.getPassagers);
        router.post('/buyTicket', isAuthenticated, ticketController.buyTicket);
        router.get('/ticketsHistory', isAuthenticated, ticketController.ticketsHistory);
        router.delete('/returnTicket', isAuthenticated, ticketController.returnTicket);

        // Passport-methods

        router.post('/login', passportController.login);
        router.post('/register', passportController.register);
        router.get('/logout', isAuthenticated, passportController.logout);
        return 0;
    } catch (error) {
        console.log(error);
        return 1;
    }
}
router_setup();
export default router;
