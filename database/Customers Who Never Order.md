## Customers Who Never Order
### Illustrate
<https://leetcode.com/problems/customers-who-never-order/>

<http://sqlfiddle.com>

### SQL Schema
```sql
Create table If Not Exists Customers (Id int, Name varchar(255));
Create table If Not Exists Orders (Id int, CustomerId int);
Truncate table Customers;
insert into Customers (Id, Name) values ('1', 'Joe');
insert into Customers (Id, Name) values ('2', 'Henry');
insert into Customers (Id, Name) values ('3', 'Sam');
insert into Customers (Id, Name) values ('4', 'Max');
Truncate table Orders;
insert into Orders (Id, CustomerId) values ('1', '3');
insert into Orders (Id, CustomerId) values ('2', '1');
```

Suppose that a website contains two tables, the `Customers` table and the `Orders` table. Write a SQL query to find all customers who never order anything.

Table: `Customers`.

```
+----+-------+
| Id | Name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
```
Table: `Orders`.

```
+----+------------+
| Id | CustomerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+
```

Using the above tables as example, return the following:

```
+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+
```

### Test - Left (Outer) Join
```sql
select *
from Customers as cus
  left join Orders as ord
  on cus.Id = ord.CustomerId;
```

Id|	Name|	Id|	CustomerId
---|---|---|---
3	|Sam	    |1    |3
1	|Joe	    |2    |1
2	|Henry	|(null)	|(null)
4	|Max   	|(null)	|(null)

### SQL - Using `Left Join`
```sql
select Name as Customers
from `Customers` as cus
  left join `Orders` as ord
  on cus.Id = ord.CustomerId
where ord.CustomerId is null;
```

### SQL - Using `Not In`
```sql
# Write your MySQL query statement below
select Name as Customers
from `Customers`
where Id not in
(
    select CustomerId from Orders
);
```