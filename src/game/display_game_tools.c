/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

void display_game_prep(window_s *w)
{
	if (PLATE_ONE[0] != '\0')
		Draw_sprite(w->window, PREP_ONE_SPRITE, NULL);
	if (PLATE_TWO[0] != '\0')
		Draw_sprite(w->window, PREP_TWO_SPRITE, NULL);
	if (PLATE_THREE[0] != '\0')
		Draw_sprite(w->window, PREP_THREE_SPRITE, NULL);
}

void display_game_hp(window_s *w)
{
	if (MY_GAME_HP > 0)
		Draw_sprite(w->window, GAME_HP_ONE_SPRITE, NULL);
	if (MY_GAME_HP > 1)
		Draw_sprite(w->window, GAME_HP_TWO_SPRITE, NULL);
	if (MY_GAME_HP > 2)
		Draw_sprite(w->window, GAME_HP_THREE_SPRITE, NULL);
}

void display_in_game_guide(window_s *w, button_s *b, music_s *m)
{
	while (w->event.key.code != sfKeyR) {
		sfRenderWindow_pollEvent(w->window, &w->event);
		Display_window(w->window);
		Clear_window(w->window, sfBlack);
		Draw_sprite(w->window, w->game_guide->s_game_guide, NULL);
		for (int i = 0; i != 10000000; i++);
	}
	play_click_sound(w, b, m, 84);
}

void display_game_arrow(window_s *w)
{
	sfVector2f vect = {w->arrow->x, w->arrow->y};

	sfSprite_setPosition(w->arrow->s_arrow, vect);
	Draw_sprite(w->window, w->arrow->s_arrow, NULL);
}
