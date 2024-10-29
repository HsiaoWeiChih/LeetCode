select * from Customers
where id not in (select customerId from Orders)