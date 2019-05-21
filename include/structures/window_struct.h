/*
** EPITECH PROJECT, 2018
** window.h
** File description:
** window.h
*/

#ifndef WINDOW_H
#define WINDOW_H

typedef struct ingredient_s {
	char *name;
	char *ingredients;
	struct sfTexture *texture;
	struct sfSprite *sprite;
	struct sfTexture *bubble_texture;
	struct sfSprite *bubble_sprite;
	struct ingredient_s *next;
} ingredient_s;

typedef struct ingredient_l {
	struct ingredient_s *head;
	size_t nb_dishes;
} ingredient_l;

typedef struct game_bg_s {
	struct sfTexture *texture;
	struct sfSprite *sprite;
} game_bg_s;

typedef struct recipes_info_s {
	int number;
	struct sfTexture *texture;
	struct sfSprite *sprite;
	struct recipes_info_s *next;
} recipes_info_s;

typedef struct recipes_info_l {
	struct recipes_info_s *head;
} recipes_info_l;

typedef struct recipes_s {
	int on_recipes;
	struct sfTexture *texture;
	struct sfSprite *sprite;
} recipes_s;

typedef struct how_to_play_s {
	int on_how_to_play;
	struct sfTexture *texture;
	struct sfSprite *sprite;
} how_to_play_s;

typedef struct highscore_s {
	int on_highscore;
	struct sfTexture *texture;
	struct sfSprite *sprite;
} highscore_s;

typedef struct speech_s {
	int speech_number;
	int on_speech;
	struct sfTexture *texture;
	struct sfSprite *sprite;
	sfText *text;
	sfFont *font;
} speech_s;

typedef struct start_button_s {
	struct sfTexture *texture;
	struct sfSprite *sprite;
} start_button_s;

typedef struct tick_s {
	struct sfTexture *texture;
	struct sfSprite *sprite;
} tick_s;

typedef struct c_dish_l {
	size_t on_customization;
	char *custom_dish_ingredients;
	struct sfTexture *texture;
	struct sfSprite *sprite;
	struct sfTexture *choice_texture;
	struct sfSprite *choice_sprite;
	struct sfTexture *custom_texture;
	struct sfSprite *custom_sprite;
	size_t on_one;
	struct sfTexture *custom_three_texture;
	struct sfSprite *custom_three_sprite;
	size_t on_three;
	struct sfTexture *custom_two_texture;
	struct sfSprite *custom_two_sprite;
	size_t on_two;
	struct sfTexture *existing_texture;
	struct sfSprite *existing_sprite;
} c_dish_l;

typedef struct customer_s {
	struct sfTexture *texture;
	struct sfSprite *sprite;
	sfVector2f position;
	sfIntRect rect;
	int chosen;
	ssize_t satisfied;
	char *dish;
	struct customer_s *next;
	sfClock *clock;
	float seconds;
	sfTime time;
} customer_s;

typedef struct customer_l {
	int on_customer_selection;
	struct customer_s *head;
} customer_l;

typedef struct start_menu_s {
	int on_menu;
	sfIntRect r;
	struct sfSprite *s;
	struct sfTexture *t;
} start_menu_s;

typedef struct loading_s {
	struct sfSprite *s_dot_one;
	struct sfSprite *s_dot_two;
	struct sfSprite *s_dot_three;
	struct sfSprite *s_load;
	struct sfTexture *t_dot_one;
	struct sfTexture *t_dot_two;
	struct sfTexture *t_dot_three;
	struct sfTexture *t_load;
} loading_s;

typedef struct pause_s {
	struct sfSprite *s_pause;
	struct sfTexture *t_pause;
} pause_s;

typedef struct square_s {
	int nb;
	struct sfSprite *s_square;
	struct sfTexture *t_square;
} square_s;

typedef struct arrow_s {
	int nb;
	int x;
	int y;
	char *plate_one;
	char *plate_two;
	char *plate_three;
	char *plate_four;
	char *plate_five;
	char *plate_six;
	char *board;
	struct sfSprite *s_arrow;
	struct sfTexture *t_arrow;
} arrow_s;

typedef struct game_guide_s {
	struct sfSprite *s_game_guide;
	struct sfTexture *t_game_guide;
} game_guide_s;

typedef struct pause_line_s {
	struct sfSprite *s_p_line;
	struct sfSprite *s_p_cross;
	struct sfTexture *t_p_line;
	struct sfTexture *t_p_cross;
} pause_line_s;

typedef struct background_s {
	struct sfSprite *s_bg;
	struct sfTexture *t_bg;
} background_s;

typedef struct game_hp_s {
	struct sfSprite *s_game_hp_one;
	struct sfSprite *s_game_hp_two;
	struct sfSprite *s_game_hp_three;
	struct sfTexture *t_game_hp;
	int hp;
	int score;
} game_hp_s;

typedef struct prep_board_s {
	struct sfSprite *s_prep_one;
	struct sfSprite *s_prep_two;
	struct sfSprite *s_prep_three;
	struct sfTexture *t_prep;
} prep_board_s;

typedef struct bad_dish_s {
	struct sfSprite *s_bad_dish_one;
	struct sfSprite *s_bad_dish_two;
	struct sfSprite *s_bad_dish_three;
	struct sfTexture *t_bad_dish;
} bad_dish_s;

typedef struct bubbles_s {
	struct sfTexture *t_good_bubble;
	struct sfTexture *t_bad_bubble;
	struct sfSprite *s_bubble_one;
	struct sfSprite *s_bubble_two;
	struct sfSprite *s_bubble_three;
	struct sfSprite *s_bubble_four;
	struct sfSprite *s_bubble_five;
} bubbles_s;

typedef struct end_board_s {
	int status;
	struct sfTexture *t_win_board;
	struct sfTexture *t_lose_board;
	struct sfSprite *s_win_board;
	struct sfSprite *s_lose_board;
} end_board_s;

#endif
