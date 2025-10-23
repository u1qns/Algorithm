-- 보호소에 들어올 당시에는 중성화1되지 않았지만, 
-- 보호소를 나갈 당시에는 중성화된 동물의 아이디와 생물 종, 이름을 조회
-- 아이디 순으로 조회
SELECT i.ANIMAL_ID, i.ANIMAL_TYPE, i.NAME
FROM ANIMAL_INS i JOIN ANIMAL_OUTS o
    ON i.ANIMAL_ID = o.ANIMAL_ID
        AND i.SEX_UPON_INTAKE LIKE 'Intact%' AND o.SEX_UPON_OUTCOME NOT LIKE 'Intact%'
ORDER BY i.ANIMAL_ID;