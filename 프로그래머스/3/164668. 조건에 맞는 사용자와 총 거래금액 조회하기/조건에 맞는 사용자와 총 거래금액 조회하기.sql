-- 코드를 입력하세요
SELECT writer_id as user_id, u.nickname, sum(price) as total_sales
FROM USED_GOODS_BOARD b left join USED_GOODS_USER u
    ON b.writer_id = u.user_id
WHERE status='DONE'
GROUP BY writer_id
HAVING SUM(PRICE) >= 700000
ORDER BY SUM(PRICE)