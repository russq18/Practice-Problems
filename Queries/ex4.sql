/*find order numbers and return the highest amount*/
select
	ordernumber,
	sum(quantityOrdered)as itemsCount,
	sum(priceeach*quantityOrdered) as total
from
	orderdetails
group by orderNumber
having total > 1000 and itemsCount > 600
order by total desc;