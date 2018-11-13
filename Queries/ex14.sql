/*Prints out total sales for each country in the fiscal year*/
select
	year(o.orderDate) as fiscalYear,
c.country,
	SUM(orderdetails.quantityOrdered * orderdetails.priceEach) as totalSales
from
	orders o
inner join
	orderdetails
inner join
	customers c
where o.customerNumber = c.customerNumber
group by country
order by fiscalyear;
