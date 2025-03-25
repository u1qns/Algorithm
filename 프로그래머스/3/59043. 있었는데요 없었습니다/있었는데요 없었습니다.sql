-- 보호 시작일보다 입양일이 더 빠른 동물의 아이디와 이름을 조회
-- 결과는 보호 시작일이 빠른 순으로 조회

-- 보호일은 ins에 DATETIME
-- 입양일은 outs에 DATETIME
-- 둘을 조인해서 비교
SELECT ins.ANIMAL_ID, ins.NAME
FROM ANIMAL_INS ins 
    JOIN ANIMAL_OUTS outs
    ON ins.ANIMAL_ID = outs.ANIMAL_ID
WHERE ins.DATETIME > outs.DATETIME
ORDER BY ins.DATETIME
