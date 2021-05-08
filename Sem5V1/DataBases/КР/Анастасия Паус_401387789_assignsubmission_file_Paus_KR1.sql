+1.SELECT * FROM products WHERE name LIKE 'ф%л%';

-2.нет условия, по которому происходит объедиенеие таблиц, GROUP BY - лишний, т.к. у вас нет агрегатной функции в SELECT; кавычки должны быть одинарные 
SELECT * FROM orders or
JOIN payments pay ON pay.method="картой"
GROUP BY or.id;

+3.SELECT DISTINCT * FROM users us
JOIN orders or ON or.status='не оплачен'
AND us.id=or.users_id;

+4.DELETE FROM products pr
WHERE pr.id NOT IN (
SELECT b.product_id
FROM basket b
);

-5. '00.00' лучше преобразовывать к типу money 0.00::money; 
orders.status здесь не важен, надо сумму оплаченную по каждому заказу (обратите внимание, что оплат может быть несколько по 1-ому заказу -  часть картой, часть наличными) сравнить со стомостью заказа из таблицы basket 

SELECT orders or.id, SUM(payments.value) FROM orders
JOIN payments pay ON or.status!= 'D'
AND pay.value >'00.00'
AND pay.order_id=or.id
GROUP BY or.id;

-9. Во внутреннем запросе FROM basket должно идти до LEFT JOIN. Не хватает запятой после SELECT p.name. С помощью COUNT(*)  вы считаете строки в таблице products, а вам надо посчтитать (просуммировать) количество ПРОДАННОГО товара (см. таблицу basket.quantity) . Не хватает запятой после SELECT pr.name. Во внтуреннем запросе в поле SELECT  не надо писать название таблицы, из которой происходит выборка, здесь указываются только поля, которые хотим вывести на экран (т.е. basket b в этом месте лишнее) Ошибка в  LEFT JOIN orders or IN....., надо писать LEFT JOIN orders or ON
 

SELECT pr.name COUNT(*)
FROM products pr
WHERE pr.id IN (
SELECT basket b b.product_id
LEFT JOIN orders or IN or.id= b.order_id AND or.status='P|F'
FROM basket)
GROUP BY pr.name;