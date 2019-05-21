/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

size_t check_if_existing_dish(window_s *w)
{
	ingredient_s *dish = w->dishes_l->head;

	while (dish != NULL) {
		if (my_strcmp(w->c_dish_l->custom_dish_ingredients,
		dish->ingredients) == 1 &&
		my_strlen(w->c_dish_l->custom_dish_ingredients) ==
		my_strlen(dish->ingredients))
			return (1);
		dish = dish->next;
	}
	return (0);
}

static void display_start_button_cust_three(window_s *w, int check)
{
	if (check == 3) {
		S_sP(w->c_dish_l->custom_two_sprite, V{730, 750});
		Draw_sprite(w->window, w->c_dish_l->custom_two_sprite,
			NULL);
		w->c_dish_l->on_one = 0;
		w->c_dish_l->on_two = 1;
		w->c_dish_l->on_three = 0;
	}
	if (check >= 4) {
		S_sP(w->c_dish_l->custom_three_sprite, V{730, 750});
		Draw_sprite(w->window, w->c_dish_l->custom_three_sprite,
			NULL);
		w->c_dish_l->on_one = 0;
		w->c_dish_l->on_two = 0;
		w->c_dish_l->on_three = 1;
	}
	S_sP(w->start_button->sprite, V{1180, 614});
	Draw_sprite(w->window, w->start_button->sprite, NULL);
}

void display_start_button_cust_two(window_s *w, int check)
{
	if (check == 2) {
		S_sP(w->c_dish_l->custom_sprite, V{730, 750});
		Draw_sprite(w->window, w->c_dish_l->custom_sprite,
			NULL);
		w->c_dish_l->on_one = 1;
		w->c_dish_l->on_two = 0;
		w->c_dish_l->on_three = 0;
	}
	display_start_button_cust_three(w, check);
}

void display_start_button_cust(window_s *w, int check)
{
	static size_t check_return;

	check_return = check_if_existing_dish(w);
	if (check_return == 1) {
		S_sP(w->c_dish_l->existing_sprite, V{700, 750});
		Draw_sprite(w->window, w->c_dish_l->existing_sprite, NULL);
	} else
		display_start_button_cust_two(w, check);
}
