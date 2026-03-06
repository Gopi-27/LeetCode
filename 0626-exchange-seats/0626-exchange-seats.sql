/* Write your PL/SQL query statement below */


WITH cnt AS(
    SELECT COUNT(*) AS cntu FROM seat
),
cte AS(
    SELECT student, CASE WHEN MOD(id,2) = 0 THEN id - 1 WHEN id = (SELECT cntu FROM cnt) THEN id ELSE id + 1 END AS id
    FROM seat 
)
SELECT id, student
FROM cte
ORDER BY id;