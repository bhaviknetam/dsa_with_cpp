SELECT d.name as Department, e.name as Employee, e.salary as Salary
FROM (
    SELECT *,
    DENSE_RANK() OVER(PARTITION BY departmentId ORDER BY salary DESC) as s_rank
    FROM Employee
) e
JOIN Department d
ON e.departmentId = d.id
WHERE e.s_rank <= 3;