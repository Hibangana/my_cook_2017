/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

static customer_s *init_pan(customer_s *element)
{
	static sfVector2f position = {30, 708};

	element = malloc(sizeof(customer_s));
	if (element == NULL)
		return (NULL);
	if (garbage_collector((char *)element, 1))
		return (NULL);
	element->texture = T_createFF("image/cooking_pan.png", NULL);
	element->sprite = sfSprite_create();
	element->rect = (sfIntRect) {0, 0, 211, 200};
	element->position = position;
	element->chosen = 0;
	element->clock = sfClock_create();
	return (element);
}

static customer_s *animate_pan(customer_s *temp)
{
	while (temp->seconds > 1) {
		if (temp->rect.left >= 3500)
			temp->rect.left = 0;
		temp->rect.left += 210;
		sfClock_restart(temp->clock);
	}
	return (temp);
}

static customer_s *display_pan_two(window_s *w, customer_s *temp,
	sfVector2f position)
{
	temp->position.x = position.x;
	temp->position.y = position.y;
	temp->time = sfClock_getElapsedTime(temp->clock);
	temp->seconds = temp->time.microseconds / 100000.0;
	temp = animate_pan(temp);
	if (temp->rect.left <= 3500) {
		S_sTexture(temp->sprite, temp->texture, sfTrue);
		S_sTextureR(temp->sprite, temp->rect);
		S_sP(temp->sprite, temp->position);
		Draw_sprite(w->window, temp->sprite, NULL);
	}
	return (temp);
}

void display_pan(window_s *w, size_t toggle)
{
	static size_t once;
	static customer_s *pan;

	if (once == 0)
		pan = init_pan(pan);
	if (toggle == 1)
		pan = display_pan_two(w, pan, (sfVector2f) {30, 708});
	if (toggle == 2)
		pan = display_pan_two(w, pan, (sfVector2f) {300, 708});
	if (toggle == 3)
		pan = display_pan_two(w, pan, (sfVector2f) {565, 708});
	once++;
}
