/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

static void display_my_hp(window_s *w)
{
	if (w->game_hp->hp > 0)
		Draw_sprite(w->window, GAME_HP_ONE_SPRITE, NULL);
	if (w->game_hp->hp > 1)
		Draw_sprite(w->window, GAME_HP_TWO_SPRITE, NULL);
	if (w->game_hp->2)
		Draw_sprite(w->window, GAME_HP_THREE_SPRITE, NULL);
}

void display_hp_and_score(window_s *w, button_s *b, music_s *m)
{
	display_my_hp(w);
}
