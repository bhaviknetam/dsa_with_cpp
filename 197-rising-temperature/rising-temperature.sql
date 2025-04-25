# Write your MySQL query statement below
SELECT w1.id
FROM Weather AS w1
JOIN Weather AS w2
ON DATE_ADD(w2.recordDate, INTERVAL 1 DAY) = w1.recordDate
WHERE w1.temperature > w2.temperature;