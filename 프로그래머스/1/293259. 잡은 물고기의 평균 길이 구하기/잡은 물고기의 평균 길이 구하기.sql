-- 코드를 작성해주세요

WITH TBL AS (
SELECT IFNULL(LENGTH, 10) AS LEN
FROM FISH_INFO
)

SELECT ROUND(AVG(LEN),2) AS AVERAGE_LENGTH
FROM TBL