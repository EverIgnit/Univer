USE DreamHome
CREATE TABLE BUYER
(Buyer_no member_no NOT NULL PRIMARY KEY,
FName shortstring NOT NULL,
LName shortstring NOT NULL,
City shortstring NOT NULL,
Street shortstring NOT NULL,
House nchar(6) NOT NULL,
Flat smallint NULL,
Htel_no Phonenumber NULL,
Wtel_no Phonenumber NULL,
Prof_Rooms tinyint NOT NULL,
Max_Price money NOT NULL,
Branch_no member_no NOT NULL,
CONSTRAINT FK_BUYER_BRANCH FOREIGN KEY(Branch_no) REFERENCES BRANCH ON UPDATE  CASCADE,
CHECK (Htel_no IS NOT NULL OR Wtel_no IS NOT NULL) 
)
