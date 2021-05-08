
USE DreamHome

CREATE TABLE OWNER 
(Owner_no member_no IDENTITY(1,1) NOT NULL,
FName shortstring NOT NULL,
LName shortstring NOT NULL,
City shortstring NOT NULL,
Street shortstring NOT NULL,
House member_no NOT NULL,
Flat smallint NULL,
Otel_no Phonenumber NULL)