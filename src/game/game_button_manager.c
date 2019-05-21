/*
** EPITECH PROJECT, 2018
** name
** File description:
** description
*/

#include "my.h"

static void my_game_button_manager_five(window_s *w, button_s *b, music_s *m)
{
	if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
		my_keyleft_manage(w);
		play_click_sound(w, b, m, 84);
	}
	if (sfKeyboard_isKeyPressed(sfKeyRight)) {
		my_keyright_manage(w);
		play_click_sound(w, b, m, 84);
	}
	if (sfKeyboard_isKeyPressed(sfKeyH)) {
		play_click_sound(w, b, m, 84);
		display_in_game_guide(w, b, m);
	}
	display_game_prep(w);
	display_dish_plate(w);
	display_game_arrow(w);
}

static void my_game_button_manager_four(window_s *w, button_s *b, music_s *m)
{
	if (w->event.key.code == sfKeyReturn) {
		ingredients_on_plate_check(w);
		play_click_sound(w, b, m, 84);
		w->event.key.code = sfKeyUp;
	}
	if (sfKeyboard_isKeyPressed(sfKeySpace)) {
		play_click_sound(w, b, m, 84);
		my_cleaning_plate(w);
	}
	my_game_button_manager_five(w, b, m);
}

static void my_game_button_manager_three(window_s *w, button_s *b, music_s *m)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum9))
		play_click_sound(w, b, m, 9);
	if (sfKeyboard_isKeyPressed(sfKeyNum0))
		play_click_sound(w, b, m, 0);
	my_game_button_manager_four(w, b, m);
}

static void my_game_button_manager_two(window_s *w, button_s *b, music_s *m)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum5))
		play_click_sound(w, b, m, 5);
	if (sfKeyboard_isKeyPressed(sfKeyNum6))
		play_click_sound(w, b, m, 6);
	if (sfKeyboard_isKeyPressed(sfKeyNum7))
		play_click_sound(w, b, m, 7);
	if (sfKeyboard_isKeyPressed(sfKeyNum8))
		play_click_sound(w, b, m, 8);
	my_game_button_manager_three(w, b, m);
}

void my_game_button_manager(window_s *w, button_s *b, music_s *m)
{
	if (sfKeyboard_isKeyPressed(sfKeyNum1))
		play_click_sound(w, b, m, 1);
	if (sfKeyboard_isKeyPressed(sfKeyNum2))
		play_click_sound(w, b, m, 2);
	if (sfKeyboard_isKeyPressed(sfKeyNum3))
		play_click_sound(w, b, m, 3);
	if (sfKeyboard_isKeyPressed(sfKeyNum4))
		play_click_sound(w, b, m, 4);
	my_game_button_manager_two(w, b, m);
}
