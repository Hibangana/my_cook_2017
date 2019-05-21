/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

void send_ingredients_to_dish(int plate_nb, window_s *w, char *plate)
{
	if (plate_nb == 4 && PLATE_FOUR[0] == '\0')
		PLATE_FOUR = my_strcat(PLATE_FOUR, plate);
	if (plate_nb == 5 && PLATE_FIVE[0] == '\0')
		PLATE_FIVE = my_strcat(PLATE_FIVE, plate);
	if (plate_nb == 6 && PLATE_SIX[0] == '\0')
		PLATE_SIX = my_strcat(PLATE_SIX, plate);
}

void plate_check(window_s *w, char *plate)
{
	if (plate[0] != '\0')
		send_ingredients_to_dish((PLATE_NB + 3), w, plate);
	plate[0] = '\0';
}

int check_if_valid(char *plate, window_s *w, int i)
{
	if (plate[0] != '\0') {
		i++;
	if (check_dish(w, plate, i) == 1)
		w->game_hp->score += 100;
	else
		w->game_hp->hp--;
	}
	return (i);
}

void ingredients_on_plate_check(window_s *w)
{
	static int customers_rank;

	if (PLATE_NB == 1)
		plate_check(w, PLATE_ONE);
	if (PLATE_NB == 2)
		plate_check(w, PLATE_TWO);
	if (PLATE_NB == 3)
		plate_check(w, PLATE_THREE);
	if (PLATE_NB == 4) {
		customers_rank = check_if_valid(PLATE_FOUR, w, customers_rank);
		PLATE_FOUR[0] = '\0';
	}
	if (PLATE_NB == 5) {
		customers_rank = check_if_valid(PLATE_FIVE, w, customers_rank);
		PLATE_FIVE[0] = '\0';
	}
	if (PLATE_NB == 6) {
		customers_rank = check_if_valid(PLATE_SIX, w, customers_rank);
		PLATE_SIX[0] = '\0';
	}
	end_game_management(w, customers_rank);
}

void my_cleaning_plate(window_s *w)
{
	if (PLATE_NB == 1)
		PLATE_ONE[0] = '\0';
	if (PLATE_NB == 2)
		PLATE_TWO[0] = '\0';
	if (PLATE_NB == 3)
		PLATE_THREE[0] = '\0';
	if (PLATE_NB == 4)
		PLATE_FOUR[0] = '\0';
	if (PLATE_NB == 5)
		PLATE_FIVE[0] = '\0';
	if (PLATE_NB == 6)
		PLATE_SIX[0] = '\0';
}
