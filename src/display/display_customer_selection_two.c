/*
** EPITECH PROJECT, 2018
** display_customer_selection_two.c
** File description:
** display_customer_selection_two.c
*/

#include "my.h"

void display_start_button(window_s *w)
{
	S_sP(w->start_button->sprite, V{1180, 614});
	Draw_sprite(w->window, w->start_button->sprite, NULL);
}

int display_tick_two(window_s *w, sfVector2f *arr, int *status)
{
	int check = 0;

	for (int i = 0; i != 10; i++) {
		if (status[i] == 1) {
			check += 1;
			S_sP(w->tick->sprite, arr[i]);
			Draw_sprite(w->window, w->tick->sprite, NULL);
		}
	}
	if (check == 5)
		display_start_button(w);
	return (check);
}

static void my_sleep(void)
{
	static sfTime duration;

	duration.microseconds = 200000.0;
	sfSleep(duration);
}

int if_clicked(window_s *w, int tick_status, int i,
		sfVector2f *arr)
{
	customer_s *temp = w->customer_l->head;

	my_sleep();
	tick_status *= -1;
	while (temp != NULL) {
		if (arr[i].x == temp->position.x &&
			arr[i].y == temp->position.y)
			temp->chosen = 1;
		temp = temp->next;
	}
	return (tick_status);
}
