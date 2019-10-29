## Reformat Department Table
### Illustrate
<https://leetcode.com/problems/reformat-department-table/>

### Schema
```sql
Create table If Not Exists Department (id int, revenue int, month varchar(5));
Truncate table Department;
insert into Department (id, revenue, month) values ('1', '8000', 'Jan');
insert into Department (id, revenue, month) values ('2', '9000', 'Jan');
insert into Department (id, revenue, month) values ('3', '10000', 'Feb');
insert into Department (id, revenue, month) values ('1', '7000', 'Feb');
insert into Department (id, revenue, month) values ('1', '6000', 'Mar');
```

Table: Department

```
+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| id            | int     |
| revenue       | int     |
| month         | varchar |
+---------------+---------+
```

`(id, month)` is the primary key of this table.
The table has information about the revenue of each department per month.
The month has values in ["Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"].

Write an SQL query to reformat the table such that there is a department id column and a revenue column **for each month**.

The query result format is in the following example:

Department table:

```
+------+---------+-------+
| id   | revenue | month |
+------+---------+-------+
| 1    | 8000    | Jan   |
| 2    | 9000    | Jan   |
| 3    | 10000   | Feb   |
| 1    | 7000    | Feb   |
| 1    | 6000    | Mar   |
+------+---------+-------+
```

Result table:

```
+------+-------------+-------------+-------------+-----+-------------+
| id   | Jan_Revenue | Feb_Revenue | Mar_Revenue | ... | Dec_Revenue |
+------+-------------+-------------+-------------+-----+-------------+
| 1    | 8000        | 7000        | 6000        | ... | null        |
| 2    | 9000        | null        | null        | ... | null        |
| 3    | null        | 10000       | null        | ... | null        |
+------+-------------+-------------+-------------+-----+-------------+
```

Note that the result table has 13 columns (1 for the department id + 12 for the months).

### SQL - IF
```sql
select id,
  max(if(month = 'Jan', revenue, null)) as 'Jan_Revenue',
  max(if(month = 'Feb', revenue, null)) as 'Feb_Revenue',
  max(if(month = 'Mar', revenue, null)) as 'Mar_Revenue',
  max(if(month = 'Apr', revenue, null)) as 'Apr_Revenue',
  max(if(month = 'May', revenue, null)) as 'May_Revenue',
  max(if(month = 'Jun', revenue, null)) as 'Jun_Revenue',
  max(if(month = 'Jul', revenue, null)) as 'Jul_Revenue',
  max(if(month = 'Aug', revenue, null)) as 'Aug_Revenue',
  max(if(month = 'Sep', revenue, null)) as 'Sep_Revenue',
  max(if(month = 'Oct', revenue, null)) as 'Oct_Revenue',
  max(if(month = 'Nov', revenue, null)) as 'Nov_Revenue',
  max(if(month = 'Dec', revenue, null)) as 'Dec_Revenue'
from Department
group by id
order by id
```

### SQL - CASE

`case - then - else - end`

```sql
select id,
  max(case when month = 'Jan' then revenue else null end) as 'Jan_Revenue',
  max(case when month = 'Feb' then revenue else null end) as 'Feb_Revenue',
  max(case when month = 'Mar' then revenue else null end) as 'Mar_Revenue',
  max(case when month = 'Apr' then revenue else null end) as 'Apr_Revenue',
  max(case when month = 'May' then revenue else null end) as 'May_Revenue',
  max(case when month = 'Jun' then revenue else null end) as 'Jun_Revenue',
  max(case when month = 'Jul' then revenue else null end) as 'Jul_Revenue',
  max(case when month = 'Aug' then revenue else null end) as 'Aug_Revenue',
  max(case when month = 'Sep' then revenue else null end) as 'Sep_Revenue',
  max(case when month = 'Oct' then revenue else null end) as 'Oct_Revenue',
  max(case when month = 'Nov' then revenue else null end) as 'Nov_Revenue',
  max(case when month = 'Dec' then revenue else null end) as 'Dec_Revenue'
from Department
group by id
order by id
```

### Thought & Explain
- without `group by` and `max`

if you do not use `group by` with some functions like `sum`, `max` or `min`

```sql
select id,
  (if(month = 'Jan', revenue, null)) as 'Jan_Revenue',
  (if(month = 'Feb', revenue, null)) as 'Feb_Revenue',
  (if(month = 'Mar', revenue, null)) as 'Mar_Revenue',
  (if(month = 'Apr', revenue, null)) as 'Apr_Revenue',
  (if(month = 'May', revenue, null)) as 'May_Revenue',
  (if(month = 'Jun', revenue, null)) as 'Jun_Revenue',
  (if(month = 'Jul', revenue, null)) as 'Jul_Revenue',
  (if(month = 'Aug', revenue, null)) as 'Aug_Revenue',
  (if(month = 'Sep', revenue, null)) as 'Sep_Revenue',
  (if(month = 'Oct', revenue, null)) as 'Oct_Revenue',
  (if(month = 'Nov', revenue, null)) as 'Nov_Revenue',
  (if(month = 'Dec', revenue, null)) as 'Dec_Revenue'
from Department
# group by id
order by id
```

the result of above SQL query will be like this

```
id	Jan_Revenue	Feb_Revenue	Mar_Revenue	Apr_Revenue	May_Revenue	Jun_Revenue	Jul_Revenue	Aug_Revenue	Sep_Revenue	Oct_Revenue	Nov_Revenue	Dec_Revenue
1	8000	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)
1	(null)	7000	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)
1	(null)	(null)	6000	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)
2	9000	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)
3	(null)	10000	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)
```

notice `when id = 1`

- use `group by` without `max`

```sql
select id,
  (if(month = 'Jan', revenue, null)) as 'Jan_Revenue',
  (if(month = 'Feb', revenue, null)) as 'Feb_Revenue',
  (if(month = 'Mar', revenue, null)) as 'Mar_Revenue',
  (if(month = 'Apr', revenue, null)) as 'Apr_Revenue',
  (if(month = 'May', revenue, null)) as 'May_Revenue',
  (if(month = 'Jun', revenue, null)) as 'Jun_Revenue',
  (if(month = 'Jul', revenue, null)) as 'Jul_Revenue',
  (if(month = 'Aug', revenue, null)) as 'Aug_Revenue',
  (if(month = 'Sep', revenue, null)) as 'Sep_Revenue',
  (if(month = 'Oct', revenue, null)) as 'Oct_Revenue',
  (if(month = 'Nov', revenue, null)) as 'Nov_Revenue',
  (if(month = 'Dec', revenue, null)) as 'Dec_Revenue'
from Department
group by id
order by id
```

the result is

```
id	Jan_Revenue	Feb_Revenue	Mar_Revenue	Apr_Revenue	May_Revenue	Jun_Revenue	Jul_Revenue	Aug_Revenue	Sep_Revenue	Oct_Revenue	Nov_Revenue	Dec_Revenue
1	8000	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)
2	9000	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)
3	(null)	10000	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)	(null)
```

considering these results, you may find where the point is!