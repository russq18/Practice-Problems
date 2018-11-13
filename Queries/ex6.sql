/*Prints the countries with their customer count from Highest to Lowest*/
SELECT 
country, 
count(customerNumber) as 'count' 
from customers 
GROUP BY country 
ORDER BY count desc;