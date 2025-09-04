/* Write your PL/SQL query statement below */


WITH cte AS
    (
        SELECT id, name, departmentid,salary,
        DENSE_RANK() OVER(PARTITION BY departmentid ORDER BY salary DESC) AS rnk
        FROM employee
    )
    SELECT d.name AS department,
        c.name AS employee,
        c.salary AS salary
    FROM
    cte c
    JOIN 
    department d
    ON c.departmentid = d.id
    WHERE c.rnk <= 3
    ;
