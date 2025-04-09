/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** my
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(const char *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return 0;
}

void my_put_nbr(int n)
{
    if (n < 0) {
        my_putchar('-');
        n = -n;
    }
    if (n / 10) {
        my_put_nbr(n / 10);
    }
    my_putchar(n % 10);
}

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void help(int ac, char **av)
{
    int i;

    for (i = 1; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'h') {
            my_putstr("Usage: ./my_hunter [options]\n");
            my_putstr("Options:\n");
            my_putstr("  -h\tPrint this message and exit.\n");
            my_putstr("Controls:\n");
            my_putstr("  Esc;\t\tPauses the game.\n");
            my_putstr("  Enter;\tUnpauses the game.\n");
            exit(0);
        }
    }
}
