/*
** EPITECH PROJECT, 2018
** display_loading.c
** File description:
** display_loading.c
*/

#include "my.h"

static void display_loading_two(window_s *w, int nb)
{
	Display_window(w->window);
	Clear_window(w->window, sfBlack);
	Draw_sprite(w->window, w->loading->s_load, NULL);
	if (nb == 1)
		Draw_sprite(w->window, w->loading->s_dot_one, NULL);
	if (nb == 2) {
		Draw_sprite(w->window, w->loading->s_dot_one, NULL);
		Draw_sprite(w->window, w->loading->s_dot_two, NULL);
	}
	if (nb == 3) {
		Draw_sprite(w->window, w->loading->s_dot_one, NULL);
		Draw_sprite(w->window, w->loading->s_dot_two, NULL);
		Draw_sprite(w->window, w->loading->s_dot_three, NULL);
	}
}

static void load_settings(window_s *w)
{
	sfVector2f vect1 = {730, 471};
	sfVector2f vect2 = {768, 471};
	sfVector2f vect3 = {800, 471};

	sfSprite_setPosition(w->loading->s_dot_one, vect1);
	sfSprite_setPosition(w->loading->s_dot_two, vect2);
	sfSprite_setPosition(w->loading->s_dot_three, vect3);
}

static int my_loop(window_s *w, int nb, float seconds)
{
	if (seconds < 2) {
		nb = 1;
		display_loading_two(w, nb);
	}
	if (seconds < 4 && seconds > 2) {
		nb = 2;
		display_loading_two(w, nb);
	}
	if (seconds < 6 && seconds > 4) {
		nb = 3;
		display_loading_two(w, nb);
	}
	return (nb);
}

void display_loading(window_s *window, music_s *music)
{
	sfClock *clock = sfClock_create();
	sfTime time;
	float seconds;
	int nb = 0;
	static int count = 0;

	if (count != 0)
		return;
	count++;
	load_settings(window);
	time = sfClock_getElapsedTime(clock);
	seconds = time.microseconds / 1000000.0;
	while (seconds < 6.5) {
		time = sfClock_getElapsedTime(clock);
		seconds = time.microseconds / 1000000.0;
		display_loading_two(window, nb);
		nb = my_loop(window, nb, seconds);
	}
	sfMusic_stop(music->loading_music);
}
