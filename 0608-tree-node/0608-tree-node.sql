/* Write your PL/SQL query statement below */

SELECT t.id,
CASE
    WHEN t.p_id IS NULL THEN 'Root'
    WHEN t.id IN (SELECT p.p_id FROM tree p) THEN 'Inner'
    ELSE 'Leaf'
END AS type
FROM tree t;

