/*
** EPITECH PROJECT, 2018
** display_background.c
** File description:
** display_background.c
*/

#include "my.h"

static void animate_customers(customer_s *temp)
{
	if (temp->seconds > 2) {
		if (temp->rect.left >= 480 && temp->rect.top == 0) {
			temp->rect.left = -120;
			temp->rect.top = 130;
		}
		if (temp->rect.left >= 480 && temp->rect.top == 130) {
			temp->rect.left = -120;
			temp->rect.top = 0;
		}
		temp->rect.left += 120;
		sfClock_restart(temp->clock);
	}
}

static void display_customers(window_s *w)
{
	customer_s *temp = w->customer_l->head;

	while (temp != NULL) {
		temp->time = sfClock_getElapsedTime(temp->clock);
		temp->seconds = temp->time.microseconds / 100000.0;
		animate_customers(temp);
		S_sTexture(temp->sprite, temp->texture, sfTrue);
		S_sTextureR(temp->sprite, temp->rect);
		S_sP(temp->sprite, temp->position);
		Draw_sprite(w->window, temp->sprite, NULL);
		temp = temp->next;
	}
}

static int display_tick(window_s *w, button_s *b)
{
	static sfVector2f arr[10] = { {350, 265}, {550, 265}, {750, 265},
				{950, 265}, {1150, 265}, {350, 500}, {550, 500},
				{750, 500}, {950, 500}, {1150, 500} };
	static int tick_status[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	customer_s *temp = w->customer_l->head;

	if (w->restart == 1) {
		for (int i = 0; i != 11; i++)
			tick_status[i] = -1;
		while (temp != NULL) {
			temp->chosen = 0;
			temp = temp->next;
		}
		w->restart = 0;
	}
	for (int i = 0; i != 10; i++) {
		if (MOUSE_ON_CUSTOMER && MOUSE_LEFT_PRESSED)
			tick_status[i] = if_clicked(w, tick_status[i], i, arr);
	}
	return (display_tick_two(w, arr, tick_status));
}

void display_customer_selection(window_s *w, button_s *b)
{
	static int customer_number;

	Draw_sprite(w->window, w->background->s_bg, NULL);
	display_customers(w);
	customer_number = display_tick(w, b);
	if (customer_number == 5)
		if ((B_IS_CLICKED(b->mouse, V{1186, 671}, V{216, 68}) == 1)
				&& MOUSE_LEFT_PRESSED)
			w->customer_l->on_customer_selection = 0;
}
