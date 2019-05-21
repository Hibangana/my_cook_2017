/*
** EPITECH PROJECT, 2018
** some project
** File description:
** who cares
*/

#include "my.h"

static ingredient_s *customers_dishes_two(window_s *w,
	ingredient_s *temp, customer_s *customer, sfVector2f position)
{
	if (w->once1 == 0)
		temp = get_random_dishes(w);
	display_dishes(w, position, temp, customer);
	return (temp);
}

static size_t display_customers_dishes_three(window_s *w,
	customer_s *custom)
{
	static ingredient_s *temp3;
	static ingredient_s *temp4;
	static ingredient_s *temp5;

	while (custom->chosen != 1)
		custom = custom->next;
	temp3 = customers_dishes_two(w, temp3, custom, (sfVector2f) {466, 450});
	custom->dish = my_strdup(temp3->ingredients);
	custom = custom->next;
	while (custom->chosen != 1)
		custom = custom->next;
	temp4 = customers_dishes_two(w, temp4, custom, (sfVector2f) {669, 450});
	custom->dish = my_strdup(temp4->ingredients);
	custom = custom->next;
	while (custom->chosen != 1)
		custom = custom->next;
	temp5 = customers_dishes_two(w, temp5, custom, (sfVector2f) {868, 450});
	custom->dish = my_strdup(temp5->ingredients);
	w->once1++;
	return (w->once1);
}

void display_customers_dishes(window_s *w)
{
	static ingredient_s *temp;
	static ingredient_s *temp2;
	customer_s *custom = w->customer_l->head;

	while (custom->chosen != 1)
		custom = custom->next;
	temp = customers_dishes_two(w, temp, custom, (sfVector2f) {60, 450});
	custom->dish = my_strdup(temp->ingredients);
	custom = custom->next;
	while (custom->chosen != 1)
		custom = custom->next;
	temp2 = customers_dishes_two(w, temp2, custom, (sfVector2f) {263, 450});
	custom->dish = my_strdup(temp2->ingredients);
	custom = custom->next;
	w->once1 = display_customers_dishes_three(w, custom);
}
