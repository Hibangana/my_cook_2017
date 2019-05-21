/*
** EPITECH PROJECT, 2018
** macro.h
** File description:
** macro.h
*/

#ifndef MACRO_H
#define MACRO_H

#define MOUSE_LEFT_PRESSED w->event.type == sfEvtMouseButtonPressed
#define INIT_EFFECTS_SOUND b->effects_sound->shape, V{1270, 630}, V{130, 100}
#define SET_TEXTURE_UNDER b->underlign->s_under, b->underlign->t_under, sfTrue
#define MOUSE_ON_CUSTOMER buttonisclicked(b->mouse, arr[i], V{140, 140}) == 1
#define MOUSE_ON_INGRE buttonisclicked(b->mouse, arr[i], V{160, 160}) == 1
#define rectangle_shape sfRectangleShape
#define CUSTOM_DISH w->c_dish_l->custom_dish_ingredients
#define CUST_ONE "image/customized_dish.png"
#define CUST_TWO "image/customized_dish_two.png"
#define CUST_THREE "image/customized_dish_three.png"

#endif
