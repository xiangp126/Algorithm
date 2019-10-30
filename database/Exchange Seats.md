## Exchange Seats
### Illustrate
<https://leetcode.com/problems/exchange-seats/>

### Schema
```sql
Create table If Not Exists seat(id int, student varchar(255));
Truncate table seat;
insert into seat (id, student) values ('1', 'Abbot');
insert into seat (id, student) values ('2', 'Doris');
insert into seat (id, student) values ('3', 'Emerson');
insert into seat (id, student) values ('4', 'Green');
insert into seat (id, student) values ('5', 'Jeames');
```

Mary is a teacher in a middle school and she has a table seat storing students' names and their corresponding seat ids.

The column **id** is continuous increment.


Mary wants to change seats for the adjacent students.


Can you write a SQL query to output the result for Mary?

```
+---------+---------+
|    id   | student |
+---------+---------+
|    1    | Abbot   |
|    2    | Doris   |
|    3    | Emerson |
|    4    | Green   |
|    5    | Jeames  |
+---------+---------+
```
For the sample input, the output is:

```
+---------+---------+
|    id   | student |
+---------+---------+
|    1    | Doris   |
|    2    | Abbot   |
|    3    | Green   |
|    4    | Emerson |
|    5    | Jeames  |
+---------+---------+
```
Note:
If the number of students is odd, there is no need to change the last one's seat.

### SQL - warm up

There are 3 cases

- For students with even-numbered ids, subtract 1 from their id
- For students with odd-numbered ids, add 1 to their id (Except if this odd-numbered student has the highest id in the class
- For student with odd-numbered id who also has the highest id in the class, don't change the id.

```sql
# Write your MySQL query statement below
select
(
  case
    when mod(id, 2) = 0 then id - 1
    when mod(id, 2) = 1 and id != (select max(id) from seat) then id + 1
    else id
  end
) as id, student
from seat
```

output is

```
| id | student |
|----|---------|
|  2 |   Abbot |
|  1 |   Doris |
|  4 | Emerson |
|  3 |   Green |
|  5 |  Jeames |
```

### SQL - AC
```sql
# Write your MySQL query statement below
select
(
  case
    when mod(id, 2) = 0 then id - 1
    when mod(id, 2) = 1 and id != (select max(id) from seat) then id + 1
    else id
  end
) as id, student
from seat
order by id
```

output is

```
| id | student |
|----|---------|
|  1 |   Doris |
|  2 |   Abbot |
|  3 |   Green |
|  4 | Emerson |
|  5 |  Jeames |
```