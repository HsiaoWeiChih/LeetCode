// Employee
with em as (
select e.*, m.salary as m_salary from (select * from Employee where managerId is not null) e
left join (select * from Employee) m
on e.managerId = m.id
)
select name as Employee from em
where salary > m_salary