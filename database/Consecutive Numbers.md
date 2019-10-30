## Consecutive Numbers
### Illustrate
<https://leetcode.com/problems/consecutive-numbers/>

### Schema
```sql
Create table If Not Exists Logs (Id int, Num int);
Truncate table Logs;
insert into Logs (Id, Num) values ('1', '1');
insert into Logs (Id, Num) values ('2', '1');
insert into Logs (Id, Num) values ('3', '1');
insert into Logs (Id, Num) values ('4', '2');
insert into Logs (Id, Num) values ('5', '1');
insert into Logs (Id, Num) values ('6', '2');
insert into Logs (Id, Num) values ('7', '2');
```

Write a SQL query to find all numbers that appear at least three times consecutively.

```
+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+
```
For example, given the above Logs table, 1 is the only number that appears consecutively for at least three times.

```
+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+
```

### SQL - Let's Warm Up
```sql
select *
from Logs as l1
  inner join Logs as l2
  inner join Logs as l3
on l2.Id = l1.Id + 1
  and l3.Id = l2.Id + 1
```

output is

```
| Id | Num | Id | Num | Id | Num |
|----|-----|----|-----|----|-----|
|  1 |   1 |  2 |   1 |  3 |   1 |
|  2 |   1 |  3 |   1 |  4 |   2 |
|  3 |   1 |  4 |   2 |  5 |   1 |
|  4 |   2 |  5 |   1 |  6 |   2 |
|  5 |   1 |  6 |   2 |  7 |   2 |
```

go on


```sql
# Warning: don't write as `l1.Num = l2.Num = l3.Num`
select *
from Logs as l1
  inner join Logs as l2
  inner join Logs as l3
on l2.Id = l1.Id + 1
  and l3.Id = l2.Id + 1
  and l1.Num = l2.Num
  and l2.Num = l3.Num
```

output is

```
| Id | Num | Id | Num | Id | Num |
|----|-----|----|-----|----|-----|
|  1 |   1 |  2 |   1 |  3 |   1 |
```

### SQL - 17 / 21 test cases passed
failed case:

```sql
Create table If Not Exists Logs (Id int, Num int);
Truncate table Logs;
insert into Logs (Id, Num) values ('1', '3');
insert into Logs (Id, Num) values ('2', '3');
insert into Logs (Id, Num) values ('3', '3');
insert into Logs (Id, Num) values ('4', '3');
```

looks like:

```
| Id | Num |
|----|-----|
|  1 |   3 |
|  2 |   3 |
|  3 |   3 |
|  4 |   3 |
```

```sql
select l1.Num as ConsecutiveNums
from Logs as l1
  inner join Logs as l2
  inner join Logs as l3
on l2.Id = l1.Id + 1
  and l3.Id = l2.Id + 1
  and l1.Num = l2.Num
  and l2.Num = l3.Num
```

output is

```
| ConsecutiveNums |
|-----------------|
|               3 |
|               3 |
```

### SQL - AC using `distinct`
```sql
select distinct l1.Num as ConsecutiveNums
from Logs as l1
  inner join Logs as l2
  inner join Logs as l3
on l2.Id = l1.Id + 1
  and l3.Id = l2.Id + 1
  and l1.Num = l2.Num
  and l2.Num = l3.Num
```

output is

```
| ConsecutiveNums |
|-----------------|
|               3 |
```

### SQL - AC implicit use `inner join`
If you use `inner join/on` implicit, you should use `where` clause instean of `on`

```sql
select distinct l1.Num as ConsecutiveNums
from Logs l1,
  Logs l2,
  Logs l3
where l2.Id = l1.Id + 1
  and l3.Id = l2.Id + 1
  and l1.Num = l2.Num
  and l2.Num = l3.Num
```