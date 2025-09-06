/* Write your PL/SQL query statement below */


WITH cte AS
    (
    SELECT person_id,person_name,weight,turn,
    SUM(weight) OVER(ORDER BY turn) AS run_weight
    FROM queue
    )
SELECT person_name
FROM cte
WHERE run_weight = (SELECT MAX(run_weight) FROM cte WHERE run_weight <= 1000);