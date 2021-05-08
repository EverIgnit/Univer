import UserRepository from '../src/repositories/userRepository';
const userRepository = new UserRepository();

describe('userRepository', () => {
    test('userRepository.deleteAccount(null)', async () => {
        expect(await userRepository.deleteAccount(null)).toBe('Nothing to delete');
    });

    test('userRepository.updateUser(null, { login: admin })', async () => {
        expect(await userRepository.updateUser(null, { login: "admin" })).toBe('error, no data');
    });


    test('userRepository.updateUser(null, { login: admin })', async () => {
        expect(await userRepository.getUser(null, null)).toBe('error, no options');
    });

});
