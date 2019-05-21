/*
** EPITECH PROJECT, 2018
** display_highscore.c
** File description:
** display_highscore.c
*/

#include "my.h"

static char *player_name(char *line, char *line_score)
{
	int i = 0;
	int j = 0;

	for (; line[i] != ' '; i++);
	for (; line[i] != '\0'; i++, j++)
		line_score[j] = line[i];
	line_score[j] = '\0';
	return (line_score);
}

static char *best_player(char *line, char *temp)
{
	char *line_score = malloc(sizeof(char) * my_strlen(line));
	char *temp_score = malloc(sizeof(char) * my_strlen(temp));
	int line_score_nb;
	int temp_score_nb;

	line_score = my_strdup(player_name(line, line_score));
	temp_score = my_strdup(player_name(temp, temp_score));
	line_score_nb = my_getnbr(line_score);
	temp_score_nb = my_getnbr(temp_score);
	if (line_score_nb > temp_score_nb)
		return (line);
	else
		return (temp);
	return (line);
}

static char *write_scores_two(char *greatest, int fd, char *line, char *temp)
{
	static size_t count;

	line = get_next_line(fd);
	if (line == NULL)
		return (greatest = my_strdup("UNKNOWN_PLAYER 0\n"));
	while (line != NULL) {
		temp = my_strdup(line);
		free(line);
		line = get_next_line(fd);
		if (line != NULL && temp != NULL)
			greatest = my_strdup(best_player(line, temp));
		count++;
	}
	if (count == 1)
		greatest = my_strdup(temp);
	return (greatest);
}

static char *write_scores(void)
{
	int fd = open("scoreboard", O_RDONLY);
	char *line = NULL;
	char *temp = NULL;
	char *greatest = NULL;

	if (fd != -1)
		greatest = write_scores_two(greatest, fd, line, temp);
	return (greatest);
	close(fd);
}

int display_highscore(window_s *w)
{
	static size_t once;
	static char *best_player;

	if (once == 0)
		best_player = my_strdup(write_scores());
	if (sfKeyboard_isKeyPressed(sfKeyB))
		w->highscore->on_highscore = 0;
	Draw_sprite(w->window, w->highscore->sprite, NULL);
	display_highscore_two(w, best_player);
	once++;
	return (0);
}
