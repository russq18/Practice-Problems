/*Return the Name, Employee Number, Job Title, and total sales ofthe top 5 performing Employees*/
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
ORDER BY totalSales Desc limit 5; 
 
