1) 
SELECT id,firstname,lastname FROM students where course=3;

2)
SELECT s.id from students as s inner join users on s.user_id=users.id 
	WHERE users.email LIKE '%@mail.ru';
	
3)
SELECT name from professors inner join users on users.id=professors.user_id 
	where (date_part('year',update_at)-date_part('year',create_at)>3 
		AND date_part('month',update_at)>=date_part('month',create_at) 
		AND date_part('day',update_at)>=date_part('day',create_at)) 
        	OR (date_part('year',update_at)-date_part('year',create_at)-1)>3;

4)
DELETE FROM students WHERE id IN (
  select ss.student_id from students_subjects as ss, students as s 
  	where s.id=ss.student_id and value<=4 group by ss.student_id, s.lastname, s.firstname 
  		having count(value)>=3
     order by s.lastname DESC, s.firstname DESC limit 4);

5)
WITH sp as (select s.id as id from subjects AS s, professors as p 
            	where p.id=s.professor_id and p.name='Ivanova' and s.is_exam=true)
SELECT u.email from users as u, students as st, students_subjects as ss, sp 
	where u.id=st.user_id AND ss.student_id=st.id and ss.subject_id=sp.id 
    	GROUP by u.email having min(ss.value)>=4;
		

6)
UPDATE students SET scholarship=scholarship*2 WHERE id in(
  	SELECT student_id from students_subjects as ss, subjects as s 
  		WHERE semester BETWEEN 1 and 4 group by student_id having min(value)>=9);


7)
SELECT firstname,lastname, ss.avg from students as s, 
	(SELECT student_id as id, AVG(value) as avg from students_subjects as sts, subjects as sub 
		where sub.id=sts.subject_id and sub.semester=1 group by student_id) as ss 
    where s.id=ss.id;
	
8)
SELECT SUM(scholarship) from students;

9)
SELECT s.name, avg(value) as otsenka from subjects as s, students_subjects as ss 
	where s.id=ss.subject_id
    	group by s.id ORDER BY otsenka DESC LIMIT 1;
		

10)
UPDATE students SET scholarship=0 where id IN (
  	SELECT student_id from students_subjects as ss 
  	group by ss.student_id HAVING MIN(value)<4);
	
	