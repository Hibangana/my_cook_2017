/*
** EPITECH PROJECT, 2018
** restart_game.c
** File description:
** restart_game.c
*/

#include "my.h"

void reset_customer_position(window_s *w)
{
	static sfVector2f arr[10] = { {350, 265}, {550, 265}, {750, 265},
				{950, 265}, {1150, 265}, {350, 500}, {550, 500},
				{750, 500}, {950, 500}, {1150, 500} };
	customer_s *temp = w->customer_l->head;
	int i = 0;

	while (temp != NULL) {
		temp->position.x = arr[i].x;
		temp->position.y = arr[i].y;
		i++;
		temp = temp->next;
	}
}

void restart_game(window_s *w, music_s *m)
{
	sfMusic_pause(m->game_music);
	sfMusic_play(m->menu_music);
	sfMusic_play(m->menu_music);
	w->start_menu->on_menu = 1;
	w->speech->speech_number = 0;
	w->speech->on_speech = 1;
	w->customer_l->on_customer_selection = 1;
	w->restart = 1;
	w->once = 0;
	reset_customer_position(w);
	Clear_window(w->window, sfBlack);
}
