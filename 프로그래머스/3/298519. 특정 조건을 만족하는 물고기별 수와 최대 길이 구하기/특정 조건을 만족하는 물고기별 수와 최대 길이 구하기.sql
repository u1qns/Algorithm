-- 평균 길이가 33cm 이상인 물고기들을 종류별로 분류
-- 잡은 수, 최대 길이, 물고기 종류
-- 물고기 종류에 대해 오름차순으로 정렬해주시고, 10cm이하의 물고기들은 10cm로 취급하여 평균 길이

SELECT COUNT(ID) AS FISH_COUNT, MAX(IFNULL(LENGTH, 10)) AS MAX_LENGTH, FISH_TYPE
FROM FISH_INFO
GROUP BY FISH_TYPE
HAVING AVG(IFNULL(LENGTH, 10)) >= 33
ORDER BY FISH_TYPE