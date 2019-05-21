/*
** EPITECH PROJECT, 2018
** initialize_customers.c
** File description:
** initialize_customers.c
*/

#include "my.h"

static sfVector2f set_position(sfVector2f position)
{
	static int counter;

	if (counter < 4)
		position.y = 265;
	else {
		if (counter == 4)
			position.x = 150;
		position.y = 500;
	}
	if (counter == 8)
		counter = 0;
	counter++;
	position.x += 200;
	return (position);
}

static customer_s *initialize_customer_three(customer_s *element,
					char *file, sfVector2f position, int i)
{
	static char *ingredients[10] = {RECIPE_ONE, RECIPE_TWO,
				RECIPE_THREE, RECIPE_FOUR,
				RECIPE_FIVE, RECIPE_SIX,
				RECIPE_SEVEN, RECIPE_EIGHT,
				RECIPE_NINE, RECIPE_TEN};

	element->dish = my_strdup(ingredients[i]);
	element->texture = T_createFF(file, NULL);
	element->sprite = sfSprite_create();
	element->rect = (sfIntRect) {0, 0, 120, 120};
	element->position = position;
	element->chosen = 0;
	element->satisfied = -1;
	return (element);
}

static customer_s *initialize_customer_two(window_s *w, char *file, int i)
{
	static sfVector2f position = {350, 265};
	customer_s *element = malloc(sizeof(customer_s));

	if (element == NULL)
		return (NULL);
	if (garbage_collector((char *)element, 1))
		return (NULL);
	element = initialize_customer_three(element, file, position, i);
	if (w->customer_l->head == NULL) {
		w->customer_l->head = element;
		element->next = NULL;
	} else {
		element->next = w->customer_l->head;
		w->customer_l->head = element;
	}
	position = set_position(position);
	return (element);
}

int initialize_customer(window_s *w)
{
	customer_s *element;
	char *file[10] = {CUSTOMER_1, CUSTOMER_2, CUSTOMER_3,
				CUSTOMER_4, CUSTOMER_5, CUSTOMER_6,
				CUSTOMER_7, CUSTOMER_8, CUSTOMER_9,
				CUSTOMER_10};

	w->customer_l = malloc(sizeof(customer_l));
	w->customer_l->head = NULL;
	w->customer_l->on_customer_selection = 1;
	for (int i = 0; i != 10; i++) {
		element = initialize_customer_two(w, file[i], i);
		if (element == NULL)
			return (84);
		S_sP(element->sprite, element->position);
		element->clock = sfClock_create();
	}
	return (0);
}
