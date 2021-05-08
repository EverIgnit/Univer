INSERT INTO PROPERTY (Property_no, Data_registration, Postcode, City, Street, House, Flat, Floor_Type, Floor, Rooms, The_area, Balcony, Ptel, Selling_Price, Branch_no,	Staff_no, Owner_no)
VALUES
(1111, '13.9.16', 21033, 'Витебск', 'Смоленская', '11',   58,  '5П',  3, 1, '31/18/10',       'Б',   'Т',     60000,  1, null, 1);



INSERT INTO PROPERTY (Property_no, Data_registration, Postcode, City, Street, House, Flat, Floor_Type, Floor, Rooms, The_area, Balcony, Ptel, Selling_Price, Branch_no,	Staff_no, Owner_no)
VALUES
(1112, '13.9.16', 21033, 'Витебск', 'Смоленская', '11',   58,  '5П', 4, 3, '31/18/10',       'Б',   'Т',     60000,  1, null, 1);


INSERT INTO VIEWING (Date_View, Comments, Property_no, Buyer_no)
VALUES 
('26.11.16', 'согласен',        3003, 2),
('21.12.16', 'согласен',        3004, 4),
('15.10.16', 'согласен',        3005, 7),
('12.9.16', 'согласен',         3006, 2),
('14.8.16', 'согласен',         3007, 3);


INSERT INTO STAFF (Staff_no, FName, LName, DOB, Sex, City, Street, House, Flat, Stel_no, DateJoined, Position, Salary, Branch_no)  
VALUES 
(20269, 'Батуркин',  'Сергей', '17.10.68', 'М', 'Новополоцк', 'Парковая',   '6',    13,   '23-33-77',        '5.01.1999',  'менеджер-2',       2100000, 3);