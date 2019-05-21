/*
** EPITECH PROJECT, 2018
** display_game.c
** File description:
** display_game.c
*/

#include "my.h"

void my_free(window_s *window, music_s *music)
{
	static size_t once;

	if (once == 0) {
		sfMusic_destroy(music->loading_music);
		sfMusic_destroy(music->menu_music);
		sfMusic_destroy(music->game_music);
		sfMusic_destroy(music->mouse_pressed);
		sfRenderWindow_destroy(window->window);
	}
	once++;
}

static void change_screen(window_s *w, button_s *b, music_s *m)
{
	if (sfKeyboard_isKeyPressed(sfKeyEscape) && w->start_menu->on_menu == 1
	&& HIGH_NULL && RECIPE_NULL && HTP_NULL) {
		sfMusic_destroy(m->end_win_music);
		sfMusic_destroy(m->end_lose_music);
		sfRenderWindow_close(w->window);
	}
	if (sfKeyboard_isKeyPressed(sfKeyEscape) && w->start_menu->on_menu == 0)
		display_pause(w, b, m);
	if (ON_QUIT && w->event.type == sfEvtMouseButtonPressed) {
		sfMusic_destroy(m->end_win_music);
		sfMusic_destroy(m->end_lose_music);
		sfRenderWindow_close(w->window);
	}
}

static int analyse_events(window_s *w, button_s *b, music_s *m)
{
	if (w->event.type == sfEvtClosed) {
		sfMusic_destroy(m->end_win_music);
		sfMusic_destroy(m->end_lose_music);
		sfRenderWindow_close(w->window);
	}
	if (w->event.type == sfEvtMouseMoved)
		b->mouse = sfMouse_getPosition((sfWindow *)w->window);
	if (w->event.type == sfEvtMouseButtonPressed) {
		b->cursor->on_cursor *= -1;
		start_menu_button_handling(w, b, m);
	}
	change_screen(w, b, m);
	return (0);
}

static int display_game_menu_options_intro(window_s *w, button_s *b, music_s *m)
{
	music_handling(w, m);
	display_loading(w, m);
	if (HIGH_ON)
		display_highscore(w);
	if (RECIPE_ON)
		display_recipes(w, b);
	if (HTP_ON)
		display_how_to_play(w);
	if (MENU_ON && ALL_NULL)
		if (display_start_menu(w, b, m))
			return (84);
	if (MENU_NULL)
		display_speech(w, b, m);
	if (MENU_NULL && SPEECH_NULL && !(CUSTOMER_NULL))
		display_customer_selection(w, b);
	if (MENU_NULL && SPEECH_NULL && CUSTOMER_NULL && !(C_DISH_NULL))
		display_customization(w, b);
	if (MENU_NULL && SPEECH_NULL && CUSTOMER_NULL && C_DISH_NULL)
		display_main_game(w, b, m);
	return (0);
}

int display_game(window_s *w, button_s *b, music_s *m)
{
	while (sfRenderWindow_isOpen(w->window)) {
		while (sfRenderWindow_pollEvent(w->window, &(w->event)))
			analyse_events(w, b, m);
		display_game_menu_options_intro(w, b, m);
		display_cursor(w, b);
		sfRenderWindow_display(w->window);
		sfRenderWindow_clear(w->window, sfBlack);
	}
	write_player_score(w);
	garbage_collector(NULL, 0);
	my_free(w, m);
	return (0);
}
