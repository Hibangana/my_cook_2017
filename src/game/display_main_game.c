/*
** EPITECH PROJECT, 2018
** display_main_game.c
** File description:
** display_main_game.c
*/

#include "my.h"

static void display_game_uid(window_s *w)
{
	display_game_hp(w);
	display_customers_dishes(w);
	display_in_game_customers(w);
	display_score(w);
}

static void add_customized_dish(window_s *w)
{
	if (w->c_dish_l->on_one == 1)
		add_customized_dish_two(w, 1);
	if (w->c_dish_l->on_two == 1)
		add_customized_dish_two(w, 2);
	if (w->c_dish_l->on_three == 1)
		add_customized_dish_two(w, 3);
}

int display_main_game(window_s *w, button_s *b, music_s *m)
{
	static size_t once;

	if (once == 0)
		add_customized_dish(w);
	if (w->end_board->status == 0) {
		Draw_sprite(w->window, w->game_bg->sprite, NULL);
		display_game_uid(w);
		my_game_button_manager(w, b, m);
	}
	if (w->end_board->status != 0) {
		if (w->end_board->status > 0)
			display_end_board(w, b, m, 1);
		if (w->end_board->status < 0)
			display_end_board(w, b, m, 0);
	}
	once++;
	return (0);
}
