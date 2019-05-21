/*
** EPITECH PROJECT, 2018
** display.h
** File description:
** display.h
*/

#ifndef DISPLAY_H
#define DISPLAY_H

ingredient_s *get_random_dishes(window_s *);
void display_customers_dishes(window_s *);
void display_in_game_customers(window_s *);
void restart_game(window_s *, music_s *);
void display_usage(void);
void display_loading(window_s *, music_s *);
void display_customer_selection(window_s *, button_s *);
void display_pause(window_s *, button_s *, music_s *);
void display_pause_four(window_s *, button_s *, music_s *);
void display_start_button(window_s *);
void display_cursor(window_s *, button_s *);
void display_pan(window_s *, size_t);
void display_dishes(window_s *, sfVector2f, ingredient_s *, customer_s *);
int display_start_menu(window_s *, button_s *, music_s *);
int display_pause_cross(window_s *, int );
int display_pause_line(window_s *, int);
int display_game(window_s *, button_s *, music_s *);
int display_pause_three(window_s *, button_s *, music_s *);
int display_tick_two(window_s *, sfVector2f *, int *);
void display_speech(window_s *, button_s *, music_s *);
int display_highscore(window_s *);
int display_how_to_play(window_s *);
int display_recipes(window_s *, button_s *);
int display_main_game(window_s *, button_s *, music_s *);

#endif
