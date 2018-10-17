SELECT COUNT(*) AS 'nb_short-films'
FROM db_egenis.film LEFT JOIN db_egenis.genre
ON db_egenis.film.id_genre = db_egenis.genre.id_genre
WHERE `duration` <= 42 AND db_egenis.genre.`name` = 'short film';