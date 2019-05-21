/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

static ingredient_s *init_image(ingredient_s *element, char *file, int i)
{
	static char *ingredients[10] = {RECIPE_ONE, RECIPE_TWO,
				RECIPE_THREE, RECIPE_FOUR,
				RECIPE_FIVE, RECIPE_SIX,
				RECIPE_SEVEN, RECIPE_EIGHT,
				RECIPE_NINE, RECIPE_TEN};

	element->ingredients = my_strdup(ingredients[i]);
	element->name = my_strdup(file);
	element->texture = T_createFF(file, NULL);
	element->sprite = sfSprite_create();
	S_sTexture(element->sprite, element->texture, sfTrue);
	element->bubble_texture = T_createFF("image/bubble.png", NULL);
	element->bubble_sprite = sfSprite_create();
	S_sTexture(element->bubble_sprite, element->bubble_texture, sfTrue);
	return (element);
}

static int init_element(window_s *w, char *file, int i)
{
	static int number = 1;
	ingredient_s *element = malloc(sizeof(ingredient_s));

	if (element == NULL)
		return (84);
	if (garbage_collector((char *)element, 1))
		return (84);
	element = init_image(element, file, i);
	if (w->dishes_l->head == NULL) {
		w->dishes_l->head = element;
		element->next = NULL;
	} else {
		element->next = w->dishes_l->head;
		w->dishes_l->head = element;
	}
	number++;
	return (0);
}

int initialize_dishes(window_s *w)
{
	w->dishes_l = malloc(sizeof(ingredient_l));
	static char *file[10] = {CHINESE_CANOLI, ASIAN_HOT_DOG,
		KOREAN_KEBAB, CHINESE_FETA_SALAD, JAPANESE_SAWTEED_NOODLES,
		INDIAN_PASTRY, VIETNAME_CREME_BRULEE, KOREAN_CHILI_CONE_CARNE,
		VIETNAMESE_BEEF_SUSHI, JAPANESE_CALIFORNIA_SUSHI};

	if (w->dishes_l == NULL)
		return (84);
	if (garbage_collector((char *)w->dishes_l, 1))
		return (84);
	w->dishes_l->head = NULL;
	for (int i = 0; i != 10; i++) {
		if (init_element(w, file[i], i))
			return (84);
	}
	w->dishes_l->nb_dishes = 9;
	return (0);
}
