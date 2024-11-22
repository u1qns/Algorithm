-- 코드를 입력하세요
SELECT SUBSTR(PRODUCT_CODE, 1, 2) as category, count(*) as PRODUCTS
from product 
group by SUBSTR(PRODUCT_CODE, 1, 2)
order by category