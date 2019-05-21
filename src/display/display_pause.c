/*
** EPITECH PROJECT, 2018
** display_pause.c
** File description:
** display_pause.c
*/

#include "my.h"

int display_pause_line(window_s *w, int nb)
{
	if (nb == 1) {
		S_sP(w->pause_line->s_p_line, V{705, 440});
		Draw_sprite(w->window, w->pause_line->s_p_line, NULL);
	}
	if (nb == 2) {
		S_sP(w->pause_line->s_p_line, V{705, 610});
		Draw_sprite(w->window, w->pause_line->s_p_line, NULL);
	}
	if (nb == 3) {
		S_sP(w->pause_line->s_p_line, V{705, 520});
		Draw_sprite(w->window, w->pause_line->s_p_line, NULL);
	}
	return (0);
}

int display_pause_cross(window_s *w, int nb)
{
	if (nb == 1) {
		S_sP(w->pause_line->s_p_cross, V{233, 590});
		Draw_sprite(w->window, w->pause_line->s_p_cross, NULL);
	}
	if (nb == 2) {
		S_sP(w->pause_line->s_p_cross, V{371, 583});
		Draw_sprite(w->window, w->pause_line->s_p_cross, NULL);
	}
	return (0);
}

static int play_music(window_s *w, button_s *b, music_s *m)
{
	if (w->event.type == sfEvtMouseButtonPressed) {
		b->cursor->on_cursor *= -1;
		if (b->effects_sound_clicked == 1)
			sfMusic_play(m->mouse_pressed);
	}
	return (0);
}

static int display_pause_two(window_s *w, button_s *b, music_s *m)
{
	while (sfRenderWindow_pollEvent(w->window, &(w->event))) {
		play_music(w, b, m);
		Draw_sprite(w->window, w->pause->s_pause, NULL);
		if (display_pause_three(w, b, m) == 1)
			return (1);
		display_pause_four(w, b, m);
		display_cursor(w, b);
		Display_window(w->window);
		Clear_window(w->window, sfBlack);
	}
	return (0);
}

void display_pause(window_s *w, button_s *b, music_s *m)
{
	while (display_pause_two(w, b, m) != 1);
}
