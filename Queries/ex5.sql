/* searching for check Numbers that end in H and returns their amount and customer number*/
select customerNumber, checkNumber, amount
from payments
where checkNumber in (select checkNumber from payments where checkNumber like "H%");