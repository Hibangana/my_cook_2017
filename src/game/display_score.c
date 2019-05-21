/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

void my_reverse(char str[], int len)
{
	int start;
	int end;
	char temp;

	for (start = 0, end = len - 1; start < end; start++, end--) {
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}

char *int_to_char(int score, char *str)
{
	int i = 0;
	int rem;

	if (score == 0) {
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	while (score != 0) {
		rem = score % 10;
		str[i++] = (rem > 9) ? (rem-10) + 'A' : rem + '0';
		score = score / 10;
	}
	str[i] = '\0';
	my_reverse(str, i);
	return (str);
}

void display_score(window_s *w)
{
	sfFont *font;
	sfText *text;
	sfVector2f position = {260, 120};
	char *str = malloc(sizeof(char) * 100);

	str = int_to_char(w->game_hp->score, str);
	font = sfFont_createFromFile("font/bonzai.ttf");
	text = sfText_create();
	sfText_setString(text, str);
	sfText_setCharacterSize(text, 100);
	sfText_setColor(text, sfBlue);
	sfText_setStyle(text, sfTextBold);
	sfText_setFont(text, font);
	sfText_setPosition(text, position);
	sfRenderWindow_drawText(w->window, text, NULL);
}
