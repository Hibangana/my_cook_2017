/*
** EPITECH PROJECT, 2018
** initialize_five.c
** File description:
** initialize_five.c
*/

#include "my.h"

int initialize_square_recipe(window_s *w)
{
	w->square = malloc(sizeof(square_s));
	if (w->square == NULL)
		return (84);
	if (garbage_collector((char *)w->square, 1))
		return (84);
	w->square->nb = 0;
	w->square->t_square = T_createFF(SQUARE_RECIPE, NULL);
	w->square->s_square = sfSprite_create();
	S_sTexture(w->square->s_square, w->square->t_square, sfTrue);
	return (0);
}

int initialize_game_background(window_s *w)
{
	w->game_bg = malloc(sizeof(game_bg_s));
	if (w->game_bg == NULL)
		return (84);
	if (garbage_collector((char *)w->game_bg, 1))
		return (84);
	w->game_bg->texture = T_createFF(GAME_BG, NULL);
	w->game_bg->sprite = sfSprite_create();
	S_sTexture(w->game_bg->sprite, w->game_bg->texture, sfTrue);
	return (0);
}

int initialize_cursor(button_s *b)
{
	b->cursor = malloc(sizeof(cursor_s));
	if (b->cursor == NULL)
		return (84);
	if (garbage_collector((char *)b->cursor, 1))
		return (84);
	b->cursor->on_cursor = 1;
	b->cursor->texture_off = T_createFF(CURSOR_NORMAL, NULL);
	b->cursor->texture_on = T_createFF(CURSOR_CLICKED, NULL);
	b->cursor->sprite_off = sfSprite_create();
	b->cursor->sprite_on = sfSprite_create();
	S_sTexture(b->cursor->sprite_off, b->cursor->texture_off, sfTrue);
	S_sTexture(b->cursor->sprite_on, b->cursor->texture_on, sfTrue);
	return (0);
}
