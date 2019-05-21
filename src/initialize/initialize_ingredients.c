/*
** EPITECH PROJECT, 2018
** initialize_ingredients.c
** File description:
** initialize_ingredients.c
*/

#include "my.h"

static int init_element(window_s *w, char *file)
{
	static int number = 1;
	recipes_info_s *element = malloc(sizeof(recipes_info_s));

	if (element == NULL)
		return (84);
	if (garbage_collector((char *)element, 1))
		return (84);
	element->number = number;
	element->texture = T_createFF(file, NULL);
	element->sprite = sfSprite_create();
	S_sTexture(element->sprite, element->texture, sfTrue);
	if (w->recipes_info_l->head == NULL) {
		w->recipes_info_l->head = element;
		element->next = NULL;
	} else {
		element->next = w->recipes_info_l->head;
		w->recipes_info_l->head = element;
	}
	number++;
	return (0);
}

int initialize_ingredients(window_s *w)
{
	w->ingredient_l = malloc(sizeof(ingredient_l));
	static char *file[10] = {BEEF, CHEESE,
		CREAM, EGG,
		FISH, FLOUR,
		NOODLES, RICE,
		SAUSAGE, VEGGIES};

	if (w->recipes_info_l == NULL)
		return (84);
	if (garbage_collector((char *)w->recipes_info_l, 1))
		return (84);
	w->recipes_info_l->head = NULL;
	for (int i = 0; i != 10; i++) {
		if (init_element(w, file[i]))
			return (84);
	}
	return (0);
}
