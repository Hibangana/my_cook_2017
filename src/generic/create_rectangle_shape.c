/*
** EPITECH PROJECT, 2018
** create_rectangle_shape.c
** File description:
** create_rectangle_shape.c
*/

#include "my.h"

rectangle_shape *init_shape(rectangle_shape *rect, V2f position, V2f size)
{
	rect = sfRectangleShape_create();
	sfRectangleShape_setPosition(rect, position);
	sfRectangleShape_setSize(rect, size);
	return (rect);
}
