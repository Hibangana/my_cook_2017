/*
** EPITECH PROJECT, 2018
** initialize.c
** File description:
** initialize.c
*/

#include "my.h"

static void initialize_window(window_s *w)
{
	w->mode = (sfVideoMode) {1600, 900, 32};
	w->window = W_create(w->mode, "Window", sfResize | sfClose, NULL);
	sfRenderWindow_setFramerateLimit(w->window, 60);
	sfWindow_setMouseCursorVisible((sfWindow *)w->window, sfFalse);
}

static int initialize_loading(window_s *w)
{
	w->loading = malloc(sizeof(loading_s));
	if (w->loading == NULL)
		return (84);
	if (garbage_collector((char *)w->loading, 1))
		return (84);
	w->loading->t_load = T_createFF(LOAD, NULL);
	w->loading->t_dot_one = T_createFF(DOT1, NULL);
	w->loading->t_dot_two = T_createFF(DOT2, NULL);
	w->loading->t_dot_three = T_createFF(DOT3, NULL);
	w->loading->s_load = sfSprite_create();
	w->loading->s_dot_one = sfSprite_create();
	w->loading->s_dot_two = sfSprite_create();
	w->loading->s_dot_three = sfSprite_create();
	S_sTexture(w->loading->s_load, w->loading->t_load, sfTrue);
	S_sTexture(w->loading->s_dot_one, w->loading->t_dot_one, sfTrue);
	S_sTexture(w->loading->s_dot_two, w->loading->t_dot_two, sfTrue);
	S_sTexture(w->loading->s_dot_three, w->loading->t_dot_three, sfTrue);
	return (0);
}

static int initialize_start_menu(window_s *w)
{
	w->start_menu = malloc(sizeof(start_menu_s));
	if (w->start_menu == NULL)
		return (84);
	if (garbage_collector((char *)w->start_menu, 1))
		return (84);
	w->start_menu->on_menu = 1;
	w->start_menu->r = (sfIntRect) {0, 0, 1600, 900};
	w->start_menu->t = T_createFF(MENU, NULL);
	w->start_menu->s = sfSprite_create();
	w->restart = 0;
	w->once = 0;
	w->once1 = 0;
	return (0);
}

int initialize(window_s *w, button_s *b, music_s *m)
{
	initialize_window(w);
	if (INIT_PART_ONE || INIT_PART_TWO || INIT_PART_THREE)
		return (84);
	if (initialize_game_arrow(w) || initialize_game_guide(w) ||
	initialize_game_hp(w) || initialize_prep_ingredients(w) ||
	initialize_bad_dish(w) || initialize_dishes(w) ||
	initialize_bubbles(w))
		return (84);
	initialize_ptr(b);
	initialize_end_boards(w);
	initialize_customization(w);
	initialize_end_musics(m);
	return (0);
}
