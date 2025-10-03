-- 더 이상 업그레이드할 수 없는 아이템의 
-- 아이템 ID(ITEM_ID), 아이템 명(ITEM_NAME), 아이템의 희귀도(RARITY
-- 아이템 ID를 기준으로 내림차순


-- 더 이상 업그레이드 못 하는 거 찾기 
-- tree에서 prarent_item_id에 없는 애들이 업그레이드 못 하는거임


SELECT ITEM_ID, ITEM_NAME, RARITY
FROM ITEM_INFO
WHERE ITEM_ID NOT IN 
(
    SELECT DISTINCT PARENT_ITEM_ID
    FROM ITEM_TREE
    WHERE PARENT_ITEM_ID IS NOT NULL
)
ORDER BY ITEM_ID DESC
