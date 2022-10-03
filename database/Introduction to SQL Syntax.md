## Introduction to SQL Syntax
### Online Learning Website
- <http://sqlfiddle.com/>
- <https://sqlbolt.com/>
- <http://www.w3school.com.cn/sql/>
- <https://www.codecademy.com/learn/learn-sql>
- <https://www.codecademy.com/learn/sql-table-transformation>
- <http://www.w3resource.com/sql-exercises/>
- <https://www.tutorialspoint.com/hive/>
- <http://www.sql-ex.ru/>

### SQL Execution Order
```sql
SELECT DISTINCT <select_list>
FROM <left_table>
<join_type> JOIN <right_table>
ON <join_condition>
WHERE <where_condition>
GROUP BY <group_by_list>
HAVING <having_condition>
ORDER BY <order_by_condition>
LIMIT <limit_number>
```

### SQL Keyword
- SQL Schema

```sql
Create table If Not Exists Person (personId int, firstName varchar(255), lastName varchar(255));
Create table If Not Exists Address (addressId int, personId int, city varchar(255), state varchar(255));
Truncate table Person;
insert into Person (personId, lastName, firstName) values ('1', 'Wang', 'Allen');
insert into Person (personId, lastName, firstName) values ('2', 'Alice', 'Bob');
Truncate table Address;
insert into Address (addressId, personId, city, state) values ('1', '2', 'New York City', 'New York');
insert into Address (addressId, personId, city, state) values ('2', '3', 'Leetcode', 'California');
```

- `Person` table

personId | firstName | lastName
---|---|---
1| Allen | Wang
2|Bob|Alice

- `Address` table

addressId|personId|city|state
---|---|---|---
1|2|New York City|New York
2|3|Leetcode|California

#### [INNER JOIN](https://www.w3schools.com/sql/sql_join_inner.asp)
The INNER JOIN keyword selects records that have matching values in both tables.

<div align=left><img src="./res/inner_join.png" width=90%></div>

personId|firstName|lastName|addressId|personId|city|state
---|---|---|---|---|---|---
2|Bob|Alice|1|2|New York City|New York

#### [LEFT JOIN](https://www.w3schools.com/sql/sql_join_left.asp)
The LEFT JOIN keyword returns all records from the left table (table1), and the matched records from the right table (table2). The result is NULL from the right side, if there is no match.

<div align=left><img src="./res/left_join.png" width=90%></div>

personId|firstName|lastName|addressId|personId|city|state
---|---|---|---|---|---|---
2|Bob|Alice|1|2|New York City|New York
1	|Allen	|Wang|	(null)	|(null)|	(null) |	(null)

#### [RIGHT JOIN](https://www.w3schools.com/sql/sql_join_right.asp)
The RIGHT JOIN keyword returns all records from the right table (table2), and the matching records from the left table (table1). The result is 0 records from the left side, if there is no match.

<div align=center><img src="./res/right_join.png" width=35%></div>

personId|firstName|lastName|addressId|personId|city|state
---|---|---|---|---|---|---
2|Bob|Alice|1|2|New York City|New York
(null)	|(null)|	(null)|	2|	3|	Leetcode|	California