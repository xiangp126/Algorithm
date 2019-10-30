## Rising Temperature
### Illustrate
<https://leetcode.com/problems/rising-temperature/>

<http://sqlfiddle.com/>

### Schema
```sql
Create table If Not Exists Weather (Id int, RecordDate date, Temperature int);
Truncate table Weather;
insert into Weather (Id, RecordDate, Temperature) values ('1', '2015-01-01', '10');
insert into Weather (Id, RecordDate, Temperature) values ('2', '2015-01-02', '25');
insert into Weather (Id, RecordDate, Temperature) values ('3', '2015-01-03', '20');
insert into Weather (Id, RecordDate, Temperature) values ('4', '2015-01-04', '30');
```

Given a `Weather` table, write a SQL query to find all dates' Ids with higher temperature compared to its previous (yesterday's) dates.

```
+---------+------------------+------------------+
| Id(INT) | RecordDate(DATE) | Temperature(INT) |
+---------+------------------+------------------+
|       1 |       2015-01-01 |               10 |
|       2 |       2015-01-02 |               25 |
|       3 |       2015-01-03 |               20 |
|       4 |       2015-01-04 |               30 |
+---------+------------------+------------------+
```
For example, return the following Ids for the above Weather table:

```
+----+
| Id |
+----+
|  2 |
|  4 |
+----+
```

### MySQL DATEDIFF Function
Return the number of days between two date values:

**This schema was only used for MySQL**

```sql
SELECT DATEDIFF("2017-06-25", "2017-06-15");
```

=> 10

### Test using `datediff`
```sql
datediff(wa.RecordDate, wb.RecordDate) = 1
```
=>&nbsp;2015-01-03(wa) = 2015-01-02(wb) + 1

```saq
select *
from Weather as wa
    left join Weather as wb
    on datediff(wa.RecordDate, wb.RecordDate) = 1
order by wa.RecordDate;
```

Id	|RecordDate|	Temperature|	Id|	RecordDate|	Temperature
---|---|---|:---:|:---:|:---:
1|	2015-01-01|	10|	(null)	|(null)|	(null)
2|	2015-01-02|	25|	1|2015-01-01|	10
3|	2015-01-03|	20|	2|2015-01-02	|25|
4|	2015-01-04|	30|	3|	2015-01-03|	20

### SQL
```sql
# Write your MySQL query statement below
select wa.Id
from Weather as wa
    left join Weather as wb
    on datediff(wa.RecordDate, wb.RecordDate) = 1
where wa.Temperature > wb.Temperature;
```