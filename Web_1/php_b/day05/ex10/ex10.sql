SELECT title AS 'Title', summary AS 'Summary', `prod_year`
FROM db_egenis.film LEFT JOIN db_egenis.genre
ON db_egenis.film.id_genre = db_egenis.genre.id_genre
WHERE db_egenis.genre.`name` = 'erotic';