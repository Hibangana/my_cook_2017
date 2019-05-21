/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "my.h"

static int create_scoreboard_file(void)
{
	FILE *file_ptr = fopen("scoreboard", "ab+");

	if (file_ptr == NULL)
		return (84);
	return (0);
}

static int game(void)
{
	window_s window_s;
	button_s button_s;
	music_s music_s;

	if (initialize(&window_s, &button_s, &music_s))
		return (84);
	if (create_scoreboard_file())
		return (84);
	if (display_game(&window_s, &button_s, &music_s))
		return (84);
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	if (envp[0] == NULL)
		return (84);
	if (argc == 2) {
		if (argv[1][0] == '-' && argv[1][1] == 'h') {
			display_usage();
			return (0);
		}
	}
	if (argc != 1)
		return (84);
	if (game())
		return (84);
	return (0);
}
