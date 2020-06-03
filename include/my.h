/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my.h
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#ifndef MY_H
#define MY_H

typedef struct sf_name {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfSprite *sprite;
    sfTexture *texture2;
    sfSprite *sprite2;
    sfSprite *mouse_sprite;
    sfTexture *mouse_texture;
    sfTexture *gun_shot_text;
    sfSprite *gun_shot_sprite;
    sfIntRect rect;
    sfIntRect rect_mouse;
    sfIntRect rect_gun;
    sfText *score;
    sfFont *poli;
    sfText *score_nb;
    int count_score;
    float speed;
    int count_shot;
}t_name;

void move_rect(t_name *name);
int fly(t_name *name);
void analyse_events(t_name *name);

void return_line(t_name *name);
void manage_mouse_click(sfMouseButtonEvent event, t_name *name);
void move_rect_mouse(t_name *name);

void text_score(t_name *name);
void text_nb_score(t_name *name);

void initilization_var(t_name *name);
void initilization(t_name *name);
void display_pro(t_name *name);
void display_draw(t_name *name);
int game();

void destroy(t_name *name);

int my_first_int_len(int res);
int my_strcmp(char const *str1, char const *str2);
int my_strlen_tree(char const *str);
char *my_revstr(char *str);
char *my_itoa(int nb);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);

#endif
