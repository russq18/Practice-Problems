/*Prints out the 5 Lowest performing Sales Reps*/
Select 
 employees.employeeNumber,
 CONCAT(employees.firstName, " ", employees.lastName) as fullName, 
 employees.jobTitle,
 SUM(orderdetails.quantityOrdered * orderdetails.priceEach) as totalSales 
from
employees
inner join
customers
inner join
orders
inner join 
orderdetails
where 
employees.employeeNumber = customers.salesRepEmployeeNumber
and orders.customerNumber = customers.customerNumber
and orders.orderNumber = orderdetails.orderNumber
GROUP BY employees.employeeNumber
ORDER BY totalSales asc limit 5; 