/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** cars2
*/

#include "../include/my.h"

sfSprite *caterham(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *car_text = sfTexture_createFromFile("assets/caterha.png", NULL);
    float scale = 0.2f;
    sfVector2f car_scale = {scale, scale};
    int random = (rand() % 2) == 0 ? 175 : 320;

    sfSprite_setTexture(sprite, car_text, sfTrue);
    sfSprite_setScale(sprite, car_scale);
    sfSprite_setPosition(sprite, (sfVector2f){0, random});
    return sprite;
}

sfSprite *crashgate(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *car_text = sfTexture_createFromFile("assets/ing.png", NULL);
    float scale = 0.25f;
    sfVector2f car_scale = {scale, scale};
    int random = (rand() % 2) == 0 ? 175 : 320;

    sfSprite_setTexture(sprite, car_text, sfTrue);
    sfSprite_setScale(sprite, car_scale);
    sfSprite_setPosition(sprite, (sfVector2f){0, random});
    return sprite;
}

sfSprite *ferrari(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *car_text = sfTexture_createFromFile("assets/ferrari.png", NULL);
    float scale = 0.2f;
    sfVector2f car_scale = {scale, scale};
    int random = (rand() % 2) == 0 ? 175 : 320;

    sfSprite_setTexture(sprite, car_text, sfTrue);
    sfSprite_setScale(sprite, car_scale);
    sfSprite_setPosition(sprite, (sfVector2f){0, random});
    return sprite;
}
