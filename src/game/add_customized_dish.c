/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

static void add_customized_dish_three(window_s *w,
					ingredient_s *element)
{
	if (w->dishes_l->head == NULL) {
		w->dishes_l->head = element;
		element->next = NULL;
	} else {
		element->next = w->dishes_l->head;
		w->dishes_l->head = element;
	}
}

size_t add_customized_dish_two(window_s *w, size_t toggle)
{
	ingredient_s *element = malloc(sizeof(ingredient_s));

	if (element == NULL || garbage_collector((char *)element, 1))
		return (84);
	element->ingredients = my_strdup(w->c_dish_l->custom_dish_ingredients);
	if (toggle == 1)
		element->texture = T_createFF(CUST_ONE, NULL);
	if (toggle == 2)
		element->texture = T_createFF(CUST_TWO, NULL);
	if (toggle == 3)
		element->texture = T_createFF(CUST_THREE, NULL);
	element->sprite = sfSprite_create();
	S_sTexture(element->sprite, element->texture, sfTrue);
	element->bubble_texture = T_createFF("image/bubble.png", NULL);
	element->bubble_sprite = sfSprite_create();
	S_sTexture(element->bubble_sprite, element->bubble_texture, sfTrue);
	add_customized_dish_three(w, element);
	w->dishes_l->nb_dishes++;
	return (0);
}
