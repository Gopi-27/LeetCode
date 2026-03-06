/* Write your PL/SQL query statement below */

WITH cte AS(
    SELECT p.product_id AS id,p.product_name AS name
    FROM
    sales s
    JOIN
    product p
    ON s.product_id = p.product_id
    WHERE s.sale_date < '2019-01-01' OR s.sale_date > '2019-03-31'
)SELECT DISTINCT product_id,product_name
FROM product
WHERE (product_id,product_name) NOT IN (SELECT id,name FROM cte) AND
product_id IN (SELECT product_id FROM sales);