-- 자동차 종류가 '세단' 또는 'SUV' 인 자동차 중 
-- 2022년 11월 1일부터 2022년 11월 30일까지 대여 가능하고 30일간의 대여 금액이 50만원 이상 200만원 미만인 자동차에 대해서 
-- 자동차 ID, 자동차 종류, 대여 금액(컬럼명: FEE) 리스트

-- CAR_RENTAL_COMPANY_RENTAL_HISTORY에서 11-1부터 11-30일까지 대여되지 않은 CAR_ID 가져오기
-- CAR_RENTAL_COMPANY_CAR랑 ID 대조해서 종류 거르기 

# SELECT *
# FROM CAR_RENTAL_COMPANY_CAR
# WHERE 
#     car_id NOT IN (
#         SELECT CAR_ID
#         FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
#         WHERE END_DATE >= '2022-11-01'AND START_DATE <= '2022-11-30'
#     );

-- 거른 걸로 CAR_RENTAL_COMPANY_DISCOUNT_PLAN로 대여금액 계산해보기 그리고 출력

SELECT car.CAR_ID, car.CAR_TYPE, ROUND((DAILY_FEE * 30 * (100 - DISCOUNT_RATE) *0.01)) AS FEE
FROM CAR_RENTAL_COMPANY_CAR car JOIN CAR_RENTAL_COMPANY_DISCOUNT_PLAN plan
    ON car.CAR_TYPE = plan.CAR_TYPE -- 필요한건가?
WHERE car.CAR_TYPE IN ('SUV', '세단') AND 
       DURATION_TYPE = "30일 이상" AND 
        car.car_id NOT IN (
        SELECT CAR_ID
        FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
        WHERE END_DATE >= '2022-11-01'AND START_DATE <= '2022-11-30'
        )
        AND ROUND(car.DAILY_FEE * 30 * (100 - plan.DISCOUNT_RATE) * 0.01) BETWEEN 500000 AND 1999999
ORDER BY FEE DESC, CAR_TYPE, CAR_ID DESC;
