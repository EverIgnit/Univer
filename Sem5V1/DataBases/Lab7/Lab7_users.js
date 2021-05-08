function app_users(startval, endval) {
	startval = 1;
	endval = 1000;
	var j,characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz';
	for (j = startval; j <= endval; j++) {
		var name = '';
		for (var i = 0; i < 10; i++ ) {
			name += characters.charAt(Math.floor(Math.random() * characters.length));
		}

		db.users.insertOne([
			{
				_id: Math.floor(Math.random()*(1000000 - 1 + 1)) + 1,
				login: name,
				password: name,
				role_id: Math.floor(Math.random()*3)+1
			}
		])
	}
}
