/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** my_first_int_len.c
*/

#include "../include/my.h"

int my_first_int_len(int res)
{
    int i;
    int j = 1;

    if (res == 0)
        return (1);
    if (res > 0) {
        for (i = 0; j <= res; i++)
            j = j * 10;
    } else {
        j = -1;
        for (i = 0; j >= res; i++)
            j = j * 10;
        i++;
    }
    return (i);
}
