/*
** EPITECH PROJECT, 2018
** macro_mouse_in_game_pause.h
** File description:
** macro_mouse_in_game_pause.h
*/

#ifndef MACRO_MOUSE_IN_GAME_PAUSE_H_
#define MACRO_MOUSE_IN_GAME_PAUSE_H_

#define MOUSE_ON_RESUME buttonisclicked(b->mouse, V{687, 382}, V{219, 53}) == 1
#define MOUSE_ON_M_MENU buttonisclicked(b->mouse, V{665, 466}, V{297, 51}) == 1
#define QUIT_GAME_PAUSE buttonisclicked(b->mouse, V{598, 548}, V{421, 56}) == 1
#define EFFECTS_PAUSE buttonisclicked(b->mouse, V{249, 618}, V{131, 90}) == 1
#define MUSIC_PAUSE buttonisclicked(b->mouse, V{380, 618}, V{95, 92}) == 1

#endif
