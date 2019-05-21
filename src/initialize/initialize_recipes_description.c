/*
** EPITECH PROJECT, 2018
** description.c
** File description:
** description.c
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

int initialize_recipes_info(window_s *w)
{
	w->recipes_info_l = malloc(sizeof(recipes_info_l));
	static char *file[10] = {RECIPES_INFO_1, RECIPES_INFO_2,
		RECIPES_INFO_3, RECIPES_INFO_4,
		RECIPES_INFO_5, RECIPES_INFO_6,
		RECIPES_INFO_7, RECIPES_INFO_8,
		RECIPES_INFO_9, RECIPES_INFO_10};

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
