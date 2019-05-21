/*
** EPITECH PROJECT, 2018
** music_handling.c
** File description:
** music_handling.c
*/

#include "my.h"

void music_handling(window_s *w, music_s *m)
{
	if (w->start_menu->on_menu == 0)
		sfMusic_pause(m->menu_music);
}
