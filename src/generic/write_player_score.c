/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

static void write_player_score_two(window_s *w, int fd)
{
	char *str = malloc(sizeof(char) * 100);

	write(fd, " ", 1);
	str = int_to_char(w->game_hp->score, str);
	write(fd, str, my_strlen(str));
	write(fd, "\n", 1);
}

void write_player_score(window_s *w)
{
	int fd = open("scoreboard", O_WRONLY | O_APPEND | O_CREAT, 0444);
	static size_t once;

	if (once == 0) {
		if (fd != -1)
			write_player_score_two(w, fd);
	}
	once++;
	close(fd);
}
