## Employees Earning More Than Their Managers

### Illustrate
<https://leetcode.com/problems/employees-earning-more-than-their-managers/>

### Schema
use

```sql
Create table If Not Exists Employee (Id int, Name varchar(255), Salary int, ManagerId int);
Truncate table Employee;
insert into Employee (Id, Name, Salary, ManagerId) values ('1', 'Joe', '70000', '3');
insert into Employee (Id, Name, Salary, ManagerId) values ('2', 'Henry', '80000', '4');
insert into Employee (Id, Name, Salary, ManagerId) values ('3', 'Sam', '60000', '0');
insert into Employee (Id, Name, Salary, ManagerId) values ('4', 'Max', '90000', '0');
```

instead of (**ERROR: invalid input syntax for integer: "None"**)

```sql
Create table If Not Exists Employee (Id int, Name varchar(255), Salary int, ManagerId int);
Truncate table Employee;
insert into Employee (Id, Name, Salary, ManagerId) values ('1', 'Joe', '70000', '3');
insert into Employee (Id, Name, Salary, ManagerId) values ('2', 'Henry', '80000', '4');
insert into Employee (Id, Name, Salary, ManagerId) values ('3', 'Sam', '60000', 'None');
insert into Employee (Id, Name, Salary, ManagerId) values ('4', 'Max', '90000', 'None');
```

The `Employee` table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.

```
+----+-------+--------+-----------+
| Id | Name  | Salary | ManagerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | NULL      |
| 4  | Max   | 90000  | NULL      |
+----+-------+--------+-----------+
```
Given the Employee table, write a SQL query that finds out employees who earn more than their managers. For the above table, Joe is the only employee who earns more than his manager.

```
+----------+
| Employee |
+----------+
| Joe      |
+----------+
```

### Test - Inner Join
```sql
select *
from Employee as a
  inner join Employee as b
  on a.ManagerId = b.Id;
```

id	|name	|salary |managerid|	id	|name|salary| managerid
---|---|---|---|---|---|---|---
1|	Joe|	70000|	3|	3|	Sam|	60000|	0
2|	Henry|	80000|	4|	4|	Max|	90000|	0

### Test - inner Join
```sql
select *
from Employee as a
left join Employee as b
on a.ManagerId = b.Id;
```

id	|name	|salary |managerid|	id	|name|salary| managerid
---|---|---|---|---|---|---|---
1|	Joe	|70000	|3	|3	|Sam	|60000	|0
2|	Henry|	80000	|4	|4	|Max	|90000	|0

### SQL
```sql
# Write your MySQL query statement below
select E1.Name as Employee
from Employee as E1 inner join Employee as E2
on E1.ManagerId = E2.Id
where E1.Salary > E2.Salary;
```