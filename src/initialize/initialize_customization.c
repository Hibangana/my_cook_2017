/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

void initialize_customization_two(window_s *w)
{
	w->c_dish_l->custom_three_sprite = sfSprite_create();
	w->c_dish_l->existing_sprite = sfSprite_create();
	S_sTexture(w->c_dish_l->sprite, w->c_dish_l->texture, sfTrue);
	S_sTexture(w->c_dish_l->choice_sprite, w->c_dish_l->choice_texture,
		sfTrue);
	S_sTexture(w->c_dish_l->custom_sprite, w->c_dish_l->custom_texture,
		sfTrue);
	S_sTexture(w->c_dish_l->custom_two_sprite,
		w->c_dish_l->custom_two_texture,
		sfTrue);
	S_sTexture(w->c_dish_l->custom_three_sprite,
		w->c_dish_l->custom_three_texture,
		sfTrue);
	S_sTexture(w->c_dish_l->existing_sprite, w->c_dish_l->existing_texture,
		sfTrue);
	w->c_dish_l->custom_dish_ingredients = malloc(sizeof(char) * 100);
	w->c_dish_l->on_one = 0;
	w->c_dish_l->on_two = 0;
	w->c_dish_l->on_three = 0;
}

size_t initialize_customization(window_s *w)
{
	w->c_dish_l = malloc(sizeof(c_dish_l));
	w->c_dish_l->on_customization = 1;
	w->c_dish_l->texture = T_createFF("image/customization.png", NULL);
	w->c_dish_l->choice_texture = T_createFF("image/choice.png", NULL);
	w->c_dish_l->custom_texture = T_createFF("image/customized_dish.png",
						NULL);
	w->c_dish_l->custom_two_texture = T_createFF(CUST_TWO,
						NULL);
	w->c_dish_l->custom_three_texture = T_createFF(CUST_THREE,
						NULL);
	w->c_dish_l->existing_texture = T_createFF("image/existing.png", NULL);
	w->c_dish_l->sprite = sfSprite_create();
	w->c_dish_l->choice_sprite = sfSprite_create();
	w->c_dish_l->custom_sprite = sfSprite_create();
	w->c_dish_l->custom_two_sprite = sfSprite_create();
	initialize_customization_two(w);
	return (0);
}
