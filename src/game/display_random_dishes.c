/*
** EPITECH PROJECT, 2018
** ds
** File description:
** ds
*/

#include "my.h"

static unsigned int number_from_urandom(char *buffer)
{
	int number = 0;

	for (int i = 0; i < 25; i++) {
		number += buffer[i];
		number *= 10;
	}
	if (number < 0)
		number = -number;
	return (number);
}

int my_random(void)
{
	int fd = open("/dev/urandom", O_RDONLY);
	char str[25];
	int read_bytes;

	if (fd == -1)
		return (84);
	read_bytes = read(fd, str, 25);
	if (read_bytes < 0)
		return (84);
	srand(number_from_urandom(str));
	close(fd);
	return (0);
}

ingredient_s *get_random_dishes(window_s *w)
{
	static int once;
	int k = 0;
	int i = 0;
	ingredient_s *temp = w->dishes_l->head;

	if (once == 0) {
		my_random();
		once++;
	}
	k = rand() % 10;
	while (i != k) {
		temp = temp->next;
		i++;
	}
	return (temp);
}

void display_dishes(window_s *w, sfVector2f position,
		ingredient_s *temp, customer_s *customer)
{
	sfVector2f dish_position = {position.x + 45, 478};

	if (customer->satisfied == 1) {
		S_sTexture(w->bubbles->s_bubble_one,
			w->bubbles->t_good_bubble, sfTrue);
		S_sP(w->bubbles->s_bubble_one, position);
		Draw_sprite(w->window, w->bubbles->s_bubble_one, NULL);
	} else if (customer->satisfied == 0) {
		S_sTexture(w->bubbles->s_bubble_one,
			w->bubbles->t_bad_bubble, sfTrue);
		S_sP(w->bubbles->s_bubble_one, position);
		Draw_sprite(w->window, w->bubbles->s_bubble_one, NULL);
	} else {
		S_sP(temp->bubble_sprite, position);
		Draw_sprite(w->window, temp->bubble_sprite, NULL);
		S_sP(temp->sprite, dish_position);
		Draw_sprite(w->window, temp->sprite, NULL);
	}
}
