export default async (req, res, next) => {
    try {
        const roles = await req.user.role;

        if (!roles)
            return res
                .status(404)
                .json(
                    'role not found',
                );

        if (roles === 'cashier' || roles === 'admin')
            return next();

        return res.status(401)
            .json('authAdminError, you are not cashier');
    } catch (error) {
        return res.status(404).json(error);
    }
};
