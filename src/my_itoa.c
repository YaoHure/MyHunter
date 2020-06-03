/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_itoa.c
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_itoa(int nb)
{
    char *str = malloc(sizeof(char *)  + 1000);
    char *dest = malloc(sizeof(char *)  + 1000);
    int dix = 10;
    int inter = 1;
    int res_1 = 0;
    int res_2 = 0;
    int i = 0;

    for (i = 0; i < my_first_int_len(nb); i++) {
        res_1 = nb - ((nb / dix) * dix);
        res_2 = res_1 / inter;
        str[i] = res_2 + 48;
        nb = nb - res_1;
        dix = dix * 10;
        inter = inter * 10;
    }
    str[i] = '\0';
    dest = my_revstr(str);
    return (dest);
}
