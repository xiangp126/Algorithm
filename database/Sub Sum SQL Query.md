## Sub Sum SQL Query
<http://sqlfiddle.com/>

### Schema
```sql
Create table If Not Exists Employee (Year int, Salary int);
Truncate table Employee;
insert into Employee (Year, Salary) values ('2001', '1000');
insert into Employee (Year, Salary) values ('2002', '2000');
insert into Employee (Year, Salary) values ('2003', '3000');
insert into Employee (Year, Salary) values ('2004', '4000');
```

just as

```
| Year | Salary |
|------|--------|
| 2001 |   1000 |
| 2002 |   2000 |
| 2003 |   3000 |
| 2004 |   4000 |
```

Write a SQL query to get each sub sum of Salary of Employee table.

```
| Year | Salary |
|------|--------|
| 2001 |   1000 |
| 2002 |   3000 |
| 2003 |   6000 |
| 2004 |   10000 |
```

### SQL - Left Join
```sql
select *
from Employee as e1
  left join Employee as e2
  on e1.Year > e2.Year
order by e1.Year
```

output is

```
| Year | Salary |   Year | Salary |
|------|--------|--------|--------|
| 2001 |   1000 | (null) | (null) |
| 2002 |   2000 |   2001 |   1000 |
| 2003 |   3000 |   2001 |   1000 |
| 2003 |   3000 |   2002 |   2000 |
| 2004 |   4000 |   2001 |   1000 |
| 2004 |   4000 |   2002 |   2000 |
| 2004 |   4000 |   2003 |   3000 |
```

### SQL - 90% Right
```sql
select e1.Year, sum(e2.Salary) + e1.Salary as Salary
from Employee as e1
  left join Employee as e2
  on e1.Year > e2.Year
group by e1.Year
# order by e1.Year
```

output is

```
| Year | Salary |
|------|--------|
| 2001 | (null) |
| 2002 |   3000 |
| 2003 |   6000 |
| 2004 |  10000 |
```

### SQL - AC
- MySQL `IFNULL()` Function

Return the specified value IF the expression is NULL, otherwise return the expression:

```sql
select e1.Year, sum(ifnull(e2.Salary, 0)) + e1.Salary as Salary
from Employee as e1
  left join Employee as e2
  on e1.Year > e2.Year
group by e1.Year
```

output is

```sql
| Year | Salary |
|------|--------|
| 2001 |   1000 |
| 2002 |   3000 |
| 2003 |   6000 |
| 2004 |  10000 |
```