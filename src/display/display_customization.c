/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

int display_tick_cust_two(window_s *w, sfVector2f *arr, int *status)
{
	int check = 0;

	for (int i = 0; i != 10; i++) {
		if (status[i] == 1) {
			check += 1;
			S_sP(w->tick->sprite, arr[i]);
			Draw_sprite(w->window, w->tick->sprite, NULL);
		}
	}
	if (check >= 2)
		display_start_button_cust(w, check);
	return (check);
}

static void my_sleep(void)
{
	static sfTime duration;

	duration.microseconds = 200000.0;
	sfSleep(duration);
}

static int if_custom_clicked(int tick_status)
{
	my_sleep();
	tick_status *= -1;
	return (tick_status);
}

static size_t display_tick(window_s *w, button_s *b)
{
	static sfVector2f arr[10] = { {320, 265}, {520, 265}, {720, 265},
				{920, 265}, {1120, 265}, {320, 500}, {520, 500},
				{720, 500}, {920, 500}, {1120, 500} };
	static int tick_status[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	static char ingredients[10] = "1234567890";
	int j = 0;

	if (w->restart == 1)
		for (int i = 0; i != 11; i++)
			tick_status[i] = -1;
	for (int i = 0; i != 10; i++) {
		if (MOUSE_ON_INGRE && MOUSE_LEFT_PRESSED)
			tick_status[i] = if_custom_clicked(tick_status[i]);
		if (tick_status[i] == 1)
			CUSTOM_DISH[j++] = ingredients[i];
	}
	w->c_dish_l->custom_dish_ingredients[j] = '\0';
	return (display_tick_cust_two(w, arr, tick_status));
}

void display_customization(window_s *w, button_s *b)
{
	static size_t ingredients_number;
	static size_t choice;

	if (choice == 0)
		choice = display_choice(w);
	else if (choice == 1) {
		Draw_sprite(w->window, w->c_dish_l->sprite, NULL);
		ingredients_number = display_tick(w, b);
		if (ingredients_number >= 2 &&
		B_IS_CLICKED(b->mouse, V{1186, 671}, V{216, 68}) == 1 &&
		MOUSE_LEFT_PRESSED)
			w->c_dish_l->on_customization = 0;
	} else
		w->c_dish_l->on_customization = 0;
}
