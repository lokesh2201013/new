# Write your MySQL query statement below
select Person.firstName,Person.lastName,Address.city,Address.state
From Person LEFT OUTER join Address on Person.personId=Address.personId