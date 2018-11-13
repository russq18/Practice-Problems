/*Prints out Information and order status of companies that did not get their orders shipped*/
SELECT 
orders.status,
customers.customerName,
customers.phone
from customers, orders
where customers.customerNumber = orders.customerNumber
and status != "Shipped"
