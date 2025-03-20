-- 입양을 간 기록은 있는데, 보호소에 들어온 기록이 없는 동물의 ID와 이름을 ID 순으로 조회
-- 정보는 outs에 있다.
SELECT outs.ANIMAL_ID, outs.NAME
FROM ANIMAL_INS ins 
    RIGHT OUTER JOIN ANIMAL_OUTS outs
    ON ins.ANIMAL_ID = outs.ANIMAL_ID
WHERE ins.ANIMAL_ID IS NULL
ORDER BY outs.ANIMAL_ID, outs.NAME