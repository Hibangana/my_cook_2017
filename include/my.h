/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include "../lib/my/include/my.h"
#include "./structures/main_struct.h"
#include "./structures/music_struct.h"
#include "./structures/window_struct.h"
#include "./structures/button_struct.h"
#include "./structures/garbage_collector_struct.h"
#include "./prototypes/display.h"
#include "./macro/main_macro.h"
#include "./macro/macro_files.h"
#include "./macro/macro_csfml_functions.h"
#include "./macro/macro_underlign.h"
#include "./macro/macro_mouse_start_menu.h"
#include "./macro/macro_mouse_in_game_pause.h"
#include "./macro/macro_mouse_in_recipes_menu.h"
#include "./macro/macro_initialize.h"
#include "./macro/macro_game.h"
#include "./macro/macro_recipes.h"

size_t check_dish(window_s *, char *, size_t);
int *reset_customers(window_s *, int *);
int initialize(window_s *, button_s *, music_s *);
int initialize_music(music_s *);
int initialize_pause(window_s *);
int initialize_pause_line_cross(window_s *);
int initialize_background(window_s *);
int initialize_button_two(button_s *);
int initialize_ptr_to_function_underlign(window_s *, button_s *);
int underlign(window_s *, button_s *, sfVector2f, sfVector2f);
int buttonisclicked(sfVector2i, sfVector2f, sfVector2f);
int cursor_position(sfVector2i, start_menu_hitbox_s *);
int initialize_customer(window_s *w);
int initialize_ptr_to_function_underlign(window_s *, button_s *);
int initialize_tick(window_s *);
int initialize_start_button(window_s *);
int initialize_button(button_s *);
int initialize_speech(window_s *);
int initialize_highscore(window_s *);
int initialize_recipes_board(window_s *);
int initialize_dish(window_s *);
int initialize_how_to_play(window_s *);
int initialize_square_recipe(window_s *);
int initialize_recipes_info(window_s *);
int initialize_game_background(window_s *);
int initialize_cursor(button_s *);
int initialize_game_arrow(window_s *w);
int initialize_game_guide(window_s *w);
int initialize_game_hp(window_s *w);
int if_clicked(window_s *, int, int, sfVector2f *);
int initialize_dishes(window_s *);
int initialize_bad_dish(window_s *);
int initialize_prep_ingredients(window_s *);
int dish_valid_checking(window_s *, char *);
void music_handling(window_s *, music_s *);
void draw_the_valid_dish_two(window_s *, char *, sfVector2f, ingredient_s *);
void draw_the_valid_dish(window_s *, char* , int);
void start_menu_button_handling(window_s *, button_s *, music_s *);
void initialize_ptr(button_s *);
int initialize_end_musics(music_s *);
void display_dish_plate(window_s *);
char *get_input_highscore(window_s *);
void play_click_sound(window_s *, button_s *, music_s *, int);
void my_game_button_manager(window_s *, button_s *, music_s *);
void display_game_arrow(window_s *);
void my_keyleft_manage(window_s *);
void my_keyright_manage(window_s *);
void display_in_game_guide(window_s *, button_s *, music_s *);
void display_hp_and_score(window_s *, button_s *, music_s *);
void display_game_hp(window_s *);
void ingredients_on_plate_check(window_s *);
void my_cleaning_plate(window_s *);
void write_player_name(char *);
void display_game_prep(window_s *);
void display_game_bad_dish(window_s *, int);
void display_highscore_two(window_s *, char *);
void end_game_management(window_s *, int);
void display_end_board(window_s *, button_s *, music_s *, int);
int check_dish_new(window_s *, char *, int);
int initialize_bubbles(window_s *);
int initialize_end_boards(window_s *);
rectangle_shape *init_shape(rectangle_shape *, sfVector2f, sfVector2f);
void display_score(window_s *);
void write_score(window_s *);
void write_player_score(window_s *);
char *int_to_char(int, char *);
void my_reverse(char *, int);
void my_free(window_s *, music_s *);
size_t initialize_customization(window_s *);
void display_customization(window_s *, button_s *);
void display_start_button_cust(window_s *, int);
size_t display_choice(window_s *);
size_t add_customized_dish_two(window_s *, size_t);

#endif
