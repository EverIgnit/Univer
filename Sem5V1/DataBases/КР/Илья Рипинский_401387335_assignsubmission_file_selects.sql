+1. Список студентов 3 курса

SELECT *
FROM 
students s
WHERE
s.course = 3

- 2.(Error LIKE = '*mail.ru') Список всех студентов, у которых email находится на домене mail.ru.

SELECT *
FROM 
students s
CROSS JOIN  
users u
WHERE
u.email LIKE '*.mail.ru'

-3( CROSS JOIN - неправильно, u.update_at-u.create_at - неправильно ). Список имён преподавателей, у которых аккакунт не обновлялся больше трёх лет с момента создания

SELECT p.name имя
FROM 
professors p
CROSS JOIN  
users u
WHERE
(u.update_at - u.create_at) > 3


-4 (запрос неверный). Удалить 4 студента 3 кура, имеющих 3 оценки ниже 4, отсортированных по фамилии и имени с конца

DELETE 
FROM students s 
USING students_subjects sub
WHERE
(SELECT COUNT(*)
FROM students_subjects ss
WHERE
value < 4 )< 3 AND
s.course = 3


- 5 (нет проверки, что это экзамен, а не зачет; нет условия, что все оценки студентов на 4-и выше, условие из where перенести в JOIN). Список email студентов сдавших все экзамены у преподавателя Иванова на 4 и выше.

SELECT u.email  почта
FROM students AS s
INNER JOIN students_subjects AS ss ON s.Id = ss.student_id
INNER JOIN subjects AS sub ON ss.subject_id = sub.id
INNER JOIN professors AS prof ON sub.professor_id = prof.id
INNER JOIN users AS u ON s.user_id = u.id
WHERE 
prof.name LIKE '%Иванова%'

- 6 (неправильный синтаксис UPDATE ... WHERE, условие из where перенести в JOIN, внутренний запрос возвращает количество студентов с оцнками >8). Увеличить всем студентам стипендию в 2 раза, у которых 1-4 семестр только на 9-10.

UPDATE students 
SET scholarship = scholarship*2
WHERE (
SELECT COUNT(*)
FROM students AS s
INNER JOIN students_subjects AS ss ON s.Id = ss.student_id
INNER JOIN subjects AS sub ON ss.subject_id = sub.id
WHERE 
ss.value > 8 AND s.course IN (1,2,3,4)) > 0

-- 7. Список фамилии и имена студентов и их средний балл за 1 семестр.

-- 8. Вывести сумму, которая тратятся на стипендии.

-- 9. Вывести название самого простой предмет (по средней оценке).

-- 10. Обнулить стипендии студентов, у которых есть хотя бы одна оценка меньше 4.