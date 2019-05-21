/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

size_t display_choice(window_s *w)
{
	Draw_sprite(w->window, w->c_dish_l->choice_sprite, NULL);
	if (sfKeyboard_isKeyPressed(sfKeyY))
		return (1);
	if (sfKeyboard_isKeyPressed(sfKeyN))
		return (2);
	return (0);
}
