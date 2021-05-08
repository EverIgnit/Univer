function app_profile(startval, endval) {
	var j;
	for (j = startval; j <= endval; j++) {

		var characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz';
		var name = '';
		for (var i = 0; i < 10; i++ ) {
			name += characters.charAt(Math.floor(Math.random() * characters.length));
		}
		var month = Math.floor(Math.random()*(12-1+1)) + 1;
		var day = Math.floor(Math.random()*(30-1+1)) + 1;
		var year = Math.floor(Math.random()*(2002-1965+1)) + 1965;
		
		if (month < 10)
			month = '0' + month;
		if (day < 10)
			day = '0' + day;

		var profession = Math.floor(Math.random()*4)+1;

		db.profiles.insertOne([
			{
				user_id: Math.floor(Math.random()*(1000000 - 1 + 1)) + 1,
				nickname: name,
				sex: Math.floor(Math.random()*2)+1==1?'M':'F',
				birth_date: ISODate(year + '-' + month + '-' + day),
				dossier: name,
				profession: profession==1?'designer':profession == 2?'programmer':profession == 3?'screenwriter':'editor'
			}
		])
	}
}
