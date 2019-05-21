/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

int initialize_bad_dish(window_s *w)
{
	sfVector2f vect1 = {800, 710};
	sfVector2f vect2 = {1090, 710};
	sfVector2f vect3 = {1375, 710};

	w->bad_dish = malloc(sizeof(bad_dish_s));
	if (w->bad_dish == NULL)
		return (84);
	if (garbage_collector((char *)w->bad_dish, 1))
		return (84);
	BAD_DISH_TEXTURE = T_createFF(BAD_DISH_PIC, NULL);
	BAD_DISH_ONE_SPRITE = sfSprite_create();
	BAD_DISH_TWO_SPRITE = sfSprite_create();
	BAD_DISH_THREE_SPRITE = sfSprite_create();
	S_sTexture(BAD_DISH_ONE_SPRITE, BAD_DISH_TEXTURE, sfTrue);
	S_sTexture(BAD_DISH_TWO_SPRITE, BAD_DISH_TEXTURE, sfTrue);
	S_sTexture(BAD_DISH_THREE_SPRITE, BAD_DISH_TEXTURE, sfTrue);
	sfSprite_setPosition(BAD_DISH_ONE_SPRITE, vect1);
	sfSprite_setPosition(BAD_DISH_TWO_SPRITE, vect2);
	sfSprite_setPosition(BAD_DISH_THREE_SPRITE, vect3);
	return (0);
}

int initialize_prep_ingredients(window_s *w)
{
	sfVector2f vect1 = {65, 720};
	sfVector2f vect2 = {325, 720};
	sfVector2f vect3 = {585, 720};

	w->prep_board = malloc(sizeof(prep_board_s));
	if (w->prep_board == NULL)
		return (84);
	if (garbage_collector((char *)w->prep_board, 1))
		return (84);
	PREP_TEXTURE = T_createFF(PREP_BOARD_PIC, NULL);
	PREP_ONE_SPRITE = sfSprite_create();
	PREP_TWO_SPRITE = sfSprite_create();
	PREP_THREE_SPRITE = sfSprite_create();
	S_sTexture(PREP_ONE_SPRITE, PREP_TEXTURE, sfTrue);
	S_sTexture(PREP_TWO_SPRITE, PREP_TEXTURE, sfTrue);
	S_sTexture(PREP_THREE_SPRITE, PREP_TEXTURE, sfTrue);
	sfSprite_setPosition(PREP_ONE_SPRITE, vect1);
	sfSprite_setPosition(PREP_TWO_SPRITE, vect2);
	sfSprite_setPosition(PREP_THREE_SPRITE, vect3);
	return (0);
}
