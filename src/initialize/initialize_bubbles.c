/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

static void my_bubble_sprite_creator(window_s *w)
{
	w->bubbles->s_bubble_one = sfSprite_create();
	w->bubbles->s_bubble_two = sfSprite_create();
	w->bubbles->s_bubble_three = sfSprite_create();
	w->bubbles->s_bubble_four = sfSprite_create();
	w->bubbles->s_bubble_five = sfSprite_create();
}

int initialize_bubbles(window_s *w)
{
	w->bubbles = malloc(sizeof(bubbles_s));
	if (w->bubbles == NULL)
		return (84);
	if (garbage_collector((char *)w->bubbles, 1))
		return (84);
	w->bubbles->t_good_bubble = T_createFF(GOOD_BUBBLE_PIC, NULL);
	w->bubbles->t_bad_bubble = T_createFF(BAD_BUBBLE_PIC, NULL);
	my_bubble_sprite_creator(w);
	return (0);
}
