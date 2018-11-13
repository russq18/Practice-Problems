/*Prints out fiscal year total sales*/
select
	year(orders.orderDate) as fiscalYear,
     SUM(orderdetails.quantityOrdered * orderdetails.priceEach) as totalSales 
from
	orders
inner join
	orderdetails
group by fiscalYear
order by totalSales
;