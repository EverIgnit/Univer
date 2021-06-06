--Контрольная работа

--I.Создаём БД

CREATE DATABASE Faculty
USE Faculty

--II.Создаём таблицы

CREATE TABLE speciality(
Specialty_id   smallint    NOT NULL PRIMARY KEY,
SpecialtyName  varchar(20)  NOT NULL,
);

CREATE TABLE groups(
Group_id       smallint    NOT NULL PRIMARY KEY,
GroupName      varchar(20)  NOT NULL,
Specialty_id   smallint    NOT NULL,
CONSTRAINT FK_GROUP_SPECIALTY FOREIGN KEY(Specialty_id) REFERENCES speciality ON UPDATE CASCADE,
);

CREATE TABLE students(
Student_id  smallint    NOT NULL PRIMARY KEY,
SName       varchar(20)  NOT NULL,
SSurname    varchar(20)  NOT NULL,
SPatronymic varchar(20)  NOT NULL,
Foto        varchar(20)   NOT NULL,
Group_id    smallint     NOT NULL,
Admittance  bit           NOT NULL,
Stipend     money         NOT NULL,
CONSTRAINT FK_STUDENTS_GROUP FOREIGN KEY(Group_id) REFERENCES groups ON UPDATE CASCADE,
);

CREATE TABLE timetable(
Group_id       smallint    NOT NULL,
Subjects_id    smallint    NOT NULL,
Data           date         NOT NULL,
Classroom      varchar(20)  NOT NULL,
Teacher_id     smallint    NOT NULL,
PRIMARY KEY(Group_id,Subjects_id),
CONSTRAINT FK_TIMETABLE_GROUP FOREIGN KEY(Group_id) REFERENCES groups ON UPDATE CASCADE,
);

CREATE TABLE subjects(
Subjects_id   smallint    NOT NULL PRIMARY KEY,
SubjectName   varchar(20)  NOT NULL,
Cathedra      varchar(20)  NOT NULL,
);

CREATE TABLE teachers(
Teacher_id    smallint    NOT NULL PRIMARY KEY,
TName         varchar(20)  NOT NULL,
TSurname      varchar(20)  NOT NULL,
TPatronymic   varchar(20)  NOT NULL,
Cathedra      varchar(20)  NOT NULL,
Position      varchar(20)  NOT NULL,
);

CREATE TABLE grades(
Student_id      smallint    NOT NULL,
Subjects_id    smallint    NOT NULL,
Grades         int          NOT NULL,
Teacher_id     smallint    NOT NULL,
Data           date         NOT NULL,
TypeOfControl  varchar(20)  NOT NULL,
PRIMARY KEY(Student_id,Subjects_id),
CONSTRAINT FK_GRADES_SUBJECTS FOREIGN KEY(Subjects_id) REFERENCES subjects ON UPDATE CASCADE,
CONSTRAINT FK_GRADES_STUDENTS FOREIGN KEY(Student_id) REFERENCES students ON UPDATE CASCADE,
CONSTRAINT FK_GRADES_TEACHER FOREIGN KEY(Teacher_id) REFERENCES teachers ON UPDATE CASCADE,
); 

III.Заполняем таблицы
teachers
INSERT teachers VALUES (1,'Пётр', 'Петров', 'Петрович', 'Геометрия', 'Доцент');
INSERT teachers VALUES (2,'Иван', 'Михайлов', 'Петрович', 'Алгебра', 'Ассистент');
INSERT teachers VALUES (3,'Никита', 'Степанов', 'Петрович', 'Русский язык', 'Профессор');
INSERT teachers VALUES (4,'Семён', 'Ботвинов', 'Петрович', 'Геометрия', 'Доцент');
INSERT teachers VALUES (5,'Никита', 'Кузьменьков', 'Владимирович', 'Геометрия', 'Ст.преподаватель');

--speciality
INSERT INTO speciality VALUES(100,'ПИ');
INSERT INTO speciality VALUES(101,'ПОИТ');
INSERT INTO speciality VALUES(102,'КБ');
INSERT INTO speciality VALUES(103,'ПМ');

--GROUP
INSERT INTO groups VALUES (11, 'ПОКС',100);
INSERT INTO groups VALUES (12, 'ПриМат',101);
INSERT INTO groups VALUES (13, 'МатИнф',102);
INSERT INTO groups VALUES (14, 'WEB',103);

--subjects
INSERT INTO subjects VALUES(1,'Анал.геом.','Геометрия');
INSERT INTO subjects VALUES(2,'Теория чисел','Алгебра');
INSERT INTO subjects VALUES(3,'Орфография','Русский язык');
INSERT INTO subjects VALUES(4,'Матимака','Алгебра');

--timetable
INSERT timetable VALUES(11,1,'2020-12-17','117a',3);
INSERT timetable VALUES(12,2,'2020-12-17','118a',2);
INSERT timetable VALUES(13,3,'2020-12-17','119a',1);
INSERT timetable VALUES(14,4,'2020-12-17','118a',4);

--students
INSERT students VALUES(101,'Иван', 'Степанов', 'Семенович', 'C:\photo1', 11, 1, 100);
INSERT students VALUES(102,'Илья', 'Семенов', 'Семенович', 'C:\photo2', 13, 0, 140);
INSERT students VALUES(103,'Семен', 'Михайлов', 'Семенович', 'C:\photo3', 11, 1, 150);
INSERT students VALUES(104,'Виталий', 'Семенов', 'Семенович', 'C:\photo4', 12, 0, 100);
INSERT students VALUES(105,'Семен', 'Семенов', 'Семенович', 'C:\photo5', 14, 1, 190);

--grades
INSERT INTO grades VALUES (101,1,10,1,'2020-12-17','Экзамен');
INSERT INTO grades VALUES (102,3,9,1,'2020-12-18','Зачёт');
INSERT INTO grades VALUES (103,1,8,1,'2020-12-19','Экзамен');
INSERT INTO grades VALUES (101,2,5,1,'2020-12-20','Зачёт');
INSERT INTO grades VALUES (101,4,3,2,'2020-12-20','Зачёт');
