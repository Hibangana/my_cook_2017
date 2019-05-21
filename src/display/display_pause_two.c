/*
** EPITECH PROJECT, 2018
** display_pause_three.c
** File description:
** display_pause_three.c
*/

#include "my.h"

int display_pause_three(window_s *w, button_s *b, music_s *m)
{
	if (MOUSE_ON_RESUME && MOUSE_LEFT_PRESSED)
		return (1);
	if (QUIT_GAME_PAUSE && MOUSE_LEFT_PRESSED) {
		sfMusic_destroy(m->end_win_music);
		sfMusic_destroy(m->end_lose_music);
		sfRenderWindow_close(w->window);
		return (1);
	}
	if (MOUSE_ON_M_MENU && MOUSE_LEFT_PRESSED) {
		restart_game(w, m);
		return (1);
	}
	if (w->event.type == sfEvtClosed) {
		sfMusic_destroy(m->end_win_music);
		sfMusic_destroy(m->end_lose_music);
		sfRenderWindow_close(w->window);
		return (1);
	}
	return (0);
}

static void music_handling_pause(button_s *b, music_s *m)
{
	static int play_music;

	if (play_music == 0 && b->sound_clicked == 1) {
		sfMusic_play(m->game_music);
		sfMusic_setLoop(m->game_music, sfTrue);
	}
	play_music = 1;
	if (b->sound_clicked == -1) {
		sfMusic_pause(m->game_music);
		play_music = 0;
	}
}

void pause_sound_effect_manage(window_s *w, button_s *b, music_s *m)
{
	if ((EFFECTS_PAUSE) && (MOUSE_LEFT_PRESSED))
		b->effects_sound_clicked *= -1;
	if ((MUSIC_PAUSE) && (MOUSE_LEFT_PRESSED)) {
		b->sound_clicked *= -1;
		music_handling_pause(b, m);
	}
	if (b->effects_sound_clicked == -1)
		display_pause_cross(w, 1);
	if (b->sound_clicked == -1)
		display_pause_cross(w, 2);
}

void display_pause_four(window_s *w, button_s *b, music_s *m)
{
	if (w->event.type == sfEvtMouseMoved)
		b->mouse = sfMouse_getPosition((sfWindow *)w->window);
	if (QUIT_GAME_PAUSE)
		display_pause_line(w, 2);
	if (MOUSE_ON_RESUME)
		display_pause_line(w, 1);
	if (MOUSE_ON_M_MENU)
		display_pause_line(w, 3);
	pause_sound_effect_manage(w, b, m);
}
