/*
** EPITECH PROJECT, 2018
** display_htp.c
** File description:
** display_htp.c
*/

#include "my.h"

int display_how_to_play(window_s *w)
{
	if (sfKeyboard_isKeyPressed(sfKeyB))
		w->how_to_play->on_how_to_play = 0;
	Draw_sprite(w->window, w->how_to_play->sprite, NULL);
	return (0);
}
