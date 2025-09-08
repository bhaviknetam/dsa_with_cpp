SELECT DISTINCT num as ConsecutiveNums
FROM (
    SELECT num, 
    LAG(num, 1) OVER(ORDER BY id) as prev, 
    LEAD(num, 1) OVER(ORDER BY id) as next
    FROM Logs
) AS New_Logs
WHERE num = prev AND num = next