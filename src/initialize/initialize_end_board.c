/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

int initialize_end_boards(window_s *w)
{
	w->end_board = malloc(sizeof(end_board_s));
	if (w->end_board == NULL)
		return (84);
	if (garbage_collector((char *)w->end_board, 1))
		return (84);
	w->end_board->status = 0;
	WIN_END_T = T_createFF(GAME_VICTORY, NULL);
	LOSE_END_T = T_createFF(GAME_DEFEAT, NULL);
	WIN_END_S = sfSprite_create();
	LOSE_END_S = sfSprite_create();
	S_sTexture(WIN_END_S, WIN_END_T, sfTrue);
	S_sTexture(LOSE_END_S, LOSE_END_T, sfTrue);
	return (0);
}
