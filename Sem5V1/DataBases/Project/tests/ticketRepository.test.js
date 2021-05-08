import TicketRepository from '../src/repositories/ticketRepository';

const ticketRepository = new TicketRepository();

describe('connect()', () => {

    test('ticketRepository.buyTicket(null, null)', async () => {
        expect(await ticketRepository.buyTicket(null, null)).toBe('error, no data');
    });

    test('ticketRepository.getPassagers(null, null)', async () => {
        expect(await ticketRepository.getPassagers(null, null)).toBe('error, no data');
    });

    test('ticketRepository.getPassagers(null, null)', async () => {
        expect(await ticketRepository.returnTicket(null, null)).toBe("error, no data");
    });

});
