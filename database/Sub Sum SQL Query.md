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

### SQL - Inner Join just Warm Up
```sql
select *
from Employee as a
  inner join Employee as b
  on b.Year <= a.Year
order by a.Year
```

output is

```
| Year | Salary | Year | Salary |
|------|--------|------|--------|
| 2001 |   1000 | 2001 |   1000 |
| 2002 |   2000 | 2001 |   1000 |
| 2002 |   2000 | 2002 |   2000 |
| 2003 |   3000 | 2001 |   1000 |
| 2003 |   3000 | 2002 |   2000 |
| 2003 |   3000 | 2003 |   3000 |
| 2004 |   4000 | 2001 |   1000 |
| 2004 |   4000 | 2002 |   2000 |
| 2004 |   4000 | 2003 |   3000 |
| 2004 |   4000 | 2004 |   4000 |
```

### SQL - AC using inner Join
- ~~MySQL `IFNULL()` Function~~

~~Return the specified value IF the expression is NULL, otherwise return the expression:~~

```sql
select a.Year, sum(b.Salary) as Salary
from Employee as a
  inner join Employee as b
  on b.Year <= a.Year
group by a.Year
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

### SQL - AC using Double Select
```sql
select Year,
(
  select sum(Salary)
  from Employee as e2
  where e2.Year <= e1.Year
) as Salary
from Employee as e1
```

output is

```
| Year | Salary |
|------|--------|
| 2001 |   1000 |
| 2002 |   3000 |
| 2003 |   6000 |
| 2004 |  10000 |
```