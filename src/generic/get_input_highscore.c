/*
** EPITECH PROJECT, 2018
** get_input_highscore.c
** File description:
** get_input_highscore.c
*/

#include "my.h"

static size_t draw_player_name_two(window_s *w, char *stock)
{
	if (sfKeyboard_isKeyPressed(sfKeyBack))
		return (1);
	sfText_setString(w->speech->text, stock);
	sfText_setCharacterSize(w->speech->text, 75);
	sfText_setColor(w->speech->text, sfBlue);
	sfText_setFont(w->speech->text, w->speech->font);
	sfText_setPosition(w->speech->text, V{590, 360});
	sfRenderWindow_drawText(w->window, w->speech->text, NULL);
	return (0);
}

static void my_sleep(float length)
{
	static sfTime duration;

	duration.microseconds = length;
	sfSleep(duration);
}

static int get_keyboard(char *stock, int *ascii_values, int i, int j)
{
	if (j < 10) {
		stock[j] = ascii_values[i];
		j++;
		my_sleep(85000.0);
	}
	return (j);
}

static char *draw_player_name(window_s *w, char *keys, int *ascii_values)
{
	static char stock[10];
	static int j = 0;

	if (sfKeyboard_isKeyPressed(sfKeyBack)) {
		j--;
		if (j < 0)
			j = 0;
		stock[j] = '\0';
		draw_player_name_two(w, stock);
		my_sleep(100000.0);
	}
	for (int i = 0; i != 26; i++)
		if (sfKeyboard_isKeyPressed(keys[i]))
			j = get_keyboard(stock, ascii_values, i, j);
	draw_player_name_two(w, stock);
	return (stock);
}

char *get_input_highscore(window_s *w)
{
	static char keys[26] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF,
		sfKeyG, sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM,
		sfKeyN, sfKeyO, sfKeyP, sfKeyQ, sfKeyR, sfKeyS, sfKeyT,
		sfKeyU, sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ};
	static int ascii_values[26] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74,
			75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86,
			87, 88, 89, 90};

	return (draw_player_name(w, keys, ascii_values));
}
