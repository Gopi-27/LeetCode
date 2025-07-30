/* Write your PL/SQL query statement below */



SELECT e.name AS name,b.bonus AS bonus
FROM
employee e
LEFT JOIN
bonus b
ON e.empid = b.empid
WHERE b.bonus < 1000 OR b.bonus IS NULL;