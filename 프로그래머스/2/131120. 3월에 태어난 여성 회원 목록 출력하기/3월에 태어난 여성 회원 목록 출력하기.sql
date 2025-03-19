-- 생일이 3월인 여성 회원의 ID, 이름, 성별, 생년월일을 조회
-- 전화번호가 NULL인 경우는 출력대상에서 제외
-- 회원ID를 기준으로 오름차순 정렬
SELECT MEMBER_ID, MEMBER_NAME, GENDER,  DATE_FORMAT(date_of_birth, '%Y-%m-%d') AS DATE_OF_BIRTH
FROM MEMBER_PROFILE
WHERE month(date_of_birth) = 3 AND GENDER = 'W' AND TLNO IS NOT NULL
ORDER BY member_id;