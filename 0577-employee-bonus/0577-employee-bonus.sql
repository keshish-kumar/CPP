# Write your MySQL query statement below

select E.name , B.bonus from Employee as E left join  Bonus as B
on B.empID = E.empID where B.bonus<1000 or bonus is null 