//1.Выборка всех данных, фильтрация по конкретному полю, массиву, встроенному объекту.

db.users.find({$comment: "Выборка всех данных"}).pretty()

db.profiles.find({profession:"programmer", $comment: "Выборка по конкретному полю"}).pretty()

db.profiles.find({hobbies:"draw", $comment: "Выборка по массиву"}).pretty()

db.profiles.find({"photo":"D:\Downloads\photo.png", $comment: "Выборка по встроенному объекту"}).pretty()

//2.Выборка в интервале, выборка из заданного списка значений.

db.profiles.find({birth_day:{$gt:ISODate("2000-04-25"), $lte: ISODate("2003-04-25")}, $comment: "Выборка в интервале"}).pretty()

db.profiles.find({nickname: {$in:["Navi", "Vertus"]},$comment: "Выборка из заданного списка значений"}).pretty()

//3.Выборка с использованием регулярных выражений.

db.profiles.find({"nickname":{$regex:"vi"}, $comment: "Выборка с использованием регулярных выражений"}).pretty()

//4.Выборка данных за конкретный период времени, на сегодняшний день, за последний месяц.

db.messages.find({"create_at": {$gte: new Date(ISODate("2021-01-01")), $lte: new Date(ISODate("2021-03-03"))}, $comment: "Выборка в интервале"}).pretty()

db.messages.find({"create_at": {$gte: new Date(new Date().getFullYear(), new Date().getMonth(), new Date().getDate(), 0, 0, 0), $lte: new Date()},}).pretty()

db.messages.find({"create_at ": {$gte: new Date(new Date().getFullYear(),new Date().getMonth(), 1, 0, 0, 0), $lt: new Date(new Date().getFullYear(),new Date().getMonth()+1, 1, 0, 0, 0)}).pretty()

//5.Выборка данных из нескольких таблиц.

db.users.aggregate([{$lookup: {from: "messages", localField: "_id", foreignField: "sender_id", as: "messages_by_user"}}]).pretty()

//6. Выборка из нескольких таблиц с фильтрацией.

db.users.aggregate([{$lookup: {from: "messages", localField: "_id", foreignField: "sender_id", as: "messages_by_user"}}, {$match: { "_id": 1341}}], ).pretty()

//7. Выборка ограниченного набора полей.

db.users.find({},{role_id: 1}).pretty() 

//8. Сортировка по 1 полю, по нескольким полям.

db.users.find({$comment: "Сортировка по 1 полю"}).sort({role_id: -1}).pretty()

db.messages.find({$comment: "Сортировка по нескольким полям"}).sort({sender_id: 1,receiver_id:-1}).pretty()

//9. Вывод данных с n-ого по m-ый номер.

db.profiles.find({$comment: "Выборка  с n-ого по m-ый номер"}).skip(1).limit(5).pretty()

//10. Написать запрос, который объединяет 1-9 пункты.

db.profiles.aggregate([{$match: {"birth_day": {$gte: ISODate("2000-01-01"), $lte: ISODate("2004-01-01")}}}, {$limit:5}, {$project:{tags: 1}}, {$sort: {"user_id": -1}}]).pretty()

