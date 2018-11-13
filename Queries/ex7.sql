/*Prints the countries with their customer count from Lowest to Highest*/
SELECT 
country, 
count(customerNumber) as 'count' 
from customers 
GROUP BY country 
ORDER BY count asc;
