/* Returns 10 rows displaying the customer's name, number, single order transaction(amount), and total amount paid */
select customers.customerNumber,customers.customerName, payments.amount, sum(payments.amount) as 'total' from
customers 
inner join payments
where customers.customerNumber = payments.customerNumber
group by customers.customerNumber
order by total desc
limit 10;