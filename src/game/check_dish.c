/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

static size_t check_dish_two(char *to_check,
		customer_s *customer)
{
	if (my_strcmp(to_check, customer->dish) == 1) {
		customer->satisfied = 1;
		return (1);
	}
	if (my_strcmp(to_check, customer->dish) != 1)
		customer->satisfied = 0;
	return (0);
}

size_t check_dish(window_s *w, char *to_check, size_t toggle)
{
	customer_s *customer = w->customer_l->head;
	size_t i = 0;

	while (customer != NULL) {
		if (customer->chosen == 1)
			i++;
		if (i == toggle)
			if (check_dish_two(to_check, customer))
				return (1);
		customer = customer->next;
	}
	return (0);
}
