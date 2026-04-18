/* Write your PL/SQL query statement below */


SELECT s.user_id AS user_id, ROUND(COUNT(CASE WHEN c.action = 'confirmed' THEN 1 END)/(COUNT(*)),2) AS confirmation_rate FROM
confirmations c
RIGHT JOIN
signups s
ON c.user_id = s.user_id
GROUP BY s.user_id;
