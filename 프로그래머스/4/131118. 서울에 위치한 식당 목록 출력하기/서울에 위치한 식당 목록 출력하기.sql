-- 서울에 위치한 식당 ID, 식당 이름, 음식 종류, 즐겨찾기수, 주소, 리뷰 평균 점수를 조회
-- 리뷰 평균점수는 소수점 세 번째 자리에서 반올림 해주시고 
-- 결과는 평균점수를 기준으로 내림차순 정렬, 평균점수가 같다면 즐겨찾기수를 기준으로 내림차순 정렬
SELECT DISTINCT info.REST_ID, REST_NAME, FOOD_TYPE, FAVORITES, ADDRESS, ROUND(AVG(REVIEW_SCORE), 2) AS SCORE
FROM REST_REVIEW
JOIN REST_INFO info ON info.REST_ID = REST_REVIEW.REST_ID
GROUP BY info.REST_ID
HAVING info.ADDRESS LIKE '서울%'
ORDER BY SCORE DESC, FAVORITES DESC;