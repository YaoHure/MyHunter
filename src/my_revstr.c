/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_revstr.c
*/

#include "../include/my.h"

int my_strlen_tree(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_revstr(char *str)
{
    char i;
    int a = 0;
    int b = my_strlen_tree(str)-1;

    while (a < b) {
        i = str[a];
        str[a] = str[b];
        str[b] = i;
        a++;
        b--;
    }
    return (str);
}
