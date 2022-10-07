## Customer Placing the Largest Number of Orders
### Illustrate
<https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/>
<http://sqlfiddle.com/>

### SQL Schema

```sql
Create table If Not Exists orders (order_number int, customer_number int);
Truncate table orders;
insert into orders (order_number, customer_number) values ('1', '1');
insert into orders (order_number, customer_number) values ('2', '2');
insert into orders (order_number, customer_number) values ('3', '3');
insert into orders (order_number, customer_number) values ('4', '3');
```

**Example 1:**

```sql
Example 1:

Input: 
Orders table:
+--------------+-----------------+
| order_number | customer_number |
+--------------+-----------------+
| 1            | 1               |
| 2            | 2               |
| 3            | 3               |
| 4            | 3               |
+--------------+-----------------+
Output: 
+-----------------+
| customer_number |
+-----------------+
| 3               |
+-----------------+
Explanation: 
The customer with number 3 has two orders, which is greater than either customer 1 or 2 because each of them only has one order. 
So the result is customer_number 3.
```

### Code
```sql
select customer_number
from orders
group by customer_number
order by count(order_number) desc limit 1
```
