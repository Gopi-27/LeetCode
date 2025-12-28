/* Write your PL/SQL query statement below */
WITH cte1 AS(
    SELECT u.name AS name,COUNT(*) AS cnt,RANK() OVER(ORDER BY COUNT(*) DESC,name ASC) AS rnk
    FROM
    movierating m
    JOIN
    users u
    ON m.user_id = u.user_id
    GROUP BY u.user_id,u.name
),
cte2 AS(
    SELECT m.title AS title,AVG(rating) avrg,RANK() OVER(ORDER BY AVG(rating) DESC,m.title ASC) AS rnk
    FROM
    movies m
    JOIN
    movierating mr
    ON m.movie_id = mr.movie_id
    WHERE mr.created_at >= '2020-2-01' AND mr.created_at <= '2020-02-29'
    GROUP BY m.movie_id,m.title
)
SELECT name AS results FROM cte1 WHERE rnk = 1;
UNION ALL
SELECT title FROM cte2 WHERE rnk = 1;


