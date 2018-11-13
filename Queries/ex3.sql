/*returns the top ten offices with their locations*/
select 
count(employees.employeeNumber) as 'count',
offices.*

from employees
inner join offices
where employees.officeCode = offices.officeCode
group by offices.officeCode
order by count desc;