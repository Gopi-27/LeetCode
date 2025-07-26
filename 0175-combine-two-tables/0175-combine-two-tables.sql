/* Write your PL/SQL query statement below */
SELECT firstName,LastName,city,state FROM
Person p
LEFT JOIN
Address a
ON p.personId = a.personId;