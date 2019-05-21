/*
** EPITECH PROJECT, 2018
** initialize_two.c
** File description:
** initialize_two.c
*/

#include "my.h"

int initialize_music(music_s *m)
{
	m->loading_music = sfMusic_createFromFile(LOADING_MUSIC);
	sfMusic_play(m->loading_music);
	sfMusic_setVolume(m->loading_music, 40.0);
	m->menu_music = sfMusic_createFromFile(MENU_MUSIC);
	m->game_music = sfMusic_createFromFile(GAME_MUSIC);
	m->mouse_pressed = sfMusic_createFromFile(MOUSE_PRESSED);
	return (0);
}

int initialize_pause(window_s *w)
{
	w->pause = malloc(sizeof(pause_s));
	if (w->pause == NULL)
		return (84);
	if (garbage_collector((char *)w->pause, 1))
		return (84);
	w->pause->t_pause = T_createFF(PAUSE, NULL);
	w->pause->s_pause = sfSprite_create();
	S_sTexture(w->pause->s_pause, w->pause->t_pause, sfTrue);
	return (0);
}

int initialize_pause_line_cross(window_s *w)
{
	w->pause_line = malloc(sizeof(pause_line_s));
	if (w->pause_line == NULL)
		return (84);
	if (garbage_collector((char *)w->pause_line, 1))
		return (84);
	w->pause_line->t_p_line = T_createFF(STICK, NULL);
	w->pause_line->t_p_cross = T_createFF(CROSS, NULL);
	w->pause_line->s_p_line = sfSprite_create();
	w->pause_line->s_p_cross = sfSprite_create();
	S_sTexture(w->pause_line->s_p_line, w->pause_line->t_p_line, sfTrue);
	S_sTexture(w->pause_line->s_p_cross, w->pause_line->t_p_cross, sfTrue);
	return (0);
}

int initialize_background(window_s *w)
{
	w->background = malloc(sizeof(background_s));
	if (w->background == NULL)
		return (84);
	if (garbage_collector((char *)w->background, 1))
		return (84);
	w->background->t_bg = T_createFF(CUSTOMER_SELECTION, NULL);
	w->background->s_bg = sfSprite_create();
	S_sTexture(w->background->s_bg, w->background->t_bg, sfTrue);
	return (0);
}

int initialize_button_two(button_s *b)
{
	b->sound = malloc(sizeof(sound_s));
	if (b->sound == NULL)
		return (84);
	if (garbage_collector((char *)b->sound, 1))
		return (84);
	b->effects_sound = malloc(sizeof(effects_sound_s));
	if (b->effects_sound == NULL)
		return (84);
	if (garbage_collector((char *)b->effects_sound, 1))
		return (84);
	return (0);
}
