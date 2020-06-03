/*
** EPITECH PROJECT, 2018
** Yaowanart HURE
** File description:
** game.c
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

void initilization(t_name *name)
{
    sfVideoMode video_mode = {1280, 720, 32};
    sfVector2f mouse_fact = {0.5, 0.5};
    sfVector2f gun_pos = {video_mode.width - name->rect_gun.width - 10,
    video_mode.height - 100};
    name->count_shot = 0;
    name->window = sfRenderWindow_create(video_mode, "My_Hunter", sfDefaultStyle
    , NULL);
    name->texture = sfTexture_createFromFile("./res/duck_my_hunter_2.png", NULL)
    ;
    name->sprite = sfSprite_create();
    name->texture2 = sfTexture_createFromFile("./res/blackground.png", NULL);
    name->sprite2 = sfSprite_create();
    name->mouse_texture = sfTexture_createFromFile("./res/Souris.png", NULL);
    name->mouse_sprite = sfSprite_create();
    name->gun_shot_text = sfTexture_createFromFile("./res/life.png", NULL);
    name->gun_shot_sprite = sfSprite_create();
    sfSprite_setPosition(name->gun_shot_sprite, gun_pos);
    sfSprite_scale(name->mouse_sprite, mouse_fact);
    text_score(name);
    text_nb_score(name);
}

void initilization_var(t_name *name)
{
    name->speed = 0.1;
    name->rect.top = 110;
    name->rect.left = 0;
    name->rect.width = 110;
    name->rect.height = 110;

    name->rect_mouse.top = 0;
    name->rect_mouse.left = 0;
    name->rect_mouse.width = 128;
    name->rect_mouse.height = 128;

    name->rect_gun.top = 0;
    name->rect_gun.left = 0;
    name->rect_gun.width = 96;
    name->rect_gun.height = 110;

    initilization(name);
}

void display_draw(t_name *name)
{
    sfVector2f vector_text = {0, 560};
    sfVector2f vector_text_score = {0, 620};
    sfVector2f offset2;
    if (name->rect.top == 0) {
        offset2.x = -6 - name->speed;
    } else {
        offset2.x = 6 + name->speed;
    }
    offset2.y = 0;
    sfRenderWindow_drawSprite(name->window, name->mouse_sprite, NULL);
    sfRenderWindow_drawSprite(name->window, name->gun_shot_sprite, NULL);
    sfText_setPosition(name->score, vector_text);
    sfRenderWindow_drawText(name->window, name->score, NULL);
    sfText_setPosition(name->score_nb, vector_text_score);
    sfRenderWindow_drawText(name->window, name->score_nb, NULL);
    sfRenderWindow_display(name->window);
    sfRenderWindow_clear(name->window, sfBlack);
    sfSprite_move(name->sprite, offset2);
    sfRenderWindow_setMouseCursorVisible(name->window, sfFalse);
    sfRenderWindow_setFramerateLimit(name->window, 60);
}

void display_pro(t_name *name)
{
    sfSprite_setTexture(name->sprite2, name->texture2, sfTrue);
    sfSprite_setTexture(name->sprite, name->texture, sfTrue);
    sfSprite_setTexture(name->mouse_sprite, name->mouse_texture, sfTrue);
    sfSprite_setTexture(name->gun_shot_sprite, name->gun_shot_text, sfTrue);
    sfSprite_setTextureRect(name->sprite, name->rect);
    sfSprite_setTextureRect(name->mouse_sprite, name->rect_mouse);
    sfSprite_setTextureRect(name->gun_shot_sprite, name->rect_gun);
    return_line(name);
    sfRenderWindow_drawSprite(name->window, name->sprite2, NULL);
    sfRenderWindow_drawSprite(name->window, name->sprite, NULL);
    display_draw(name);
}

int game(void)
{
    t_name *name = malloc(sizeof(t_name));
    sfClock *clock = sfClock_create();
    initilization_var(name);
    while (sfRenderWindow_isOpen(name->window)) {
        sfTime time = sfClock_getElapsedTime(clock);
        float seconds = time.microseconds / 1000000.0;
        while (sfRenderWindow_pollEvent(name->window, &name->event)) {
            analyse_events(name);
            if (name->event.type == sfEvtClosed || name->count_shot == 5)
                sfRenderWindow_close(name->window);
        }
        if (seconds > 0.2) {
            move_rect(name);
            move_rect_mouse(name);
            sfClock_restart(clock);
        }
        display_pro(name);
    }
    destroy(name);
    return (0);
}
