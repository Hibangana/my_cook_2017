/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

int my_plate_alloc(window_s *w)
{
	w->arrow->plate_one = malloc(sizeof(char) * 1024);
	w->arrow->plate_two = malloc(sizeof(char) * 1024);
	w->arrow->plate_three = malloc(sizeof(char) * 1024);
	w->arrow->plate_four = malloc(sizeof(char) * 1024);
	w->arrow->plate_five = malloc(sizeof(char) * 1024);
	w->arrow->plate_six = malloc(sizeof(char) * 1024);
	w->arrow->board = malloc(sizeof(char) * 10);
	if (PLATE_ONE_NULL || PLATE_TWO_NULL || PLATE_THREE_NULL ||
	PLATE_FOUR_NULL || PLATE_FIVE_NULL || PLATE_SIX_NULL || BOARD_NULL)
		return (84);
	if (GARB_PLATE_ONE || GARB_PLATE_TWO || GARB_PLATE_THREE ||
	GARB_PLATE_FOUR || GARB_PLATE_FIVE || GARB_PLATE_SIX || GARB_BOARD)
		return (84);
	w->arrow->plate_one[0] = '\0';
	w->arrow->plate_two[0] = '\0';
	w->arrow->plate_three[0] = '\0';
	w->arrow->plate_four[0] = '\0';
	w->arrow->plate_five[0] = '\0';
	w->arrow->plate_six[0] = '\0';
	return (0);
}

int initialize_game_arrow(window_s *w)
{
	w->arrow = malloc(sizeof(arrow_s));
	if (w->arrow == NULL)
		return (84);
	if (garbage_collector((char *)w->arrow, 1))
		return (84);
	if (my_plate_alloc(w) == 84)
		return (84);
	w->arrow->nb = 1;
	w->arrow->x = 85;
	w->arrow->y = 720;
	w->arrow->t_arrow = T_createFF(ARROW_FILE, NULL);
	w->arrow->s_arrow = sfSprite_create();
	S_sTexture(w->arrow->s_arrow, w->arrow->t_arrow, sfTrue);
	return (0);
}

int initialize_game_guide(window_s *w)
{
	w->game_guide = malloc(sizeof(game_guide_s));
	if (w->game_guide == NULL)
		return (84);
	if (garbage_collector((char *)w->game_guide, 1))
		return (84);
	w->game_guide->t_game_guide = T_createFF(IN_GAME_GUIDE, NULL);
	w->game_guide->s_game_guide = sfSprite_create();
	S_sTexture(GAME_GUIDE_SPRITE, GAME_GUIDE_TEXTURE, sfTrue);
	return (0);
}

static int initialize_game_hp_two(window_s *w)
{
	sfVector2f vect = {3, 53};
	sfVector2f vect2 = {95, 53};
	sfVector2f vect3 = {190, 53};

	sfSprite_setPosition(GAME_HP_ONE_SPRITE, vect);
	sfSprite_setPosition(GAME_HP_TWO_SPRITE, vect2);
	sfSprite_setPosition(GAME_HP_THREE_SPRITE, vect3);
	w->game_hp->score = 0;
	return (0);
}

int initialize_game_hp(window_s *w)
{
	w->game_hp = malloc(sizeof(game_hp_s));
	if (w->game_hp == NULL)
		return (84);
	if (garbage_collector((char *)w->game_hp, 1))
		return (84);
	w->game_hp->hp = 3;
	w->game_hp->t_game_hp = T_createFF(GAME_HP, NULL);
	w->game_hp->s_game_hp_one = sfSprite_create();
	w->game_hp->s_game_hp_two = sfSprite_create();
	w->game_hp->s_game_hp_three = sfSprite_create();
	S_sTexture(GAME_HP_ONE_SPRITE, GAME_HP_TEXTURE, sfTrue);
	S_sTexture(GAME_HP_TWO_SPRITE, GAME_HP_TEXTURE, sfTrue);
	S_sTexture(GAME_HP_THREE_SPRITE, GAME_HP_TEXTURE, sfTrue);
	initialize_game_hp_two(w);
	return (0);
}
