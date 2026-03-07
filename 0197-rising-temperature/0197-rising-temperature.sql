/* Write your PL/SQL query statement below */


SELECT w.id
FROM weather w
WHERE w.temperature > (
                        SELECT t.temperature
                        FROM weather t 
                        WHERE t.recorddate = w.recorddate - 1
                    );