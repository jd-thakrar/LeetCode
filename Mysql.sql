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
