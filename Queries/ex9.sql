/*Prints out the top 10 performing companies and their revenue*/
select
c.customerName,
	c.phone,
	SUM(orderdetails.quantityOrdered * priceEach) as revenue
from
	employees e
inner join
	customers c
inner join
	orders
inner join
	orderdetails
where e.employeeNumber = c.salesRepEmployeeNumber
and orders.customerNumber = c.customerNumber
and orderdetails.orderNumber = orders.orderNumber
GROUP BY e.employeeNumber
ORDER BY revenue DESC limit 10;
