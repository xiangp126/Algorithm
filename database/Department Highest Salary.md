## Department Highest Salary
### Illustrate
<https://leetcode.com/problems/department-highest-salary/>

### Schema
```sql
Create table If Not Exists Employee (Id int, Name varchar(255), Salary int, DepartmentId int);
Create table If Not Exists Department (Id int, Name varchar(255));
Truncate table Employee;
insert into Employee (Id, Name, Salary, DepartmentId) values ('1', 'Joe', '70000', '1');
insert into Employee (Id, Name, Salary, DepartmentId) values ('2', 'Jim', '90000', '1');
insert into Employee (Id, Name, Salary, DepartmentId) values ('3', 'Henry', '80000', '2');
insert into Employee (Id, Name, Salary, DepartmentId) values ('4', 'Sam', '60000', '2');
insert into Employee (Id, Name, Salary, DepartmentId) values ('5', 'Max', '90000', '1');
Truncate table Department;
insert into Department (Id, Name) values ('1', 'IT');
insert into Department (Id, Name) values ('2', 'Sales');
```

The Employee table holds all employees. Every employee has an Id, a salary, and there is also a column for the department Id.

```
+----+-------+--------+--------------+
| Id | Name  | Salary | DepartmentId |
+----+-------+--------+--------------+
| 1  | Joe   | 70000  | 1            |
| 2  | Jim   | 90000  | 1            |
| 3  | Henry | 80000  | 2            |
| 4  | Sam   | 60000  | 2            |
| 5  | Max   | 90000  | 1            |
+----+-------+--------+--------------+
```
The Department table holds all departments of the company.

```
+----+----------+
| Id | Name     |
+----+----------+
| 1  | IT       |
| 2  | Sales    |
+----+----------+
```
Write a SQL query to find employees who have the highest salary in each of the departments. For the above tables, your SQL query should return the following rows (order of rows does not matter).

```
+------------+----------+--------+
| Department | Employee | Salary |
+------------+----------+--------+
| IT         | Max      | 90000  |
| IT         | Jim      | 90000  |
| Sales      | Henry    | 80000  |
+------------+----------+--------+
```
Explanation:

Max and Jim both have the highest salary in the IT department and Henry has the highest salary in the Sales department.

### SQL - Let's Warm Up
- Step 1

```sql
select DepartmentId, max(Salary)
from Employee
group by DepartmentId
```

output is

```
| DepartmentId | max(Salary) |
|--------------|-------------|
|            1 |       90000 |
|            2 |       80000 |
```

- Step 2

```sql
select dep.Name as Department,
  emp.Name as Employee, Salary
from Employee as emp,
  Department as dep
where emp.DepartmentId = dep.Id
```

output is

```
| Department | Employee | Salary |
|------------|----------|--------|
|         IT |      Joe |  70000 |
|         IT |      Jim |  90000 |
|      Sales |    Henry |  80000 |
|      Sales |      Sam |  60000 |
|         IT |      Max |  90000 |
```

- Step 3

Combine these two queries we get

```sql
select dep.Name as Department,
    emp.Name as Employee, Salary
from Employee as emp, Department as dep
where emp.DepartmentId = dep.Id
and (emp.DepartmentId, Salary)
in
(
  select DepartmentId, max(Salary)
  from Employee
  group by DepartmentId
)
```

output is

```
| Department | Employee | Salary |
|------------|----------|--------|
|         IT |      Jim |  90000 |
|      Sales |    Henry |  80000 |
|         IT |      Max |  90000 |
```

### SQL - AC
```sql
select dep.Name as Department,
    emp.Name as Employee, Salary
from Employee as emp, Department as dep
where emp.DepartmentId = dep.Id
    and (emp.DepartmentId, Salary)
    in (
        select DepartmentId, max(Salary)
        from Employee
        group by DepartmentId
    )
order by Department;
```

output is

```
| Department | Employee | Salary |
|------------|----------|--------|
|         IT |      Jim |  90000 |
|         IT |      Max |  90000 |
|      Sales |    Henry |  80000 |
```

or use `inner join` explicitly

```sql
select dep.Name as Department,
    emp.Name as Employee, Salary
from Employee as emp
inner join Department as dep
on emp.DepartmentId = dep.Id
where (emp.DepartmentId, Salary)
in (
    select DepartmentId, max(Salary)
    from Employee
    group by DepartmentId
)
order by Department;
```
