/* Kubekin Tsimafei Vitalievich */
/* Variant 2 /*

В требованиях к контр.работе было написано, что "задание заливать в формате *.sql", у вас txt-файл.

+  /*1)*/ SELECT * FROM products WHERE name LIKE 'ф%л';

-  /*2)*/  нет условия, по которому происходит объедиенеие таблиц, GROUP BY - лишний, т.к. у вас нет агрегатной функции в SELECT; кавычки должны быть одинарные 
SELECT * FROM orders JOIN payments ON payments.method="card" GROUP BY orders.id; 

+  /*3)*/ кавычки должны быть одинарные
 SELECT DISTINCT * FROM users JOIN orders ON orders.status="not payed" AND users.id=orders.users_id;

+ /*4)*/ DELETE FROM products WHERE products.id NOT IN (SELECT bt.product_id FROM basket bt);

-  /*5)*/ '0.00' лучше преобразовывать к типу money 0.00::money; 
orders.status здесь не важен, надо сумму оплаченную по каждому заказу (обратите внимание, что оплат может быть несколько по одному заказу -  часть картой, часть наличными)
сравнить со стомостью заказа из таблицы basket 
 SELECT orders.id, SUM(payments.value) FROM orders JOIN payments ON orders.status != 'Processing' AND payments.value > '0.00' AND payments.order_id=orders.id GROUP BY orders.id; 

-  /*7)*/ Функцию AVG нельзя напрямую применять к типу money
 SELECT AVG(value) AS Average_Price FROM payments WHERE payments.order_id = orders.id AND orders.status = 'Payed';