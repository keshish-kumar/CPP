# Write your MySQL query statement below

select  DISTINCT author_id as id from Views
where author_id = viewer_id order by id ASC;