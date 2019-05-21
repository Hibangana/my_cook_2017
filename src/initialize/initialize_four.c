/*
** EPITECH PROJECT, 2018
** initialize_four.c
** File description:
** initialize_four.c
*/

#include "my.h"

int initialize_button(button_s *b)
{
	b->mouse.x = -1;
	b->mouse.x = -1;
	b->sound_clicked = 1;
	b->effects_sound_clicked = 1;
	initialize_button_two(b);
	b->sound->shape = init_shape(b->sound->shape, V{1450, 670}, V{90, 90});
	b->effects_sound->shape = init_shape(INIT_EFFECTS_SOUND);
	return (0);
}

int initialize_speech(window_s *w)
{
	w->speech = malloc(sizeof(speech_s));
	if (w->speech == NULL)
		return (84);
	if (garbage_collector((char *)w->speech, 1))
		return (84);
	w->speech->font = sfFont_createFromFile("font/bonzai.ttf");
	w->speech->text = sfText_create();
	w->speech->on_speech = 1;
	w->speech->speech_number = 0;
	w->speech->texture = T_createFF(SPEECH_1, NULL);
	w->speech->sprite = sfSprite_create();
	S_sTexture(w->speech->sprite, w->speech->texture, sfTrue);
	return (0);
}

int initialize_highscore(window_s *w)
{
	w->highscore = malloc(sizeof(highscore_s));
	if (w->highscore == NULL)
		return (84);
	if (garbage_collector((char *)w->highscore, 1))
		return (84);
	w->highscore->on_highscore = 0;
	w->highscore->texture = T_createFF(HIGHSCORE, NULL);
	w->highscore->sprite = sfSprite_create();
	S_sTexture(w->highscore->sprite, w->highscore->texture, sfTrue);
	return (0);
}

int initialize_recipes_board(window_s *w)
{
	w->recipes = malloc(sizeof(recipes_s));
	if (w->recipes == NULL)
		return (84);
	if (garbage_collector((char *)w->recipes, 1))
		return (84);
	w->recipes->on_recipes = 0;
	w->recipes->texture = T_createFF(RECIPES, NULL);
	w->recipes->sprite = sfSprite_create();
	S_sTexture(w->recipes->sprite, w->recipes->texture, sfTrue);
	return (0);
}

int initialize_how_to_play(window_s *w)
{
	w->how_to_play = malloc(sizeof(how_to_play_s));
	if (w->how_to_play == NULL)
		return (84);
	if (garbage_collector((char *)w->how_to_play, 1))
		return (84);
	w->how_to_play->on_how_to_play = 0;
	w->how_to_play->texture = T_createFF(HOW_TO_PLAY, NULL);
	w->how_to_play->sprite = sfSprite_create();
	S_sTexture(w->how_to_play->sprite, w->how_to_play->texture, sfTrue);
	return (0);
}
