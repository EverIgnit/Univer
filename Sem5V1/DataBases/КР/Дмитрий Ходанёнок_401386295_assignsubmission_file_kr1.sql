/*Ходанёнок Д.В., вариант 2*/

+ /*Запрос 1*/
SELECT name FROM products WHERE name LIKE 'ф%л%';

- /*Запрос 2*/ нет условия, по которому происходит объедиенеие таблиц, GROUP BY - лишний, т.к. у вас нет агрегатной функции в SELECT; кавычки должны быть одинарные 

SELECT * FROM orders
JOIN payments ON payments.method="картой"
GROUP BY orders.id;

+ /*Запрос 3*/ кавычки должны быть одинарные 
SELECT DISTINCT * FROM users
JOIN orders ON orders.status="не оплачен" AND users.id=orders.users_id;


+/*Запрос 4*/
DELETE FROM products
WHERE products.id NOT IN (
SELECT b.product_id
FROM basket b
);

-/*Запрос 5*/ '0.00' лучше преобразовывать к типу money 0.00::money; 
orders.status здесь не важен, надо сумму оплаченную по каждому заказу (обратите внимание, что оплат может быть несколько по одному заказу -  часть картой, часть наличными)
сравнить со стомостью заказа из таблицы basket 

SELECT orders.id, SUM(payments.value) FROM orders
JOIN payments ON orders.status!= 'processing'
AND payments.value>'0.00'
AND payments.order_id=orders.id
GROUP BY orders.id;

-/*Запрос 6*/  На данный момент ваш запрос уменьшает скидку на 10% (если учесть что скидка у нас тип money), у всех товаров, количество которых на складе меньше 100. Число купленных товаров находится в basket.quantity, его и надо суммировать по каждому наименованию товара.

UPDATE products SET discount = discount * 0.9 WHERE quantity <100;

-/*Запрос 7*/ Функцию AVG нельзя напрямую применять к типу money
SELECT AVG(value) FROM payments
JOIN orders ON payments.order_id = orders.id AND orders.status = 'оплачено';

/*Запрос 8*/

-/*Запрос 9*/ Ваш запрос выводит названия товаров и их количество на складе. По условию надо было другое выводить.
SELECT name,quantity FROM products;

/*Запрос 10*/
