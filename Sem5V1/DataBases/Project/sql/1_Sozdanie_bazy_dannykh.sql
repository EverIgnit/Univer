-- train;
DROP TABLE IF EXISTS users, carriages, tickets;

CREATE TABLE users (
     id SERIAL PRIMARY KEY,
     login VARCHAR(255) NOT NULL,
     password VARCHAR(255) NOT NULL,
     role VARCHAR(255) NOT NULL
);

INSERT INTO users (id, login, password, role) values (1, 'user', 'user', 'user');
INSERT INTO users (id, login, password, role) values(2, 'cashier', 'cashier', 'cashier');
INSERT INTO users (id, login, password, role) values(3, 'admin', 'admin','admin');

CREATE TABLE carriages (
    id SERIAL PRIMARY KEY,
    number BIGINT NOT NULL,
    type VARCHAR,
    captain VARCHAR(50) NOT NULL,
    smoking BOOLEAN NOT NULL
) ;  

INSERT INTO carriages (id, number, type, captain, smoking) values ( 1, 1,'common', 'Тимофеев М.Ф.',true);
INSERT INTO carriages (id, number, type, captain, smoking) values ( 2, 2,'econom class', 'Поляков П.Е.',false);
INSERT INTO carriages (id, number, type, captain, smoking) values ( 3, 3,'econom class', 'Иванов П.Е.',true);
INSERT INTO carriages (id, number, type, captain, smoking) values ( 4 ,4 ,'coupe', 'Туров В.Э.',true);
INSERT INTO carriages (id, number, type, captain, smoking) values ( 5, 5,'coupe', 'Игнатьев З.М.',false);
INSERT INTO carriages (id, number, type, captain, smoking) values ( 6, 6,'coupe', 'Игнатьев З.М.',false);

CREATE TABLE tickets (
     id SERIAL,
     half_free BOOLEAN NOT NULL,
     package_freight BOOLEAN NOT NULL,
     carriage_id BIGINT NOT NULL,
     user_id BIGINT NOT NULL 
) ;

ALTER TABLE tickets ADD FOREIGN KEY (carriage_id) REFERENCES carriages (id);
ALTER TABLE tickets ADD FOREIGN KEY (user_id) REFERENCES users (id);

INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id ) values (1, true, false, 6,1);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (2, false, false, 1,2);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (3, false, true, 6,3);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (4, true, false, 1,1);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (5, true, false, 2,3);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (6, false, false, 3,1);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (7, false, true, 3,2);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (8, true, false, 2,3);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (9, false, true, 2,1);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (10, false, false, 4,3);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (11, false, false, 5,2);
INSERT INTO tickets (id, half_free, package_freight, carriage_id, user_id) values (12, false, true, 4,1);
