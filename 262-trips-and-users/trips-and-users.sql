SELECT Day, ROUND( SUM(cancelled) / COUNT(cancelled), 2) as 'Cancellation Rate'
FROM ( 
    SELECT t.request_at as Day, t.status != 'completed' as cancelled 
    FROM Trips t 
    INNER JOIN Users u1 ON t.client_id = u1.users_id AND u1.banned = "No" 
    INNER JOIN Users u2 ON t.driver_id = u2.users_id AND u2.banned = 'No'
    WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
) sub
GROUP BY Day
ORDER BY Day;