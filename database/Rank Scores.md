## Rank Scores
### Illustrate
<https://leetcode.com/problems/rank-scores/>

### Schema
```sql
Create table If Not Exists Scores (Id int, Score DECIMAL(3,2));
Truncate table Scores;
insert into Scores (Id, Score) values ('1', '3.5');
insert into Scores (Id, Score) values ('2', '3.65');
insert into Scores (Id, Score) values ('3', '4.0');
insert into Scores (Id, Score) values ('4', '3.85');
insert into Scores (Id, Score) values ('5', '4.0');
insert into Scores (Id, Score) values ('6', '3.65');
```

Write a SQL query to rank scores. If there is a tie between two scores, both should have the same ranking. Note that after a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no "holes" between ranks.

```
+----+-------+
| Id | Score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
```
For example, given the above Scores table, your query should generate the following report (order by highest score):

```
+-------+------+
| Score | Rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+
```

### SQL - AC using Double Select
To determine the ranking of a score, count the number of distinct scores that are >= to that score

```sql
# Write your MySQL query statement below
select Score,
  (
    select count(distinct s2.Score)
    from Scores as s2
    where s2.Score >= s1.Score
  ) as Rank
from Scores as s1
order by s1.Score desc
```

=>

```
| Score | Rank |
|-------|------|
|     4 |    1 |
|     4 |    1 |
|  3.85 |    2 |
|  3.65 |    3 |
|  3.65 |    3 |
|   3.5 |    4 |
```

### SQL - AC using Left Join [Warm Up]
To determine the ranking of a score, count the number of distinct scores that are >= to that score

```sql
select *
from Scores as s1
  left join Scores as s2
  on s2.Score >= s1.Score
order by s1.Id
```

output is

```
| Id | Score | Id | Score |
|----|-------|----|-------|
|  1 |   3.5 |  3 |     4 |
|  1 |   3.5 |  4 |  3.85 |
|  1 |   3.5 |  6 |  3.65 |
|  1 |   3.5 |  5 |     4 |
|  1 |   3.5 |  1 |   3.5 |
|  1 |   3.5 |  2 |  3.65 |
|  2 |  3.65 |  2 |  3.65 |
|  2 |  3.65 |  3 |     4 |
|  2 |  3.65 |  4 |  3.85 |
|  2 |  3.65 |  6 |  3.65 |
|  2 |  3.65 |  5 |     4 |
|  3 |     4 |  3 |     4 |
|  3 |     4 |  5 |     4 |
|  4 |  3.85 |  5 |     4 |
|  4 |  3.85 |  3 |     4 |
|  4 |  3.85 |  4 |  3.85 |
|  5 |     4 |  5 |     4 |
|  5 |     4 |  3 |     4 |
|  6 |  3.65 |  2 |  3.65 |
|  6 |  3.65 |  5 |     4 |
|  6 |  3.65 |  3 |     4 |
|  6 |  3.65 |  4 |  3.85 |
|  6 |  3.65 |  6 |  3.65 |
```

### SQL - AC using Left Join
```sql
select s1.Score, count(distinct s2.Score) as Rank
from Scores as s1
  left join Scores as s2
  on s2.Score >= s1.Score
group by s1.Id
order by s1.Score desc
```