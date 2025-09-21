
CREATE FUNCTION getNthHighestSalary(N IN NUMBER) RETURN NUMBER IS
result NUMBER;
BEGIN
    /* Write your PL/SQL query statement below */
    WITH cte1 AS(
        SELECT DISTINCT salary FROM employee
    ),
    cte2 AS(
        SELECT salary,
        RANK() OVER(ORDER BY salary DESC) AS rnk
        FROM cte1
    )
    SELECT salary INTO result FROM cte2 WHERE rnk = N;

    RETURN result;
END;