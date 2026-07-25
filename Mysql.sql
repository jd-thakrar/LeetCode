-- Eassy

-- 175. Combine Two Tables
select p.firstName, p.lastName, a.city, a.state 
from Person p left join Address a
on p.personId = a.personId;

-- 1148. Article Views I
select author_id as id 
from views 
where author_id = viewer_id 
Group by author_id 
Order by author_id;

-- 181. Employees Earning More Than Their Managers
select e.name as Employee 
from employee e 
inner join employee m 
on e.managerId = m.Id 
where e.salary > m.salary;

-- 183. Customers Who Never Order
select name AS Customers 
from Customers c 
left outer join Orders o 
on c.id = o.customerId 
where customerId is null