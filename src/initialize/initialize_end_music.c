/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

int initialize_end_musics(music_s *m)
{
	m->end_win_music = sfMusic_createFromFile(WINNING_MUSIC);
	m->end_lose_music = sfMusic_createFromFile(LOSING_MUSIC);
	return (0);
}
