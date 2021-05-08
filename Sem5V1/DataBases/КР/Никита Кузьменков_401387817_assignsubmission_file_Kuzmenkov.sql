+1)
SELECT * 
FROM students 
WHERE course = '3';

+2)
SELECT *
FROM students 
JOIN users ON users.id = students.id 
AND users.email LIKE '%mail.ru';

-3)(ваша формула дает разность дат равной 0 для всех записей из таблицы)
SELECT name 
FROM professors 
JOIN users ON users.id = professors.user_id 
AND (EXTRACT (year FROM ('today'::timestamp - users.update_at::date))) > 3;

-4)(Неправильны синтаксис внутреннего подзапроса на выбор только 4-х записей о студентах 3-его курса)
DELETE FROM students 
USING students_subjects 
WHERE students.course = '3' 
AND studendts.id = students_subjects.student_id 
AND (SELECT count(*) FROM students_subjects WHERE students_subjects.value < 4) = 3 
ORDER BY students.lastname, students.firstnamre ASC; 

--5)(неправильный JOIN, нет проверки, что все оценки у студента выше 4-х, неправильный WHERE NOT EXISTS....)
SELECT email FROM users
JOIN professors ON professors.name ='Иванова'
JOIN subjects ON subjects.professors_id = professors.id
WHERE NOT EXISTS(is_exam = false);