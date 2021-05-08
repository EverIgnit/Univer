--1.	Вывести количество товаров для каждой категории.

SELECT p.category_id COUNT(*)  FROM products AS cat_prod GROUP BY p.category_id 

--2.	Вывести список пользователей, которые не оплатили хотя бы 1 заказ полностью.

SELECT users.id users.login FROM users
JOIN orders ON users.id=orders.users_id AND orders.status=’C’
 
--3.	Удалить товары, которые ни разу не были куплены (отсутствуют информация в таблице basket).

DELETE FROM products
  WHERE products.id NOT IN (
    SELECT basket.product_id
      FROM basket)
--4.	Вывести заказы, которые оплачены только частично.

SELECT orders.id, SUM(payments_orders.value) FROM orders 
JOIN payments_orders ON orders.status!= 'D' AND payments_orders.value>'0.00' AND payments_orders.order_id=orders.id GROUP BY orders.id 
--5.	Вывести для каждого покупателя количество его заказов по статусам.

SELECT u.id COUNT(o.*)
FILTER (WHERE o.status = 'N'  ) AS n_count, count(o.*)
FILTER (WHERE o.status = 'D'  ) AS d_count, count(o.*)
FILTER ( WHERE o.status = 'P'  ) AS p_count, count(o.*)
FILTER (WHERE o.status = 'F'  ) AS f_count, count(o.*)
FILTER (WHERE o.status = 'C') AS c_count, FROM users u
RIGHT JOIN orders o ON o.user_id = u.id GROUP BY u.id
 
--6.	Вывести средний чек для выполненных заказов (status='F').

SELECT AVG(orders.price::numeric::float8) AS srCheck FROM orders
WHERE orders.status='F '


--7.	Вывести топ-10 самых продаваемых товаров по суммарной прибыли (заказы для этих товаров должны быть полностью оплачены).
SELECT p.*, SUM(b.price) AS basket_valueFROM products p
RIGHT JOIN basket b ON b.product_id = p.id,  (SELECT o.id, o.price SUM(p_o.value) AS paid_value FROM orders o
RIGHT JOIN payment_orders p_o ON p_o.order_id = o.id
GROUP BY o.id, p_o.value) AS paid_orders
JOIN basket ON b.order_id = paid_orders.id
WHERE paid_orders.price <= paid_orders.paid_value
GROUP BY p.id ORDER BY basket_value DESC LIMIT 10
--8.	Вывести список товаров, которые лежат пока только в корзине и не привязаны к заказу, и их количества не хватает на складе для продажи (считается, что товар списывается со склада только тогда, когда заказ будет доставлен).

SELECT p.* FROM products p 
RIGHT JOIN basket b ON b.product_id = p.id  and b.order_id IS NULL
GROUP BY p.id HAVING SUM(b.quantity)<SUM(p.quantity)
--9.	Вывести список пользователей, которые "бросили"  свои корзины (не оформили заказ) за последние 30 дней.
SELECT * FROM users
JOIN orders ON orders.user_id=users.id AND orders.status=’N’
JOIN payments_orders ON orders.id=payments_orders.order_id AND payments_orders.create_at>=(SELECT NOW()-INTERVAL  '30'  DAY)
ORDER BY users.id

--10.	Добавить скидку 10% на все товары, которые покупались (статус заказов "P" или "F") не более 10 раз.

UPDATE products
SET discount=discount* 1.1
WHERE products.id IN
(SELECT basket.product_id FROM basket 
RIGHT JOIN orders ON basket.order_id=orders.id
WHERE orders.status in ('P,F')
GROUP BY basket.product_id HAVING COUNT(orders.*) <= 10)
--11.	Вывести количество заказов оплаченных полностью с внутреннего счета.
SELECT COUNT(*) AS inner_paym FROM orders
JOIN payments_orders
ON orders.id=payments_orders.order_id WHERE orders.status=’P’ AND payments_orders.payment_id IS NULL AND payments_orders.from_account IS TRUE
GROUP BY orders.id

--12.	Сделать скидку 50% (без доставки, только на товары) на новые заказы (статус "N") для VIP-пользователей.

UPDATE orders
SET discount = discount*1.5
WHERE orders.status = 'N' AND orders.user_id IN (SELECT user.id FROM users
RIGHT JOIN accounts ON accounts.user_id = users.id
WHERE accounts.is_vip = TRUE
GROUP BY users.id)
 
--13.	  Вывести самую популярную доставку и самый популярный способ оплаты (результат из 2 записей)
SELECT delivery_top.*,  payment_top.* FROM
(SELECT d.*, COUNT(d_o.*) AS orders_count FROM delivery d
LEFT JOIN delivery_orders d_o ON d_o.delivery_id = d.id 
ORDER BY orders_count DESC GROUP BY d.id LIMIT 1) AS delivery_top,
(SELECT p.*, COUNT(p_o .*) AS orders_count FROM payments p 
LEFT JOIN payments_orders p_o ON p_o.payment_id = p.id 
ORDER BY orders_count DESC GROUP BY p.id LIMIT 1) AS payment_top
--14.	Удалить пустые категории.
DELETE FROM categories c WHERE c.id NOT IN (SELECT products.category_id FROM products)
--15.	Вывести список пользователей, которые были оплачены полностью не более чем через час, с момента добавления первого товара в корзину.
SELECT o.*, MIN(b.created_at) AS basket_first, MAX(p_o.created_at) AS payment_last, SUM(p_o.value) AS paid_value  FROM orders o
LEFT JOIN payments_orders p_o ON p_o.order_id  =  o.id
LEFT JOIN basket b ON b.order_id = o.id
WHERE orders.price = (SELECT SUM(payments_orders.value) FROM payments_otders) AND 
(SELECT date_part('hour',
(SELECT MAX(payments_orders.create_at)-MIN(basket.create_at) FROM payments_orders, basket))) <= 1
GROUP BY o.id
 
--16.	Вернуть все деньги пользователей на внутренний счет для заказов, которые были оплачены (как внутренним счетом, так и некоторым способом оплаты) и были отменены (status = "С").
WITH ids_prices_to_change AS (
	SELECT
		o.user_id,
		o.price
	FROM orders o
	JOIN payments_orders p_o ON p_o.order_id = o.id
	WHERE 
		o.status = 'C' AND
		p_o.value >= o.price
)
UPDATE accounts
SET
	value = value + ids_prices_to_change.price
FROM ids_prices_to_change
WHERE 
	accounts.user_id = ids_prices_to_change.user_id
