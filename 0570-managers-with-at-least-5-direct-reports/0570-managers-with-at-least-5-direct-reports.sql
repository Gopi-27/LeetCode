/* Write your PL/SQL query statement below */

-- WITH cte AS(
--     SELECT managerid, COUNT(*) AS cnt
--     FROM employee
--     GROUP BY managerid
-- )
SELECT name
FROM employee e
WHERE (
    SELECT COUNT(*) FROM employee m WHERE m.managerid = e.id
) >= 5;