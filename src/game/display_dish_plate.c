/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

void display_game_bad_dish(window_s *w, int nb)
{
	if (nb == 4)
		Draw_sprite(w->window, BAD_DISH_ONE_SPRITE, NULL);
	if (nb == 5)
		Draw_sprite(w->window, BAD_DISH_TWO_SPRITE, NULL);
	if (nb == 6)
		Draw_sprite(w->window, BAD_DISH_THREE_SPRITE, NULL);
}

void display_dish_plate(window_s *w)
{
	if (PLATE_FOUR[0] != '\0' && (dish_valid_checking(w, PLATE_FOUR)) == 1)
		display_game_bad_dish(w, 4);
	if (PLATE_FOUR[0] != '\0' && (dish_valid_checking(w, PLATE_FOUR)) == 0)
		draw_the_valid_dish(w, PLATE_FOUR, 4);
	if (PLATE_FIVE[0] != '\0' && (dish_valid_checking(w, PLATE_FIVE)) == 1)
		display_game_bad_dish(w, 5);
	if (PLATE_FIVE[0] != '\0' && (dish_valid_checking(w, PLATE_FIVE)) == 0)
		draw_the_valid_dish(w, PLATE_FIVE, 5);
	if (PLATE_SIX[0] != '\0' && (dish_valid_checking(w, PLATE_SIX)) == 1)
		display_game_bad_dish(w, 6);
	if (PLATE_SIX[0] != '\0' && (dish_valid_checking(w, PLATE_SIX)) == 0)
		draw_the_valid_dish(w, PLATE_SIX, 6);
}

void draw_the_valid_dish_two(window_s *w, char *str, sfVector2f position,
			ingredient_s *temp)
{
	while (temp != NULL) {
		if (my_strcmp(str, temp->ingredients) == 1) {
			sfSprite_setPosition(temp->sprite, position);
			Draw_sprite(w->window, temp->sprite, NULL);
		}
		temp = temp->next;
	}
}

void draw_the_valid_dish(window_s *w, char *str, int plate_nb)
{
	sfVector2f vect4 = {845, 760};
	sfVector2f vect5 = {1135, 760};
	sfVector2f vect6 = {1415, 760};
	ingredient_s *temp = w->dishes_l->head;

	if (plate_nb == 4)
		draw_the_valid_dish_two(w, str, vect4, temp);
	if (plate_nb == 5)
		draw_the_valid_dish_two(w, str, vect5, temp);
	if (plate_nb == 6)
		draw_the_valid_dish_two(w, str, vect6, temp);
}

int dish_valid_checking(window_s *w, char *dish)
{
	int count = 0;
	ingredient_s *element = w->dishes_l->head;

	while (element != NULL) {
		if (my_strcmp(element->ingredients, dish) == 1 &&
		my_strlen(element->ingredients) == my_strlen(dish)) {
			count++;
		}
		element = element->next;
	}
	if (count == 0)
		return (1);
	return (0);
}
