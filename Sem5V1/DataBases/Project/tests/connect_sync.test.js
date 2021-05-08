import connect from '../src/database/connect';

describe('connect()', () => {

    test('connect()', async () => {
        expect(await connect()).toBe(0);
    });

});
