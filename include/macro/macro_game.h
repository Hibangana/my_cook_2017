/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#ifndef MACRO_GAME_H_
#define MACRO_GAME_H_

#define GAME_GUIDE_SPRITE w->game_guide->s_game_guide
#define GAME_GUIDE_TEXTURE w->game_guide->t_game_guide
#define GAME_HP_ONE_SPRITE w->game_hp->s_game_hp_one
#define GAME_HP_TWO_SPRITE w->game_hp->s_game_hp_two
#define GAME_HP_THREE_SPRITE w->game_hp->s_game_hp_three
#define GAME_HP_TEXTURE w->game_hp->t_game_hp
#define MY_GAME_HP w->game_hp->hp
#define PLATE_NB w->arrow->nb
#define PLATE_ONE w->arrow->plate_one
#define PLATE_TWO w->arrow->plate_two
#define PLATE_THREE w->arrow->plate_three
#define PLATE_FOUR w->arrow->plate_four
#define PLATE_FIVE w->arrow->plate_five
#define PLATE_SIX w->arrow->plate_six
#define PLATE_BOARD w->arrow->board
#define PLATE_ONE_NULL (w->arrow->plate_one == NULL)
#define PLATE_TWO_NULL (w->arrow->plate_two == NULL)
#define PLATE_THREE_NULL (w->arrow->plate_three == NULL)
#define PLATE_FOUR_NULL (w->arrow->plate_four == NULL)
#define PLATE_FIVE_NULL (w->arrow->plate_five == NULL)
#define PLATE_SIX_NULL (w->arrow->plate_six == NULL)
#define BOARD_NULL (w->arrow->board == NULL)
#define GARB_PLATE_ONE garbage_collector((char *)w->arrow->plate_one, 1)
#define GARB_PLATE_TWO garbage_collector((char *)w->arrow->plate_two, 1)
#define GARB_PLATE_THREE garbage_collector((char *)w->arrow->plate_three, 1)
#define GARB_PLATE_FOUR garbage_collector((char *)w->arrow->plate_four, 1)
#define GARB_PLATE_FIVE garbage_collector((char *)w->arrow->plate_five, 1)
#define GARB_PLATE_SIX garbage_collector((char *)w->arrow->plate_six, 1)
#define GARB_BOARD garbage_collector((char *)w->arrow->board, 1)
#define PREP_TEXTURE w->prep_board->t_prep
#define PREP_ONE_SPRITE w->prep_board->s_prep_one
#define PREP_TWO_SPRITE w->prep_board->s_prep_two
#define PREP_THREE_SPRITE w->prep_board->s_prep_three
#define BAD_DISH_TEXTURE w->bad_dish->t_bad_dish
#define BAD_DISH_ONE_SPRITE w->bad_dish->s_bad_dish_one
#define BAD_DISH_TWO_SPRITE w->bad_dish->s_bad_dish_two
#define BAD_DISH_THREE_SPRITE w->bad_dish->s_bad_dish_three
#define BUBBLE_ONE w->bubbles->s_bubble_one
#define BUBBLE_TWO w->bubbles->s_bubble_two
#define BUBBLE_THREE w->bubbles->s_bubble_three
#define BUBBLE_FOUR w->bubbles->s_bubble_four
#define BUBBLE_FIVE w->bubbles->s_bubble_five
#define WIN_END_T w->end_board->t_win_board
#define LOSE_END_T w->end_board->t_lose_board
#define WIN_END_S w->end_board->s_win_board
#define LOSE_END_S w->end_board->s_lose_board

#endif
