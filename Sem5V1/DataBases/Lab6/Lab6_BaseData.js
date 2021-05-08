//roles
db.createCollection("roles")

db.roles.insert([
      {_id:"1","position":"administrator"},
      {_id:"2","position":"manager"},
      {_id:"3","position":"user"}
  ])

//users
db.createCollection("users")

db.users.insert([
    { _id : 1234 ,"login" : "login1", "password" : "1234", "email" : "fghfdgh@mail.ru", "role_id" : 1},
    { _id : 1235 ,"login" : "login2", "password" : "235345", "email" : "dfghfdgh@yandex.ru","role_id" : 2},
    { _id : 1236 ,"login" : "login3", "password" : "34234", "email" : "dfghfdgh@bk.ru","role_id" : 3}
])

//profiles
db.createCollection("profiles")

db.profiles.insert([
    { user_id: "1400", "nickname": "Vill", "foto": "D:\Downloads\photo.jpg", "sex": "M", "birth_day": ISODate("2003-04-30"), "dossier": "dfgsdfg", "hobbies": ["dfg", "retert","draw"], "profession" : "designer"},
    { user_id: "1401", "nickname": "Navi", "foto": "D:\Downloads\photo.jpg", "sex": "M", "birth_day": ISODate("1999-02-12"), "dossier": "sdfgdfgsd", "hobbies": ["draw","sdfgsdfg"], "profession" : "programmer"},
    { user_id : "1402", "nickname" : "Ffdg", "foto" : "D:\Downloads\photo.jpg", "sex" : "F", "birth_day" : ISODate("2000-04-25"), "dossier" : "sdfgsdfgsdfgsdfg", "hobbies" : ["dsfgsdfg","sdfgsdfg"], "profession" : "screenwriter"}
])

//messages
db.createCollection("messages")

db.messages.insert([
    { _id: "700", "mtext": "fdghdfghdfgh", "sender_id": 1234, "receiver_id": 1235, "create_at" : new Date()},
    { _id: "701", "mtext": "dfhfdgh dfghfghdfgh?", "sender_id": 1235, "receiver_id": 1234, "create_at" : new Date()},
    { _id: "702", "mtext": "asdfasdfsdf", "sender_id": 1234, "receiver_id": 1235, "create_at" : new Date()}
])