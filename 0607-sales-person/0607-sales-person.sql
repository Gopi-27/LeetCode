/* Write your PL/SQL query statement below */


WITH cte AS(
    SELECT o.sales_id AS id FROM
    orders o
    JOIN  
    company c
    ON o.com_id = c.com_id
    WHERE c.name = 'RED';
),cte2 AS(
    SELECT DISTINCT sales_id,name 
    FROM salesperson 
    WHERE sales_id NOT IN (
        SELECT id FROM cte
    )
)SELECT name FROM cte2;