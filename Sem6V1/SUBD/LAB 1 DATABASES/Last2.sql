
EXEC sp_addtype Phonenumber, 'char(17)', 'NOT NULL'
EXEC sp_addtype shortstring, 'varchar(20)'
EXEC sp_addtype Postcode, 'char(6)', 'NULL'
EXEC sp_addtype member_no, 'smallint'