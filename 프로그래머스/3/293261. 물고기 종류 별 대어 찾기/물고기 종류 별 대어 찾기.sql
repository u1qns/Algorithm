-- 물고기 종류 별로 가장 큰 물고기의 ID, 물고기 이름, 길이를 출력
-- 물고기의 ID에 대해 오름차순 정렬해주세요.

    
SELECT ID, FISH_NAME, i.LENGTH
FROM FISH_INFO i JOIN  (
    SELECT FISH_TYPE, MAX(LENGTH) AS LENGTH
    FROM FISH_INFO i
    GROUP BY FISH_TYPE
) tmp 
 ON (i.FISH_TYPE, i.LENGTH) = (tmp.FISH_TYPE, tmp.LENGTH)

JOIN FISH_NAME_INFO n ON i.FISH_TYPE = n.FISH_TYPE
ORDER BY ID
