SELECT  A.AUTHOR_ID
               , A.AUTHOR_NAME
               , B.CATEGORY
                , SUM(C.SALES*B.PRICE) AS TOTAL_SALES
   FROM  BOOK B
     LEFT
     JOIN  AUTHOR A
        ON  A.AUTHOR_ID = B.AUTHOR_ID
    LEFT
     JOIN  BOOK_SALES C 
        ON  B.BOOK_ID = C.BOOK_ID
WHERE SALES_DATE LIKE '2022-01%'
GROUP
         BY A.AUTHOR_ID
              , A.AUTHOR_NAME
              , B.CATEGORY
ORDER
        BY  A.AUTHOR_ID ASC
               , B.CATEGORY DESC