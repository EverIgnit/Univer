-- Секционирование отзывов по кварталам методом наследования
CREATE TABLE reviews_2020_quarter_1 (LIKE reviews INCLUDING ALL) INHERITS (reviews);
ALTER TABLE reviews_2020_quarter_1 ADD CHECK (publish_date BETWEEN date'2020-01-01' AND date'2020-03-31');
CREATE TABLE reviews_2020_quarter_2 (LIKE reviews INCLUDING ALL) INHERITS (reviews);
ALTER TABLE reviews_2020_quarter_2 ADD CHECK (publish_date BETWEEN date'2020-04-01' AND date'2020-06-30');
CREATE TABLE reviews_2020_quarter_3 (LIKE reviews INCLUDING ALL) INHERITS (reviews);
ALTER TABLE reviews_2020_quarter_3 ADD CHECK (publish_date BETWEEN date'2020-07-01' AND date'2020-09-30');
CREATE TABLE reviews_2020_quarter_4 (LIKE reviews INCLUDING ALL) INHERITS (reviews);
ALTER TABLE reviews_2020_quarter_4 ADD CHECK (publish_date BETWEEN date'2020-10-01' AND date'2020-12-31');
-- Создание триггера
CREATE OR REPLACE FUNCTION review_select_part()
RETURNS TRIGGER AS $$
BEGIN
	IF NEW.publish_date  BETWEEN date'2020-01-01' AND date'2020-03-31' THEN
		INSERT INTO reviews_2020_quarter_1 VALUES(NEW.*);
	ELSIF NEW.publish_date BETWEEN date'2020-04-01' AND date'2020-06-30' THEN
		INSERT INTO reviews_2020_quarter_2 VALUES(NEW.*);
	ELSIF NEW.publish_date BETWEEN date'2020-07-01' AND date'2020-09-30' THEN
		INSERT INTO reviews_2020_quarter_3 VALUES(NEW.*);
	ELSIF NEW.publish_date BETWEEN date'2020-10-01' AND date'2020-12-31' THEN
		INSERT INTO reviews_2020_quarter_4 VALUES(NEW.*);
	ELSE
		RAISE EXCEPTION 'NO EXISTING QUATER FOR PROVIDED DATE';
	END IF;
	RETURN NULL;
END;
$$
LANGUAGE plpgsql;

CREATE TRIGGER on_review_insertion
	BEFORE INSERT ON reviews
	FOR EACH ROW EXECUTE PROCEDURE review_select_part();
-- Проверка работы
SELECT * FROM reviews;
SELECT describtion FROM reviews WHERE publish_date > date'2020-08-01';