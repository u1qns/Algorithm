-- 물고기 종류 별로 가장 큰 물고기의 ID, 물고기 이름, 길이를 출력
-- 물고기의 ID에 대해 오름차순 정렬

SELECT ID, FISH_NAME, LENGTH
FROM FISH_INFO i JOIN FISH_NAME_INFO ni 
    ON i.FISH_TYPE = ni.FISH_TYPE
WHERE (i.FISH_TYPE, i.LENGTH) IN 
    (
        SELECT FISH_TYPE, MAX(LENGTH)
        FROM FISH_INFO
        GROUP BY FISH_TYPE
    )
ORDER BY i.ID;