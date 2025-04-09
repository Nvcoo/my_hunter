/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** my
*/

#ifndef INCLUDED_MY_H
    #define INCLUDED_MY_H

    #include <unistd.h>
    #include <SFML/Graphics.h>
    #include <stdlib.h>

typedef struct {
    sfRenderWindow *window;
    sfVideoMode mode;
    sfEvent event;
} window_t;

typedef struct {
    sfSprite *sprite;
    sfVector2f position;
    float speed;
} car_t;

typedef struct {
    int paused;
} game_t;

void my_putchar(char c);
int my_pustr(const char *str);
void my_put_nbr(int n);
int my_strlen(char const *str);
void help(int ac, char **av);
sfSprite *renault(void);
sfSprite *random_car(void);
sfSprite *redbull(void);
sfSprite *mclaren(void);
sfSprite *williams(void);
sfSprite *renault2(void);
sfSprite *caterham(void);
sfSprite *crashgate(void);
sfSprite *ferrari(void);
sfSprite *lotus(void);
sfSprite *elect(int choice);
#endif
