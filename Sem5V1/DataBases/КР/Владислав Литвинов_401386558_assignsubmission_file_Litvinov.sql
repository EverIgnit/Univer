1. +
SELECT * FROM students
	WHERE cource=3;
	
2. - (Error LIKE = '*mail.ru')
SELECT * FROM students
	CROSS JOIN users
	WHERE users.email LIKE = '*mail.ru'
	
3. - (users - ����� ����������� ������, CROSS JOIN -, u.update_at-u.create_at - ����������� )
SELECT * FROM professors
	CROSS JOIN users
	users AS u
	WHERE u.update_at-u.create_at> 3
	
/*10.
UPDATE students 
SET scolarship = 0 
	WHERE (
SELECT COUNT(*) FROM students AS st
INNER JOIN students_subjects AS ss ON st.Id = ss.student_id
INNER JOIN subjects AS sub ON ss.subject_id = sub.id
WHERE ss.value < 4) > 0*/

5. - (��� ��������, ��� ��� �������, � �� �����; ��� �������, ��� ��� ������ ��������� �� 4-� ����, ������� �� where ��������� � JOIN)
SELECT u.email FROM
students AS st
INNER JOIN students_subjects AS ss ON st.Id = ss.student_id
INNER JOIN subjects AS sub ON ss.subject_id = sub.id
INNER JOIN professors AS prof ON sub.professor_id = prof.id
INNER JOIN users AS u ON st.user_id = u.id
WHERE prof.name LIKE '%Иванова%'

6.- (���������� ��������� ���������� ���������� ���������, � ������� ������ ������ 9 ����  � 4-�� � ����������� ���������, ������������ ��������� UPDATE ... WHERE, ������� �� where ��������� � JOIN)
UPDATE students
SET scholarship = scholarship*2 
WHERE (
SELECT COUNT(*) 
	FROM students AS st
INNER JOIN students_subjects AS ss ON st.Id = ss.student_id
INNER JOIN subjects AS sub ON ss.subject_id = sub.id
WHERE ss.value < 9 AND st.course > 3) = 0
