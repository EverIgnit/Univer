for (var j = 1; j <= 100000; j++) {
	var characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz';
	var name = '';
	for (var i = 0; i < 10; i++) {
		name += characters.charAt(Math.floor(Math.random() * characters.length));
	}
	var role = Math.floor(Math.random() * 5) + 1, roleval = 1;
	if (role == 2)
		roleval = 2;
	else if (role == 3)
		roleval = 3;
	db.users.insert([
		{
			login: name,
			password: name,
			role_id: roleval
		}
	])
}
