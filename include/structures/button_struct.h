/*
** EPITECH PROJECT, 2018
** button.h
** File description:
** button.h
*/

#ifndef BUTTON_H
#define BUTTON_H

typedef struct cursor_s {
	int on_cursor;
	sfTexture *texture_off;
	sfSprite *sprite_off;
	sfTexture *texture_on;
	sfSprite *sprite_on;
} cursor_s;

typedef struct sound_s {
	sfRectangleShape *shape;
	struct sfSprite *s_sound;
	struct sfTexture *t_sound;
	sfIntRect r_sound;
	void (*sound)();
} sound_s;

typedef struct effects_sound_s {
	sfRectangleShape *shape;
	struct sfSprite *s;
	struct sfTexture *t;
	sfIntRect r_sound;
	void (*effects_sound)();
} effects_sound_s;

typedef struct underlign_position_s {
	sfVector2f position;
	sfVector2f size;
} underlign_position_s;

typedef struct start_menu_hitbox_s {
	sfVector2f position;
	sfVector2f size;
} start_menu_hitbox_s;

typedef struct underlign_s {
	sfRectangleShape *shape;
	struct sfSprite *s_under;
	struct sfTexture *t_under;
	sfVector2f **u_position;
	sfVector2f **u_hitbox;
	sfIntRect r_under;
} underlign_s;

#endif
