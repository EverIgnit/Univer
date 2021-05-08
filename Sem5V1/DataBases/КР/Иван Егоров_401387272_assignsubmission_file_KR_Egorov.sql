--Егоров Иван Геннадьевич 2 вариант

+1.Список товаров, начинающихся на буква ф и имеющих в названии букву л.

SELECT * FROM products
WHERE name LIKE 'ф%л%';

-2.нет условия, по которому происходит объедиенеие таблиц, GROUP BY - лишний, т.к. у вас нет агрегатной функции в SELECT; кавычки должны быть одинарные 

Список всех заказов, оплаченных картой.
SELECT * FROM orders
JOIN payments ON payments.method="картой"
GROUP BY orders.id;

+3.Список пользователей, которые не оплатили хотя бы 1заказ(без повторений).

SELECT DISTINCT * FROM users
JOIN orders ON orders.status='не оплачен' 
AND users.id=orders.users_id;

+4.Удалить товары, которые ни разу не покупали.

DELETE FROM products
WHERE products.id NOT IN (
SELECT basket.product_id
FROM basket
);

--5. '0' лучше преобразовывать к типу money 0.00::money; 
orders.status здесь не важен, надо сумму оплаченную по каждому заказу (обратите внимание, что оплат может быть несколько по одному заказу -  часть картой, часть наличными)
сравнить со стомостью заказа из таблицы basket 

Список заказов, которые оплатили,но не полностью.
SELECT orders.id, SUM(payments.value) FROM orders
JOIN payments ON orders.status!= 'оплачен'
AND payments.value>'0'
AND payments.order_id=orders.id
GROUP BY orders.id;

--6.Сделать скидку 10% на все товары, которых купили не более 100 штук.


+7.Вывести средний чек для всех оплаченных заказов.

SELECT AVG(payments.value::numeric::float8) FROM payments
JOIN orders ON payments.order_id=orders.id
AND orders.status='оплачено';

--8.Вывести 10 самых покупаемых товаров (максимальная прибыль) за последние 30 дней.


-9. Ошибка в LEFT JOIN orders o IN orders.id= basket.order_id, надо писать LEFT JOIN orders or ON и обращаться к таблице orders через o.id. Во внутреннем запросе FROM basket должно идти до LEFT JOIN. Ваш запрос на данный момент просто выводит назвния проданных товаров, надо было еще просуммировать проданное количество по каждому товару и вывести эту информацию на экран 

Вывести список названий товаров и их проданное количество.

SELECT products.name FROM products  
WHERE products.id IN (
SELECT basket.product_id
LEFT JOIN orders o IN orders.id= basket.order_id
AND orders.status='оплачен'
FROM basket)
GROUP BY products.name;

--10.Вывести id и цену заказов, которые были оплачены, по крайней мере,2 различными способами оплаты.


