/*
** EPITECH PROJECT, 2018
** display_recipes.c
** File description:
** display_recipes.c
*/

#include "my.h"

static int display_recipe_square(window_s *w, sfVector2f vector, int nb)
{
	S_sP(w->square->s_square, vector);
	Draw_sprite(w->window, w->square->s_square, NULL);
	w->square->nb = nb;
	return (0);
}

static int display_recipe_info(window_s *w)
{
	recipes_info_s *temp = w->recipes_info_l->head;

	while (temp != NULL) {
		if (temp->number == w->square->nb) {
			S_sP(temp->sprite, V{570, 255});
			Draw_sprite(w->window, temp->sprite, NULL);
		}
		temp = temp->next;
	}
	return (0);
}

int display_square(window_s *w, sfVector2f *position)
{
	for (int i = 0; i != 10; i++)
		if (w->square->nb == i + 1)
			display_recipe_square(w, position[i], i + 1);
	return (0);
}

int display_square_and_info(window_s *w, button_s *b, sfVector2f *position)
{
	for (int i = 0; i != 10; i++) {
		if (MOUSE_ON_RECIPE && (MOUSE_LEFT_PRESSED))
			display_recipe_square(w, position[i], i + 1);
		display_recipe_info(w);
	}
	return (0);
}

int display_recipes(window_s *w, button_s *b)
{
	static sfVector2f position[10] = { {268, 128}, {268, 239}, {268, 349},
		{268, 459}, {268, 569}, {1158, 129}, {1158, 239},
		{1158, 349}, {1158, 459}, {1158, 569} };

	if (sfKeyboard_isKeyPressed(sfKeyB))
		w->recipes->on_recipes = 0;
	Draw_sprite(w->window, w->recipes->sprite, NULL);
	display_square(w, position);
	display_square_and_info(w, b, position);
	return (0);
}
