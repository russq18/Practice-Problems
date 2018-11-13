/*Prints out all the orders that have not been confirmed as shipped */
select orders.status, customers.state,count(customers.state) as number
from orders
inner join
customers
where
customers.customerNumber = orders.customerNumber
and status != "Shipped"
Group by orders.status, state;