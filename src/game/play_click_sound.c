/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

void add_in_array(int plate_nb, window_s *w, char *new_ingredient)
{
	if (plate_nb == 1)
		my_strcat(w->arrow->plate_one, new_ingredient);
	if (plate_nb == 2)
		my_strcat(w->arrow->plate_two, new_ingredient);
	if (plate_nb == 3)
		my_strcat(w->arrow->plate_three, new_ingredient);
}

void play_click_sound(window_s *w, button_s *b, music_s *m, int nb)
{
	if (b->effects_sound_clicked == 1)
		sfMusic_play(m->mouse_pressed);
	if ((nb >= 0 && nb <= 9) && (w->arrow->nb >= 1 && w->arrow->nb <= 3)) {
		PLATE_BOARD[0] = nb + 48;
		PLATE_BOARD[1] = '\0';
		add_in_array(w->arrow->nb, w, PLATE_BOARD);
	}
	for (int i = 0; i != 100000000; i++);
}
