/*
** EPITECH PROJECT, 2018
** display_start_menu.c
** File description:
** display_start_menu.c
*/

#include "my.h"

void start_menu_button_handling(window_s *w, button_s *b, music_s *m)
{
	if (b->effects_sound_clicked == 1)
		sfMusic_play(m->mouse_pressed);
	if (SOUND_BUTTON) {
		b->sound_clicked *= -1;
		return;
	}
	if (EFF_SOUND && w->start_menu->on_menu == 1)
		b->effects_sound_clicked *= -1;
	if (ON_START && w->start_menu->on_menu == 1)
		w->start_menu->on_menu = 0;
	if (ON_HIGHSCORE && w->start_menu->on_menu == 1)
		w->highscore->on_highscore = 1;
	if (ON_RECIPES && w->start_menu->on_menu == 1)
		w->recipes->on_recipes = 1;
	if (ON_HTP && w->start_menu->on_menu == 1)
		w->how_to_play->on_how_to_play = 1;
}

int underlign(window_s *w, button_s *b, sfVector2f position, sfVector2f size)
{
	b->underlign = malloc(sizeof(underlign_s));
	if (b->underlign == NULL)
		return (84);
	if (garbage_collector((char *)b->underlign, 1))
		return (84);
	b->underlign->shape = sfRectangleShape_create();
	sfRectangleShape_setPosition(b->underlign->shape, position);
	sfRectangleShape_setSize(b->underlign->shape, size);
	b->underlign->t_under = T_createFF(LINE, NULL);
	b->underlign->s_under = sfSprite_create();
	RS_sT(b->underlign->shape, b->underlign->t_under, sfTrue);
	sfSprite_setTexture(SET_TEXTURE_UNDER);
	b->underlign->r_under = (sfIntRect) { 0, 0, 300, 100};
	sfSprite_setTextureRect(b->underlign->s_under, b->underlign->r_under);
	sfSprite_setPosition(b->underlign->s_under, position);
	sfRenderWindow_drawSprite(w->window, b->underlign->s_under, NULL);
	return (0);
}

static int start_menu_underlign(window_s *w, button_s *b)
{
	if (U_START)
		if (UNDERLIGN_START)
			return (84);
	if (U_RECIPES)
		if (UNDERLIGN_RECIPES)
			return (84);
	if (U_HTP)
		if (UNDERLIGN_HTP)
			return (84);
	if (U_HIGHSCORE)
		if (UNDERLIGN_HIGHSCORE)
			return (84);
	if (U_QUIT)
		if (UNDERLIGN_QUIT)
			return (84);
	return (0);
}

static void set_music_loop(button_s *b, music_s *m)
{
	static int play_music;

	if (play_music == 0 && b->sound_clicked == 1) {
		sfMusic_play(m->menu_music);
		sfMusic_setLoop(m->menu_music, sfTrue);
	}
	play_music = 1;
	if (b->sound_clicked == -1) {
		sfMusic_pause(m->menu_music);
		play_music = 0;
	}
}

int display_start_menu(window_s *w, button_s *b, music_s *m)
{
	set_music_loop(b, m);
	S_sTexture(w->start_menu->s, w->start_menu->t, sfTrue);
	S_sTextureR(w->start_menu->s, w->start_menu->r);
	Draw_sprite(w->window, w->start_menu->s, NULL);
	if (start_menu_underlign(w, b))
		return (84);
	if (b->sound_clicked == -1)
		SOUND_RED;
	if (b->effects_sound_clicked == -1)
		E_S_RED;
	return (0);
}
