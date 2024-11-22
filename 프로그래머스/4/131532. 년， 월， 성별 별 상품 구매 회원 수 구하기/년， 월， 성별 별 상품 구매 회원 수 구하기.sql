-- 코드를 입력하세요
SELECT  YEAR(SALES_DATE) as YEAR, MONTH(SALES_DATE) AS MONTH, gender AS GENDER, COUNT(DISTINCT ui.user_id) as USERS
from ONLINE_SALE os join USER_INFO ui on ui.user_id = os.user_id
where gender is not null
group by YEAR(SALES_DATE), MONTH(SALES_DATE), gender
order by YEAR(SALES_DATE), MONTH(SALES_DATE), gender