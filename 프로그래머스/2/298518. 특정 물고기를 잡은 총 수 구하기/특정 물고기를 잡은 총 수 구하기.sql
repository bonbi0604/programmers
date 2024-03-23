-- 코드를 작성해주세요

SELECT COUNT(ID) AS FISH_COUNT
FROM FISH_INFO AS F JOIN FISH_NAME_INFO AS I ON F.FISH_TYPE = I.FISH_TYPE
WHERE I.FISH_NAME IN ('BASS', 'SNAPPER');
