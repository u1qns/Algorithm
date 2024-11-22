-- 코드를 입력하세요
SELECT * 
from places 
where host_id IN (
    select host_id
    from places
    group by host_id
    having count(*) > 1)
order by id;
