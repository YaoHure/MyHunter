/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_duck.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void analyse_events(t_name *name)
{
    sfVector2f pos = sfSprite_getPosition(name->sprite);

    if (name->event.type == sfEvtMouseButtonReleased) {
        if (name->event.mouseButton.x <= pos.x + 110 &&
            name->event.mouseButton.x >= pos.x && name->event.mouseButton.y
            <= pos.y + 110 && name->event.mouseButton.y >= pos.y) {
            manage_mouse_click(name->event.mouseButton, name);
        } else {
            name->count_shot++;
        }
    }
    else if (name->event.type == sfEvtMouseMoved) {
        sfIntRect rect = sfSprite_getTextureRect(name->mouse_sprite);
        sfVector2f mouse_vect;
        mouse_vect.x = name->event.mouseMove.x - rect.width / 4;
        mouse_vect.y = name->event.mouseMove.y - rect.height / 4;
        sfSprite_setPosition(name->mouse_sprite, mouse_vect);
    }
}

int fly(t_name *name)
{
    if (name->rect.left == 220)
        name->rect.left = 0;
    else if (name->rect.left < 220)
        name->rect.left += 110;
    return (0);
}

void move_rect(t_name *name)
{
    name->rect_gun.left = (name->rect_gun.left + 96 * 2 > 1152) ? 0 : name->
    rect_gun.left + 96;
    fly(name);
}
