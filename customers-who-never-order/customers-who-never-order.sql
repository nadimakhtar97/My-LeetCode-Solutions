# Write your MySQL query statement below



# SELECT c.Name AS Customers FROM Customers c LEFT OUTER JOIN Orders o ON c.Id=o.CustomerId WHERE O.Id IS NULL;

SELECT Name Customers FROM Customers WHERE Id NOT IN (SELECT CustomerId From Orders);

