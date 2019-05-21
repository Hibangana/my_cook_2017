/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

void display_highscore_two(window_s *w, char *best_player)
{
	sfFont *font;
	sfText *text;
	sfVector2f position = {500, 400};

	font = sfFont_createFromFile("font/bonzai.ttf");
	text = sfText_create();
	sfText_setString(text, best_player);
	sfText_setCharacterSize(text, 100);
	sfText_setColor(text, sfBlue);
	sfText_setStyle(text, sfTextBold);
	sfText_setFont(text, font);
	sfText_setPosition(text, position);
	sfRenderWindow_drawText(w->window, text, NULL);
}
