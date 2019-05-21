/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

static void write_player_name_two(int fd, char *player_name)
{
	if (fd != -1) {
		if (player_name != NULL) {
			write(fd, player_name, my_strlen(player_name));
		} else
			write(fd, "unknown_player",
			my_strlen("unknown_player"));
	}
}

void write_player_name(char *player_name)
{
	int fd = open("scoreboard", O_WRONLY | O_APPEND | O_CREAT, 0444);
	static size_t once;

	if (once == 0)
		write_player_name_two(fd, player_name);
	once++;
	close(fd);
}
