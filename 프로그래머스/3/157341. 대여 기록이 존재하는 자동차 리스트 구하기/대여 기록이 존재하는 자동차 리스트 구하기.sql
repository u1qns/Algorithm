-- '세단'인 자동차들 중 10월에 대여를 시작한 기록이 있는 자동차 ID 리스트를 출력
-- 자동차 ID 리스트는 중복이 없어야 하며, 자동차 ID를 기준으로 내림차순
SELECT DISTINCT(c.CAR_ID)
FROM CAR_RENTAL_COMPANY_CAR c JOIN CAR_RENTAL_COMPANY_RENTAL_HISTORY h
    ON c.CAR_ID = h.CAR_ID AND 10 = MONTH(h.START_DATE) AND CAR_TYPE ='세단'
ORDER BY c.CAR_ID DESC;