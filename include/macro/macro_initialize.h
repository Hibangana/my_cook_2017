/*
** EPITECH PROJECT, 2018
** macro_initialize.h
** File description:
** macro_initialize.h
*/

#ifndef MACRO_INITIALIZE_H_
#define MACRO_INITIALIZE_H_

#define INIT_PART_ONE INIT_ONE || INIT_TWO || INIT_THREE || INIT_FOUR
#define INIT_PART_TWO INIT_FIVE || INIT_SIX || INIT_SEVEN || INIT_EIGHT
#define INIT_PART_THREE INIT_NINE
#define INIT_ONE initialize_loading(w) || initialize_start_menu(w)
#define INIT_TWO initialize_button(b) || initialize_music(m)
#define INIT_THREE initialize_pause(w) || initialize_pause_line_cross(w)
#define INIT_FOUR initialize_background(w) || initialize_customer(w)
#define INIT_FIVE initialize_tick(w) || initialize_start_button(w)
#define INIT_SIX initialize_speech(w) || initialize_highscore(w)
#define INIT_SEVEN initialize_recipes_board(w) || initialize_how_to_play(w)
#define INIT_EIGHT initialize_square_recipe(w) || initialize_recipes_info(w)
#define INIT_NINE initialize_game_background(w) || initialize_cursor(b)

#endif
