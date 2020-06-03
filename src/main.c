/*
** EPITECH PROJECT, 2018
** MUL_my_hunter_2018
** File description:
** main.c
*/
#include <unistd.h>
#include "../include/my.h"

void display_creator(void)
{
    write(1, "Game Name: New Generation of Dunk Hunt\n", 40);
    write(1, "Creator: Yaowanart HURE\n", 25);
    write(1, "Year of creation: 2018\n", 24);
    write(1, "The goal of the game is to shot on the dunk\n", 45);
    write(1, "The Rules of the Game:\n", 24);
    write(1, "You have several targets and your goal is to kill the dunk\n", 60)
    ;
    write(1, "On the bottom you can see your score\n", 39);
    write(1, "Little difficulty: the speed of the dunk can change\n", 53);
    write(1, "You only have two chances to kill the dunk\n", 44);
    write(1, "If you miss your target, the window will close automatically", 61)
    ;
}

int main(int ac, char **av)
{
    if (ac == 1) {
        game();
    }
    else if (ac == 2 && (my_strcmp(av[1], "-h"))) {
        display_creator();
    }
    return (0);
}
