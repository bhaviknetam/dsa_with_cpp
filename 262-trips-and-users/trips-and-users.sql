SELECT t.request_at as Day, 
    ROUND(SUM(t.status != 'completed')/COUNT(*), 2) as 'Cancellation Rate'
FROM Trips t 
INNER JOIN Users u1 ON t.client_id = u1.users_id AND u1.banned = "No" 
INNER JOIN Users u2 ON t.driver_id = u2.users_id AND u2.banned = 'No'
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at;