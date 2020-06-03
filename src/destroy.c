/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** destroy.c
*/

#include "../include/my.h"

void destroy(t_name *name)
{
    sfRenderWindow_destroy(name->window);
    sfSprite_destroy(name->sprite);
    sfTexture_destroy(name->texture);
    sfRenderWindow_destroy(name->window);
    sfTexture_destroy(name->texture2);
    sfSprite_destroy(name->mouse_sprite);
    sfTexture_destroy(name->mouse_texture);
    sfTexture_destroy(name->gun_shot_text);
    sfSprite_destroy(name->gun_shot_sprite);
    sfText_destroy(name->score);
    sfText_destroy(name->score_nb);
    sfFont_destroy(name->poli);
}
