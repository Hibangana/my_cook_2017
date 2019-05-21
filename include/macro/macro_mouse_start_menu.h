/*
** EPITECH PROJECT, 2018
** macro_mouse_start_menu.h
** File description:
** macro_mouse_start_menu.h
*/

#ifndef MACRO_MOUSE_START_MENU_H_
#define MACRO_MOUSE_START_MENU_H_

#define C_DISH_NULL w->c_dish_l->on_customization == 0
#define HIGH_NULL w->highscore->on_highscore == 0
#define HIGH_ON w->highscore->on_highscore == 1
#define RECIPE_NULL w->recipes->on_recipes == 0
#define RECIPE_ON w->recipes->on_recipes == 1
#define HTP_NULL w->how_to_play->on_how_to_play == 0
#define HTP_ON w->how_to_play->on_how_to_play == 1
#define MENU_NULL w->start_menu->on_menu == 0
#define MENU_ON w->start_menu->on_menu == 1
#define SPEECH_NULL w->speech->on_speech == 0
#define SPEECH_ON w->speech->on_speech == 1
#define CUSTOMER_NULL w->customer_l->on_customer_selection == 0
#define ALL_NULL HIGH_NULL && RECIPE_NULL && HTP_NULL
#define SFX effects_sound

#define START_CLICK buttonisclicked(b->mouse, V{350, 120}, V{230, 100}) == 1
#define QUIT_CLICK buttonisclicked(b->mouse, V{618, 789}, V{193, 73}) == 1
#define HIGH_CLICK buttonisclicked(b->mouse, V{478, 630}, V{300, 123}) == 1
#define RECIPE_CLICK buttonisclicked(b->mouse, V{382, 291}, V{243, 62}) == 1
#define HTP_CLICK buttonisclicked(b->mouse, V{454, 432}, V{299, 68}) == 1

#define ON_START START_CLICK && HIGH_NULL && HTP_NULL && RECIPE_NULL
#define ON_QUIT QUIT_CLICK && HIGH_NULL && HTP_NULL && RECIPE_NULL
#define ON_HIGHSCORE HIGH_CLICK && RECIPE_NULL && HTP_NULL
#define ON_RECIPES RECIPE_CLICK && HIGH_NULL && HTP_NULL
#define ON_HTP HTP_CLICK && HIGH_NULL && RECIPE_NULL
#define SOUND_BUTTON (buttonisclicked(b->mouse, V{1450, 670}, V{90, 90}) == 1)
#define SOUND_RED b->sound->sound(b, w, V{1450, 670}, V{90, 90})
#define EFF_SOUND (buttonisclicked(b->mouse, V{1300, 660}, V{140, 100}) == 1)
#define E_S_RED b->SFX->SFX(b, w, V{1270, 660}, V{140, 100})

#endif
