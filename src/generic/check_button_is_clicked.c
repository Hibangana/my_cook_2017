/*
** EPITECH PROJECT, 2018
** check
** File description:
** check
*/

#include "my.h"

int buttonisclicked(sfVector2i mouse, sfVector2f position, sfVector2f size)
{
	if (mouse.x != -1 && mouse.y != -1)
		return (mouse.x < position.x +
			size.x &&
			mouse.x > position.x &&
			mouse.y < position.y +
			size.y &&
			mouse.y > position.y);
	return (0);
}
