/* Write your PL/SQL query statement below */



SELECT u.user_id AS buyer_id, TO_CHAR(u.join_date,'YYYY-MM-DD') AS join_date,
COUNT(CASE WHEN TO_CHAR(o.order_date,'YYYY') = '2019' THEN 1 END) AS orders_in_2019
FROM
orders o
RIGHT JOIN
users u 
ON o.buyer_id = u.user_id
GROUP BY u.user_id,u.join_date;