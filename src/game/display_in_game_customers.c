/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

static void initialize_customer_position(customer_s *temp)
{
	sfVector2f position = {200, -1000};

	while (temp != NULL) {
		if (temp->chosen == 1) {
			temp->position.x = position.x;
			temp->position.y = position.y;
			position.y -= position.y;
		}
		temp = temp->next;
	}
}

void display_in_game_customers(window_s *w)
{
	customer_s *temp = w->customer_l->head;
	sfVector2f position = {200, 620};

	if (w->once == 0)
		initialize_customer_position(temp);
	while (temp != NULL) {
		if (temp->chosen == 1) {
			temp->rect = (sfIntRect) {0, 0, 120, 120};
			S_sP(temp->sprite, position);
			S_sTextureR(temp->sprite, temp->rect);
			Draw_sprite(w->window, temp->sprite, NULL);
			position.x += 200;
		}
		temp = temp->next;
	}
	w->once++;
}
