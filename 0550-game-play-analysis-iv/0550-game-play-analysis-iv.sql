/* Write your PL/SQL query statement below */


WITH cte AS(
    SELECT player_id AS id, MIN(event_date) AS edt
    FROM activity
    GROUP BY player_id
),cte2 AS(
    SELECT id FROM
    cte
    WHERE (id,edt + 1) IN (SELECT player_id,event_date FROM activity);
) SELECT ROUND((SELECT COUNT(id) FROM cte2)/(SELECT COUNT(id) FROM cte),2) AS fraction FROM dual;
