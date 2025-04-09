/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** cars3
*/

#include "../include/my.h"

sfSprite *williams(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *car_text = sfTexture_createFromFile("assets/william.png", NULL);
    float scale = 0.25f;
    sfVector2f car_scale = {scale, scale};
    int random = (rand() % 2) == 0 ? 175 : 320;

    sfSprite_setTexture(sprite, car_text, sfTrue);
    sfSprite_setScale(sprite, car_scale);
    sfSprite_setPosition(sprite, (sfVector2f){0, random});
    return sprite;
}

sfSprite *elect(int choice)
{
    switch (choice) {
        case 0:
            return renault();
        case 1:
            return lotus();
        case 2:
            return mclaren();
        case 3:
            return redbull();
        case 4:
            return caterham();
        case 5:
            return crashgate();
        case 6:
            return ferrari();
        case 8:
            return williams();
    }
    return renault();
}
