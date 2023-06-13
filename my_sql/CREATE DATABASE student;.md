CREATE DATABASE student;
USE student;

CREATE TABLE Student
(
 Sno char(12)PRIMARY KEY,
 Sname char(20)not null,
 Birthday char(12),
 Ssex char(2),
 Sage SMALLINT,
 Sdept char(20),
 class char(22)
);

ALTER TABLE Student
ADD CONSTRAINT CK_Sex CHECK (Ssex IN ('男', '女'));

ALTER TABLE Student
ADD CONSTRAINT CK_Sno CHECK (Sno REGEXP '^2004[0-9]{4}$');

CREATE TABLE Course
(
 Cname char(40)NOT NULL,
 Cno char(4)PRIMARY KEY,
 Ccredit SMALLINT,
 teacher char(20)not NULL
);

CREATE TABLE SC
(
 Sno char(12),
 Cno char(4),
 Grade SMALLINT,
 PRIMARY KEY(Sno,Cno),
 FOREIGN KEY (Sno) REFERENCES Student(Sno), 
 FOREIGN KEY (Cno) REFERENCES Course(Cno)
);

INSERT 
INTO Student
VALUES('20041000','小明','2001-6-3','男','21','CS','2142');

INSERT 
INTO Student
VALUES('20041001','小红','2002-6-3','女','20','CS','2142');

INSERT 
INTO Student
VALUES('20041002','小龙','2001-6-4','男','21','MA','2142');

INSERT 
INTO Student
VALUES('20041003','小明','2001-6-3','男','21','IS','2141');

INSERT 
INTO Student
VALUES('20041004','大红','2001-6-3','女','21','IS','2142');

SELECT*
FROM student;

INSERT
INTO Course
VALUES('数据库','1',12,'李华');

INSERT
INTO Course
VALUES('数据结构','2',12,'张华');

INSERT
INTO Course
VALUES('c/c++课程','3',12,'李龙');

INSERT
INTO Course
VALUES('操作系统','4',12,'张龙');


INSERT INTO Sc
VALUES('20041000',2,85);

INSERT INTO Sc
VALUES('20041000',3,84);

INSERT INTO Sc
VALUES('20041000',4,85);

INSERT INTO Sc
VALUES('20041000',5,87);


INSERT INTO Sc
VALUES('20041001',2,90);

INSERT INTO Sc
VALUES('20041001',3,98);

INSERT INTO Sc
VALUES('20041001',4,91);

INSERT INTO Sc
VALUES('20041001',5,92);

INSERT INTO Sc
VALUES('20041002',2,90);

INSERT INTO Sc
VALUES('20041002',3,80);

INSERT INTO Sc
VALUES('20041002',4,90)

INSERT INTO Sc
VALUES('20041002',5,90);;

CREATE VIEW Student_View
AS
SELECT SNAME,student.Sno,Ssex,birthday,Class,Sdept,Cno,grade
from student,sc
WHERE student.sno=sc.Sno;

CREATE view Course_View
AS
SELECT *
FROM course;

CREATE view SC_View
AS
SELECT student.Sname,sc.Sno,sc.Cno,course.Cname,grade
from student,sc,course
WHERE student.Sno=sc.Sno AND sc.Cno=course.Cno;

GRANT UPDATE(sno),SELECT
ON TABLE student
TO lsd;

#设计一个查询模块，返回该学生已选修的课程
CREATE PROCEDURE get_selected_courses(IN student_sno CHAR(12))
BEGIN
    SELECT course.Cno, course.Cname
    FROM course
    INNER JOIN sc ON course.Cno = sc.Cno#连接俩表
 WHERE sc.Sno = student_sno;#判断sno的值
END;

CALL get_selected_courses('20041001');

#设计一个查询平均分模块，输入该学生的学号，返回平均分
CREATE PROCEDURE get_AVG_student(IN student_sno char(12))
BEGIN 
		SELECT AVG(grade)
		FROM sc
		WHERE sc.Sno=student_sno;
END;

CALL get_AVG_student('20041002');

#设计一个查询平均分模块，输入该学生的学号，返回总平均分、各科课号和课程名
CREATE PROCEDURE get_AVG_PRO(IN student_sno char(12))
BEGIN
		SELECT grade,sc.Cno,course.Cname
		from sc
		INNER JOIN course ON sc.Cno=course.Cno
		WHERE sc.Sno=student_sno;
		
		SELECT AVG(grade) AS total_AVG
		from sc
		WHERE sc.Sno=student_sno;
END;

CALL get_AVG_PRO('20041002');

#当一个学生删除时，会将该学生从成绩表中删除
CREATE TRIGGER DELETE_Student
AFTER DELETE ON student
FOR EACH ROW
BEGIN 
	DELETE
	FROM sc
	WHERE sc.sno=old.sno;
end;

#修改外键约束下的级联操作
ALTER TABLE Sc DROP FOREIGN KEY sc_ibfk_1;
ALTER TABLE Sc ADD CONSTRAINT sc_ibfk_1 FOREIGN KEY (sno) REFERENCES student(sno) ON DELETE CASCADE;

DELETE
FROM student
WHERE sno='20041000';

CREATE TRIGGER UPDATE_Course_Sc
AFTER UPDATE on Course
FOR each ROW
BEGIN
	UPDATE sc
	SET sc.Cno=new.cno
	WHERE sc.Cno=old.cno;
END;

ALTER TABLE sc DROP FOREIGN key sc_ibfk_2;
ALTER TABLE sc ADD constraint sc_ibfk_2 FOREIGN KEY(cno) REFERENCES course(cno) ON UPDATE CASCADE;

UPDATE course
SET cno='9'
WHERE cno='2';

DELETE 
FROM student 
WHERE sno='20041008';

UPDATE student
SET Sname='栀子花'
WHERE sno='20041001';

SELECT sname
FROM student;

CREATE DATABASE tmp;