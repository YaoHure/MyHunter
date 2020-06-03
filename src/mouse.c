/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** mouse.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void return_line(t_name *name)
{
    sfVector2f return_stat = sfSprite_getPosition(name->sprite);
    int y = rand()% 500;
    sfVector2f vecfly = {-110, y};

    if (return_stat.x > 1279) {
        name->rect.top = 0;
    }else if (return_stat.x < -100){
        name->rect.top = 110;
    }
}

void manage_mouse_click(sfMouseButtonEvent event, t_name *name)
{
    sfVector2f offset2_bis;
    offset2_bis.x = rand () % 2;
    offset2_bis.y = rand () % 500;
    if (offset2_bis.x == 0) {
        offset2_bis.x = 1280;
    }
    else if (offset2_bis.x == 1) {
        offset2_bis.x = -210;
    }
    sfSprite_setPosition(name->sprite, offset2_bis);
    name->speed = (name->count_score % 5 == 0) ? name->speed + 2 :
    name->speed;
    name->count_score++;
    text_nb_score(name);

}

void move_rect_mouse(t_name *name)
{
    sfClock *clock = sfClock_create();
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = time.microseconds / 1000000.0;

    name->rect_mouse.left += 128;
    if (name->rect_mouse.left >= 2048) {
        name->rect_mouse.left = 0;
    }
    sfClock_restart(clock);
}
