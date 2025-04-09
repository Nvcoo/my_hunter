/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** el_nano
*/

#include "../include/my.h"

sfSprite *renault(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *car_text = sfTexture_createFromFile("assets/renault.png", NULL);
    float scale = 0.25f;
    sfVector2f car_scale = {scale, scale};
    int random = (rand() % 2) == 0 ? 175 : 320;

    sfSprite_setTexture(sprite, car_text, sfTrue);
    sfSprite_setScale(sprite, car_scale);
    sfSprite_setPosition(sprite, (sfVector2f){0, random});
    return sprite;
}

sfSprite *lotus(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *car_text = sfTexture_createFromFile("assets/lotus.png", NULL);
    float scale = 0.25f;
    sfVector2f car_scale = {scale, scale};
    int random = (rand() % 2) == 0 ? 175 : 320;

    sfSprite_setTexture(sprite, car_text, sfTrue);
    sfSprite_setScale(sprite, car_scale);
    sfSprite_setPosition(sprite, (sfVector2f){0, random});
    return sprite;
}

sfSprite *mclaren(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *car_text = sfTexture_createFromFile("assets/mclaren.png", NULL);
    float scale = 0.25f;
    sfVector2f car_scale = {scale, scale};
    int random = (rand() % 2) == 0 ? 175 : 320;

    sfSprite_setTexture(sprite, car_text, sfTrue);
    sfSprite_setScale(sprite, car_scale);
    sfSprite_setPosition(sprite, (sfVector2f){0, random});
    return sprite;
}

sfSprite *redbull(void)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *car_text = sfTexture_createFromFile("assets/redbull.png", NULL);
    float scale = 0.25f;
    sfVector2f car_scale = {scale, scale};
    int random = (rand() % 2) == 0 ? 175 : 320;

    sfSprite_setTexture(sprite, car_text, sfTrue);
    sfSprite_setScale(sprite, car_scale);
    sfSprite_setPosition(sprite, (sfVector2f){0, random});
    return sprite;
}

sfSprite *random_car(void)
{
    int choice = rand() % 9;

    return elect(choice);
}
