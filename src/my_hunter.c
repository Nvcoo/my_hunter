/*
** EPITECH PROJECT, 2024
** Untitled (Workspace)
** File description:
** my_hunter
*/

#include "../include/my.h"
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Sprite.h>
#include <SFML/Graphics/Texture.h>
#include <time.h>

int mouse_handler(window_t *win, car_t *car)
{
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(win->window);
    sfVector2f m_w = sfRenderWindow_mapPixelToCoords(win->window, m_pos, NULL);
    sfFloatRect box = sfSprite_getGlobalBounds(car->sprite);

    if (sfFloatRect_contains(&box, m_w.x, m_w.y) &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        return 0;
    }
    return 1;
}

int event_process(sfEvent event, window_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(win->window);
        }
    }
    return 0;
}

static void update(window_t *win, sfSprite *sprite, car_t *car)
{
    sfRenderWindow_clear(win->window, sfBlack);
    sfRenderWindow_drawSprite(win->window, sprite, NULL);
    sfRenderWindow_drawSprite(win->window, car->sprite, NULL);
    sfRenderWindow_display(win->window);
}

static void reset_car(car_t *car, float *speed)
{
    car->position.x = -sfSprite_getGlobalBounds(car->sprite).width;
    car->position.y = (rand() % 2) == 0 ? 175 : 320;
    sfSprite_setPosition(car->sprite, car->position);
    car->sprite = random_car();
    *speed *= 0.90f;
}

static void pause_game(window_t *win)
{
    sfEvent event;

    while (1) {
        event_process(event, win);
        if (sfKeyboard_isKeyPressed(sfKeyEnter)) {
            break;
        }
        sfRenderWindow_display(win->window);
    }
}

void game(window_t *win, car_t *car, sfSprite *sprite)
{
    float speed = 5.0f;

    while (sfRenderWindow_isOpen(win->window)) {
        event_process(win->event, win);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            pause_game(win);
        if (mouse_handler(win, car) == 0) {
            car->position.x = -sfSprite_getGlobalBounds(car->sprite).width;
            car->position.y = (rand() % 2) == 0 ? 175 : 320;
            sfSprite_setPosition(car->sprite, car->position);
            car->sprite = random_car();
            speed *= 1.1f;
        }
        car->position.x += speed;
        if (car->position.x > 800)
            reset_car(car, &speed);
        sfSprite_setPosition(car->sprite, car->position);
        update(win, sprite, car);
    }
}

static sfSprite *create_background(window_t *win)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *back_text = sfTexture_createFromFile("assets/road.png", NULL);
    sfVector2u window_size = sfRenderWindow_getSize(win->window);
    sfVector2u back_text_size = sfTexture_getSize(back_text);
    sfVector2f scale = {
        (float)window_size.x / back_text_size.x,
        (float)window_size.y / back_text_size.y
    };

    sfSprite_setTexture(sprite, back_text, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

int main(int ac, char **av)
{
    window_t win;
    car_t car;
    sfSprite *back_sprite;

    help(ac, av);
    win.mode = (sfVideoMode){800, 600, 32};
    win.window = sfRenderWindow_create(win.mode, "", sfResize | sfClose, NULL);
    if (!win.window)
        return 84;
    sfRenderWindow_setFramerateLimit(win.window, 60);
    car.sprite = random_car();
    sfRenderWindow_setMouseCursorVisible(win.window, sfTrue);
    car.position = sfSprite_getPosition(car.sprite);
    back_sprite = create_background(&win);
    game(&win, &car, back_sprite);
    sfSprite_destroy(back_sprite);
    sfSprite_destroy(car.sprite);
    sfRenderWindow_destroy(win.window);
    return 0;
}

sfSprite *load_sprite(char *filename)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *sprite_text = sfTexture_createFromFile(filename, NULL);

    sfSprite_setTexture(sprite, sprite_text, sfTrue);
    sfTexture_destroy(sprite_text);
    return sprite;
}
