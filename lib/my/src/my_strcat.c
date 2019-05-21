/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int k = 0;

	while (dest[i])
		i++;
	while (src[k]) {
		dest[i] = src[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
