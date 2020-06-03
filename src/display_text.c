/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** display_text.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void text_score(t_name *name)
{
    name->score = sfText_create();
    name->poli = sfFont_createFromFile("./res/Finished Sympathy.otf");
    sfText_setString(name->score, "SCORE");
    sfText_setFont(name->score, name->poli);
    sfText_setCharacterSize(name->score, 90);

}

void text_nb_score(t_name *name)
{
    char *str_score = my_itoa(name->count_score);

    name->score_nb = sfText_create();
    sfText_setString(name->score_nb, str_score);
    sfText_setFont(name->score_nb, name->poli);
    sfText_setCharacterSize(name->score_nb, 90);
    text_score(name);

}
