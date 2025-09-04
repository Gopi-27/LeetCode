/* Write your PL/SQL query statement below */



-- WITH cte1 AS (
--     SELECT requester_id As id,COUNT(*) AS cnt
--     FROM
--     requestAccepted
--     GROUP BY 
--     requester_id
-- ),
-- cte2 AS (
--     SELECT accepter_id AS id,COUNT(*) AS cnt
--     FROM
--     requestaccepted
--     GROUP BY 
--     accepter_id
-- )

-- SE
-- cte1 c1
-- FULL JOIN
-- cte2 c2
-- c1.id = c2.id;


WITH cte1 AS(
    SELECT requester_id AS id FROM requestaccepted
    UNION ALL
    SELECT accepter_id AS id FROM requestaccepted),
cte2 AS (
    SELECT id,COUNT(*) AS cnt 
    FROM
    cte1
    GROUP BY id
)

SELECT id, cnt AS num FROM cte2 WHERE
 cnt = (SELECT MAX(cnt) FROM cte2);

