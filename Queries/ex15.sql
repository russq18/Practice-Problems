/*Prints out the best selling Products and their country of originsfrom highest to lowest*/
 select
c.country,
p.productName,
orderdetails.quantityOrdered as bestselling
from
	customers c
inner join
	 products p
inner join
	orders o
inner join
	orderdetails
WHERE
o.customerNumber = c.customerNumber
and orderdetails.orderNumber = o.orderNumber
and orderdetails.productCode = p.productCode
GROUP BY country
ORDER BY bestselling desc;
