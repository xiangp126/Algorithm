## Second Highest Salary
### Illustrate
<https://leetcode.com/problems/second-highest-salary/>

### Schema
```sql
Create table If Not Exists Employee (Id int, Salary int);
Truncate table Employee;
insert into Employee (Id, Salary) values ('1', '100');
insert into Employee (Id, Salary) values ('2', '200');
insert into Employee (Id, Salary) values ('3', '300');
```

Write a SQL query to get the second highest salary from the `Employee` table.

```
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
```
For example, given the above Employee table, the query should return 200 as the second highest salary. **If there is no second highest salary, then the query should return null**.

```
+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+
```

### limit [Num] offset [Num]
To limit the number of rows returned by a select statement, you use the LIMIT and OFFSET clauses.

- The `LIMIT` row_count determines the number of rows (row_count) returned by the query.
- The `OFFSET` offset clause skips the offset rows before beginning to return the rows.

### MySQL IFNULL() Function

- Syntax

|IFNULL(expression, alt_value)|
|---|

- Parameter Values

|Parameter|Description|
|---|---|
|expression|	Required. The expression to test whether is NULL
|alt_value|	Required. The value to return if expression is NULL

### SQL - 5 / 7 test cases passed
The `OFFSET` clause skips the offset rows before beginning to return the rows.

```sql
select salary as SecondHighestSalary
from Employee
  order by salary desc
  limit 1 offset 1;
```

### SQL - AC
- If there is no second highest salary, then the query should **return null**
- take care of duplicate items, should use `distinct`

Since the 2nd-highest salary may not exist, we have to turn our original query into a subquery, and wrap it in a `select`:

```sql
# Write your MySQL query statement below
select ifnull(
    (select distinct salary from Employee
        order by salary desc
        limit 1 offset 1
), null) as SecondHighestSalary;
```

or directly

```sql
# Write your MySQL query statement below
select (
    select distinct salary from Employee
        order by salary desc
        limit 1 offset 1
) as SecondHighestSalary;
```
