var j, startval = 1, finalval = 100000;
for (j = startval; j <= finalval; j++) {
	var u_id = Math.floor(Math.random() * (1000000 - 1 + 1)) + 1;

	var characters = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz';
	var name = '';
	for (var i = 0; i < 10; i++) {
		name += characters.charAt(Math.floor(Math.random() * characters.length));
	}

	var year = Math.floor(Math.random() * (2002 - 1965 + 1)) + 1965;
	var month = Math.floor(Math.random() * (12 - 1 + 1)) + 1;
	var day = Math.floor(Math.random() * (30 - 1 + 1)) + 1;

	if (month < 10)
		month = '0' + month;
	if (day < 10)
		day = '0' + day;

	DoB = year + '-' + month + '-' + day;

	var profession = Math.floor(Math.random() * 4) + 1, professionval = 'designer';
	if (profession == 2)
		professionval = 'programmer';
	else if (profession == 3)
		professionval = 'screenwriter';
	else if (profession == 4)
		professionval = 'editor';

	db.profiles.insert([
		{
			user_id: u_id,
			nickname: name,
			photo: "D:\Downloads\photo.png",
			sex: (Math.floor(Math.random() * 2) + 1 ? 'M' : 'F'),
			birth_date: ISODate(DoB),
			dossier: name,
			profession: professionval
		}])
}