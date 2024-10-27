-- Person 
with cntMail as (
    select email, count(email) as cnt from Person group by email
)
select email from cntMail where cnt > 1