/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

static void end_music_player(int toggle, button_s *b, music_s *m)
{
	sfMusic_pause(m->game_music);
	if (toggle == 1 && b->sound_clicked == 1)
		sfMusic_play(m->end_win_music);
	if (toggle == 0 && b->sound_clicked == 1)
		sfMusic_play(m->end_lose_music);
}

static void end_pannel(int toggle, window_s *w)
{
	Display_window(w->window);
	Clear_window(w->window, sfBlack);
	if (toggle == 1)
		Draw_sprite(w->window, WIN_END_S, NULL);
	else
		Draw_sprite(w->window, LOSE_END_S, NULL);
}
void display_end_board(window_s *w, button_s *b, music_s *m, int toggle)
{
	int status = 0;

	write_player_score(w);
	end_music_player(toggle, b, m);
	while (w->event.key.code != sfKeyEscape) {
		sfRenderWindow_pollEvent(w->window, &w->event);
		end_pannel(toggle, w);
		if (w->event.type == sfEvtClosed) {
			status = 1;
			sfMusic_destroy(m->end_win_music);
			sfMusic_destroy(m->end_lose_music);
			w->event.key.code = sfKeyEscape;
			sfRenderWindow_close(w->window);
		}
	}
	if (status != 1) {
		sfMusic_destroy(m->end_win_music);
		sfMusic_destroy(m->end_lose_music);
		sfRenderWindow_close(w->window);
	}
}

void end_game_management(window_s *w, int customers_rank)
{
	if (w->game_hp->hp == 0)
		w->end_board->status = -1;
	if (customers_rank == 5 && w->game_hp->hp > 0)
		w->end_board->status = 1;
}
