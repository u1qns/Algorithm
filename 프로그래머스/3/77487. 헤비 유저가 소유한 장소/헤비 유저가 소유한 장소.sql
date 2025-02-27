select ID, NAME, HOST_ID
FROM places
WHERE host_id IN (
    select host_id
    from places
    group by host_id
    having count(*) > 1
)
order by id;