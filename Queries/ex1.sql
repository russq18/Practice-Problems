/*Returns list of orders shipped to their respective states*/
select orders.status, customers.state
from orders
inner join
customers
where
customers.customerNumber = orders.customerNumber
;