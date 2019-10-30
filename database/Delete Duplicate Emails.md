## Delete Duplicate Emails
### Illustrate
<https://leetcode.com/problems/delete-duplicate-emails/>

### Schema
```sql
Create table If Not Exists Person (Id int, Email varchar(255));
Truncate table Person;
insert into Person (Id, Email) values ('1', 'john@example.com');
insert into Person (Id, Email) values ('2', 'bob@example.com');
insert into Person (Id, Email) values ('3', 'john@example.com');
insert into Person (Id, Email) values ('4', 'john@example.com');
```
Write a SQL query to delete all duplicate email entries in a table named `Person`, keeping only unique emails based on its smallest Id.

```
+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
| 3  | john@example.com |
| 4  | john@example.com |
+----+------------------+
```
Id is the primary key column for this table.
For example, after running your query, the above Person table should have the following rows:

```
+----+------------------+
| Id | Email            |
+----+------------------+
| 1  | john@example.com |
| 2  | bob@example.com  |
+----+------------------+
```
Note:

Your output is the whole Person table after executing your sql. Use delete statement.

### Test - Step 1
```sql
select *
from Person as p1
  inner join Person as p2
  on p1.Email = p2.Email
order by p1.Id;
```

Total items = 3(dups) * 3 + 1

Id	|Email	|Id	|Email
---|---|---|---
1| 	john@example.com| 	1|	john@example.com
1| 	john@example.com| 	3|	john@example.com
1| 	john@example.com| 	4|	john@example.com
2| 	bob@example.com |   2|	bob@example.com
3| 	john@example.com| 	1|	john@example.com
3| 	john@example.com| 	3|	john@example.com
3| 	john@example.com| 	4|	john@example.com
4| 	john@example.com| 	1|	john@example.com
4| 	john@example.com| 	3|	john@example.com
4| 	john@example.com| 	4|	john@example.com

### Test - Step 2
```sql
select *
from Person as p1
  inner join Person as p2
  on p1.Email = p2.Email and p1.Id > p2.Id;
```

Output: there's Id duplicates

Id	|Email	|Id	|Email
---|---|---|---
3|	john@example.com	|1|	john@example.com
4|	john@example.com	|1|	john@example.com
4|	john@example.com	|3|	john@example.com

### Test - Step 3
```sql
select * 
from Person as p1
  inner join Person as p2
  on p1.Email = p2.Email and p1.Id > p2.Id
 group by p1.Id;
```

Id	|Email	|Id	|Email
---|---|---|---
3|	john@example.com	|1|	john@example.com
4|	john@example.com	|1|	john@example.com

### SQL - Solution
```sql
# Write your MySQL query statement below
delete p1 
from Person as p1
  inner join Person as p2
  on p1.Email = p2.Email and p1.Id > p2.Id;
```