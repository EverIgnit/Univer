/*�������� �.�., ������� 2*/

+ /*������ 1*/
SELECT name FROM products WHERE name LIKE '�%�%';

- /*������ 2*/ ��� �������, �� �������� ���������� ����������� ������, GROUP BY - ������, �.�. � ��� ��� ���������� ������� � SELECT; ������� ������ ���� ��������� 

SELECT * FROM orders
JOIN payments ON payments.method="������"
GROUP BY orders.id;

+ /*������ 3*/ ������� ������ ���� ��������� 
SELECT DISTINCT * FROM users
JOIN orders ON orders.status="�� �������" AND users.id=orders.users_id;


+/*������ 4*/
DELETE FROM products
WHERE products.id NOT IN (
SELECT b.product_id
FROM basket b
);

-/*������ 5*/ '0.00' ����� ��������������� � ���� money 0.00::money; 
orders.status ����� �� �����, ���� ����� ���������� �� ������� ������ (�������� ��������, ��� ����� ����� ���� ��������� �� ������ ������ -  ����� ������, ����� ���������)
�������� �� ��������� ������ �� ������� basket 

SELECT orders.id, SUM(payments.value) FROM orders
JOIN payments ON orders.status!= 'processing'
AND payments.value>'0.00'
AND payments.order_id=orders.id
GROUP BY orders.id;

-/*������ 6*/  �� ������ ������ ��� ������ ��������� ������ �� 10% (���� ������ ��� ������ � ��� ��� money), � ���� �������, ���������� ������� �� ������ ������ 100. ����� ��������� ������� ��������� � basket.quantity, ��� � ���� ����������� �� ������� ������������ ������.

UPDATE products SET discount = discount * 0.9 WHERE quantity <100;

-/*������ 7*/ ������� AVG ������ �������� ��������� � ���� money
SELECT AVG(value) FROM payments
JOIN orders ON payments.order_id = orders.id AND orders.status = '��������';

/*������ 8*/

-/*������ 9*/ ��� ������ ������� �������� ������� � �� ���������� �� ������. �� ������� ���� ���� ������ ��������.
SELECT name,quantity FROM products;

/*������ 10*/
