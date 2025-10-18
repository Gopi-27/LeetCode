/* Write your PL/SQL query statement below */
WITH cte AS(
    SELECT customer_id,MIN(order_date) AS first_ord
    FROM delivery
    GROUP BY customer_id
),cte1 AS (
    SELECT COUNT(*) AS cnt FROM
    cte c
    JOIN
    delivery d
    ON (c.customer_id = d.customer_id ) AND (d.customer_pref_delivery_date = c.first_ord)
),cte2 AS(
    SELECT COUNT(*) AS tot FROM cte
)SELECT ROUND((SELECT cnt FROM cte1)/(SELECT tot FROM cte2) * 100,2) AS immediate_percentage FROM dual;