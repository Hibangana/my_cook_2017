/*
** EPITECH PROJECT, 2018
** initialize_three.c
** File description:
** initialize_three.c
*/

#include "my.h"

void sound_redcross(button_s *b, window_s *w)
{
	b->sound->t_sound = T_createFF(CROSS, NULL);
	b->sound->s_sound = sfSprite_create();
	RS_sT(b->sound->shape, b->sound->t_sound, sfTrue);
	S_sTexture(b->sound->s_sound, b->sound->t_sound, sfTrue);
	b->sound->r_sound = (sfIntRect) { 0, 0, 150, 150};
	S_sTextureR(b->sound->s_sound, b->sound->r_sound);
	S_sP(b->sound->s_sound, V{1430, 630});
	Draw_sprite(w->window, b->sound->s_sound, NULL);
}

void effects_sound_redcross(button_s *b, window_s *w)
{
	b->effects_sound->t = T_createFF(CROSS, NULL);
	b->effects_sound->s = sfSprite_create();
	RS_sT(b->effects_sound->shape, b->effects_sound->t, sfTrue);
	S_sTexture(b->effects_sound->s, b->effects_sound->t, sfTrue);
	b->effects_sound->r_sound = (sfIntRect) { 0, 0, 150, 150};
	S_sTextureR(b->effects_sound->s, b->effects_sound->r_sound);
	S_sP(b->effects_sound->s, V{1280, 640});
	Draw_sprite(w->window, b->effects_sound->s, NULL);
}

void initialize_ptr(button_s *b)
{
	b->sound->sound = &sound_redcross;
	b->effects_sound->effects_sound = &effects_sound_redcross;
}

int initialize_tick(window_s *w)
{
	w->tick = malloc(sizeof(tick_s));
	if (w->tick == NULL)
		return (84);
	if (garbage_collector((char *)w->tick, 1))
		return (84);
	w->tick->texture = T_createFF(TICK, NULL);
	w->tick->sprite = sfSprite_create();
	S_sTexture(w->tick->sprite, w->tick->texture, sfTrue);
	return (0);
}

int initialize_start_button(window_s *w)
{
	w->start_button = malloc(sizeof(start_button_s));
	if (w->start_button == NULL)
		return (84);
	if (garbage_collector((char *)w->start_button, 1))
		return (84);
	w->start_button->texture = T_createFF(START_BUTTON, NULL);
	w->start_button->sprite = sfSprite_create();
	S_sTexture(w->start_button->sprite, w->start_button->texture, sfTrue);
	return (0);
}
