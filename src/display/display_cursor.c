/*
** EPITECH PROJECT, 2018
** display_cursor.c
** File description:
** display_cursor.c
*/

#include "my.h"

void display_cursor(window_s *w, button_s *b)
{
	static sfVector2f new_position;
	static sfIntRect rect = {0, 0, 150, 150};

	new_position.x = b->mouse.x - 75;
	new_position.y = b->mouse.y - 52;
	if (b->cursor->on_cursor == 1) {
		sfSprite_setPosition(b->cursor->sprite_off, new_position);
		sfSprite_setTextureRect(b->cursor->sprite_off, rect);
		Draw_sprite(w->window, b->cursor->sprite_off, NULL);
	} else {
		sfSprite_setPosition(b->cursor->sprite_on, new_position);
		sfSprite_setTextureRect(b->cursor->sprite_on, rect);
		Draw_sprite(w->window, b->cursor->sprite_on, NULL);
	}
}
