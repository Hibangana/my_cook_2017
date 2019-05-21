##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c\
		src/display/display_usage.c\
		src/display/display_game.c\
		src/display/display_loading.c	\
		src/display/display_start_menu.c			\
		src/display/display_customer_selection.c		\
		src/display/display_customer_selection_two.c		\
		src/display/display_pause.c				\
		src/display/display_pause_two.c				\
		src/display/display_speech.c				\
		src/display/display_highscore.c				\
		src/display/display_recipes.c				\
		src/display/display_how_to_play.c			\
		src/display/display_cursor.c				\
		src/display/display_customization.c\
		src/display/display_customization_two.c\
		src/display/display_choice.c\
		src/initialize/initialize.c				\
		src/initialize/initialize_two.c				\
		src/initialize/initialize_three.c			\
		src/initialize/initialize_four.c			\
		src/initialize/initialize_five.c			\
		src/initialize/initialize_customers.c			\
		src/initialize/initialize_recipes_description.c	\
		src/initialize/initialize_game.c			\
		src/initialize/initialize_dishes.c\
		src/initialize/initialize_question_marks.c\
		src/initialize/initialize_bubbles.c\
		src/initialize/initialize_end_board.c\
		src/initialize/initialize_end_music.c\
		src/initialize/initialize_customization.c\
		src/generic/create_rectangle_shape.c		\
		src/generic/check_button_is_clicked.c		\
		src/generic/music_handling.c	\
		src/generic/restart_game.c	\
		src/generic/get_input_highscore.c		\
		src/generic/write_player_name.c\
		src/generic/write_player_score.c\
		src/game/game_button_manager.c		\
		src/game/play_click_sound.c\
		src/game/display_main_game.c		\
		src/game/display_game_tools.c		\
		src/game/my_key_arrow_manage.c		\
		src/game/end_game_management.c\
		src/game/display_in_game_customers.c\
		src/game/display_pan.c\
		src/game/display_random_dishes.c\
		src/game/ingredients_on_plate_check.c\
		src/game/display_customer_dishes.c\
		src/game/display_highscore.c\
		src/game/display_dish_plate.c\
		src/game/check_dish.c\
		src/game/display_score.c\
		src/game/add_customized_dish.c\

OBJ		=	$(SRC:.c=.o)

NAME		=	my_cook

CC		=	gcc

CFLAGS		=	-Wall -Wextra

CPPFLAGS	=	-I./include

LDFLAGS		=	-l c_graph_prog -Llib/my/ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C lib/my/
		$(CC) $(CFLAGS) $(CPPFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

tests_run:
		make -C tests

tests_clean:
		cd tests/ && $(MAKE) fclean
		rm *.gcno
		rm *.gcda
		rm *.o
		rm unit_test
clean:
	$(RM) $(OBJ)
	$(RM) scoreboard
	cd lib/my/ && $(MAKE) clean

fclean: clean
	$(RM) $(NAME)
	cd lib/my/ && $(MAKE) fclean

re: fclean all

.PHONY : all tests_run tests_clean re fclean clean
