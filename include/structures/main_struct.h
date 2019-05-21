/*
** EPITECH PROJECT, 2018
** main_struct.h
** File description:
** main_struct.h
*/

#ifndef MAIN_STRUCT_H
#define MAIN_STRUCT_H
#include "my.h"

typedef struct music_s {
	size_t end_game_music_on;
	sfMusic *loading_music;
	sfMusic *menu_music;
	sfMusic *game_music;
	sfMusic *mouse_pressed;
	sfMusic *end_win_music;
	sfMusic *end_lose_music;
} music_s;

typedef struct window_s {
	sfRenderWindow* window;
	sfVideoMode mode;
	sfEvent event;
	struct ingredient_s *ingredient_s;
	struct ingredient_l *ingredient_l;
	struct ingredient_l *dishes_l;
	struct recipes_info_s *recipes_info_s;
	struct recipes_info_l *recipes_info_l;
	struct customer_s *customer_s;
	struct customer_l *customer_l;
	struct start_menu_s *start_menu;
	struct loading_s *loading;
	struct pause_s *pause;
	struct background_s *background;
	struct pause_line_s *pause_line;
	struct tick_s *tick;
	struct start_button_s *start_button;
	struct speech_s *speech;
	struct highscore_s *highscore;
	struct recipes_s *recipes;
	struct how_to_play_s *how_to_play;
	struct square_s *square;
	struct arrow_s *arrow;
	struct game_guide_s *game_guide;
	struct game_bg_s *game_bg;
	struct game_hp_s *game_hp;
	struct prep_board_s *prep_board;
	struct bad_dish_s *bad_dish;
	struct bubbles_s *bubbles;
	struct end_board_s *end_board;
	struct c_dish_l *c_dish_l;
	size_t restart;
	size_t once;
	size_t once1;
} window_s;

typedef struct button_s {
	sfVector2i mouse;
	int sound_clicked;
	int effects_sound_clicked;
	struct cursor_s *cursor;
	struct underlign_s *underlign;
	struct sound_s *sound;
	struct effects_sound_s *effects_sound;
} button_s;

#endif
