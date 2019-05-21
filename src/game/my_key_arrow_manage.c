/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

void my_keyleft_manage(window_s *w)
{
	if (w->arrow->nb > 1) {
		w->arrow->x -= 266;
		w->arrow->nb--;
	}
}

void my_keyright_manage(window_s *w)
{
	if (w->arrow->nb < 6) {
		w->arrow->x += 266;
		w->arrow->nb++;
	}
}
