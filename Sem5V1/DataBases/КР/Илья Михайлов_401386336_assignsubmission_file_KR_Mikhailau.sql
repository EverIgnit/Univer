
--Михайлов Илья Михайлович 
--1 Вариант

+ 1. Список студентов, обучающихся на 3 курсе
SELECT firstname, lastname FROM  students WHERE course = 3 ;


+ 2 (лишняя точка с запятой в конце 1-ой строчки). Список всех студентов, у которых email находится на домене mail.ru.
SELECT firstname, lastname FROM students;

JOIN users ON users.id = students.id 
WHERE users.email LIKE '%mail.ru';


- 3(ваша формула дает разность дат равной 0 для всех записей из таблицы) .Список имен преподавателей, у которых аккаунт не обновлялся больше 3 лет с момента создания.
SELECT name FROM professors JOIN users ON users.id = professors.user_id 
WHERE(EXTRACT (year FROM ('today'::timestamp - users.update_at::date)))>3;

-4 (Неправильны синтаксис внутреннего подзапроса на выбор только 4-х записей о студентах 3-его курса).Удалить 4 студентов 3 курса, имеющих 3 оценки ниже 4, отсортированных по фамилии и имени с конца.
DELETE FROM students
USING students_subjects
WHERE students.course = '3'
AND studendts.id = students_subjects.student_id
AND (SELECT count(*) FROM students_subjects WHERE students_subjects.value < 4) <= 4;

-5 (неправильный JOIN, нет проверки, что все оценки у студента выше 4-х, неправильный WHERE NOT EXISTS....).Список email студентов сдавших все экзамены у преподавателя Иванова на 4 и выше.
SELECT email FROM users 

JOIN professors ON  professors.name ='Иванова'

JOIN subjects ON subjects.professors_id = professors.id

WHERE NOT EXISTS(is_exam = false);
