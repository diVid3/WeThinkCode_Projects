INSERT INTO db_egenis.ft_table(`login`, `creation_date`, `group`)
SELECT `last_name` AS `login`, date(`birthdate`) AS `creation_date`, 'other' AS `group`
FROM db_egenis.user_card
WHERE `last_name` LIKE '%a%' AND CHAR_LENGTH(last_name) < 9
ORDER BY `last_name`
LIMIT 10;