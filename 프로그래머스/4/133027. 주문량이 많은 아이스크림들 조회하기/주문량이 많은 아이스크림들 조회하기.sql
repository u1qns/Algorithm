-- 7월 아이스크림 총 주문량과 상반기의 아이스크림 총 주문량을 더한 값이 
-- 큰 순서대로 상위 3개의 맛을 조회


-- 7월 아이스크림 총 주문량은 
SELECT july.FLAVOR
FROM JULY july 
    JOIN FIRST_HALF fh
    ON july.FLAVOR = fh.FLAVOR
GROUP BY FLAVOR
ORDER BY (SUM(july.TOTAL_ORDER) + SUM(fh.TOTAL_ORDER)) DESC
LIMIT 3
