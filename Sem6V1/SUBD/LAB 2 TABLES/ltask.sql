 USE DreamHome

CREATE TABLE STAFF (
    Staff_no    member_no   NOT NULL PRIMARY KEY,
    FName       shortstring NOT NULL,
    Position    shortstring NOT NULL,
    Sex         shortstring NOT NULL CHECK (Sex = 'М' or Sex = 'Ж'),
    Street      shortstring NOT NULL,
    House       member_no   NOT NULL,
    Flat        smallint        NULL,
    Branch_no   member_no       NULL,

    CONSTRAINT STAFF_BRANCH FOREIGN KEY(Branch_no) REFERENCES BRANCH ON UPDATE CASCADE
)
CREATE INDEX ASDS ON STAFF (FName)


USE DreamHome

CREATE TABLE PROPERTY  (
    Property_no member_no   NOT NULL PRIMARY KEY,
    FName       shortstring NOT NULL,
    Rooms       shortstring NOT NULL CHECK (Rooms <> 0),
    City        shortstring NOT NULL,
    Ptel        shortstring NOT NULL DEFAULT 'Т',
    House       member_no   NOT NULL,
    Flat        smallint        NULL,
    Branch_no   member_no   NOT NULL,
    Staff_no    member_no       NULL,
    Owner_no    member_no   NOT NULL,

    CONSTRAINT PROPERTY_BRANCH FOREIGN KEY(Branch_no) REFERENCES BRANCH ON UPDATE  CASCADE,
    CONSTRAINT PROPERTY_Staff  FOREIGN KEY(Staff_no)  REFERENCES STAFF  ON UPDATE  CASCADE,
    CONSTRAINT PROPERTY_Owner  FOREIGN KEY(Owner_no)  REFERENCES OWNER  ON UPDATE  CASCADE,
)


CREATE TABLE VIEWING (
    Staff_no    member_no   NOT NULL PRIMARY KEY,
    FName       shortstring NOT NULL,
    LName       shortstring NOT NULL,
    City        shortstring NOT NULL,
    Street      shortstring NOT NULL,
    House       member_no   NOT NULL,
    Flat        smallint        NULL,
    Property_no member_no   NOT NULL,
    Buyer_no    member_no   NOT NULL,
    Date_View   member_no   NOT NULL,

    CONSTRAINT STAFF_BRANCH PRIMARY KEY(Property_no, Buyer_no)
)
CREATE INDEX S ON VIEWING (Date_View)


CREATE TABLE CONTRACT (
    Sale_no       member_no     NOT NULL PRIMARY KEY,
    Notary_Office shortstring   NOT NULL,
    Date_Contract smalldatetime NOT NULL,
    Service_Cost  money         NOT NULL,
    Property_no   member_no     NOT NULL,
    Buyer_no      member_no     NOT NULL,

    CONSTRAINT CONTRACT_PROPERTY FOREIGN KEY(Property_no) REFERENCES PROPERTY ON UPDATE  CASCADE,
    CONSTRAINT CONTRACT_BUYER    FOREIGN KEY(Buyer_no)    REFERENCES BUYER    ON UPDATE  CASCADE,
)


/*

USE DreamHome


CREATE TABLE VIEWING (
    Staff_no member_no PRIMARY KEY NOT NULL,
FName shortstring NOT NULL,
LName shortstring NOT NULL,
City shortstring NOT NULL,
Street shortstring NOT NULL,
House member_no NOT NULL,
Flat smallint NULL,
Property_no member_no NOT NULL ,
Buyer_no member_no NOT NULL  ,
Date_View member_no NOT NULL,
CONSTRAINT VIEWING_PROPERTY FOREIGN KEY(Property_no) REFERENCES PROPERTY ON UPDATE  NO ACTION,
CONSTRAINT VIEWING_BUYER FOREIGN KEY(Buyer_no) REFERENCES BUYER ON UPDATE  NO ACTION,
)
CREATE INDEX S ON VIEWING (Date_View)

*/
