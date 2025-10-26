-- 분화된 연도(YEAR), 분화된 연도별 대장균 크기의 편차(YEAR_DEV), 대장균 개체의 ID(ID) 를 출력
-- 분화된 연도별 대장균 크기의 편차는 분화된 연도별 가장 큰 대장균의 크기 - 각 대장균의 크기
-- 연도에 대해 오름차순으로 정렬하고 같은 연도에 대해서는 대장균 크기의 편차에 대해 오름차순



SELECT YEAR(DIFFERENTIATION_DATE) AS YEAR, (MAX_SIZE-SIZE_OF_COLONY) AS YEAR_DEV, ID
FROM ECOLI_DATA e
    JOIN (
        SELECT YEAR(DIFFERENTIATION_DATE) AS YEAR , MAX(SIZE_OF_COLONY) AS MAX_SIZE
        FROM ECOLI_DATA
        GROUP BY YEAR(DIFFERENTIATION_DATE)) tmp
ON YEAR(e.DIFFERENTIATION_DATE) = tmp.YEAR
ORDER BY YEAR, YEAR_DEV;
