## Nth Highest Salary
### Illustrate
<https://leetcode.com/problems/nth-highest-salary/>

### Schema
```sql
Create table If Not Exists Employee (Id int, Salary int);
Truncate table Employee;
insert into Employee (Id, Salary) values ('1', '100');
insert into Employee (Id, Salary) values ('2', '200');
insert into Employee (Id, Salary) values ('3', '300');
```
Write a SQL query to get the **Nth** highest salary from the Employee table.

```
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+
```
For example, given the above Employee table, the nth highest salary where n = 2 is 200. If there is no nth highest salary, then the query **should return null**.

```
+------------------------+
| getNthHighestSalary(2) |
+------------------------+
| 200                    |
+------------------------+
```

### SQL - 11 / 14 test cases passed
```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set N = N-1;
  RETURN (
    # Write your MySQL query statement below.
    select Salary from Employee
      order by Salary desc
      limit 1 offset N
  );
END
```

- failed case | should return **null** not 100 when input N = 2

```
+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 100    |
+----+--------+
```

### SQL - AC using `distinct`
- **Attention**: Do not miss the semicolon at the end of `set N = N -1`

```sql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set N = N-1;
  RETURN (
    # Write your MySQL query statement below.
    select distinct Salary from Employee
      order by Salary desc
      limit 1 offset N
  );
END
```