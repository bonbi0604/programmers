-- 코드를 작성해주세요
SELECT COUNT(INFO.FISH_TYPE) AS FISH_COUNT, FISH_NAME
FROM FISH_INFO AS INFO JOIN FISH_NAME_INFO AS NAME ON INFO.FISH_TYPE = NAME.FISH_TYPE
GROUP BY INFO.FISH_TYPE, FISH_NAME
ORDER BY COUNT(INFO.FISH_TYPE) DESC
