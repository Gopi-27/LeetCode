/* Write your PL/SQL query statement below */

SELECT d.name AS department,e.name AS employee,e.salary AS salary
FROM
employee e
JOIN
department d
ON e.departmentid = d.id
WHERE (d.name,salary) IN
(SELECT d.name,MAX(e.salary)
FROM
employee e
JOIN
department d
ON e.departmentid = d.id
GROUP BY d.name
);