/*
** EPITECH PROJECT, 2018
** display_speech.c
** File description:
** display_speech.c
*/

#include "my.h"

static void set_music_loop(button_s *b, music_s *m)
{
	static int play_music;
	sfSoundStatus sound_status;

	sound_status = sfMusic_getStatus(m->game_music);
	if (sound_status == sfPaused) {
		sfMusic_play(m->game_music);
		sfMusic_play(m->game_music);
	} else if (play_music == 0 && b->sound_clicked == 1) {
		sfMusic_play(m->game_music);
		sfMusic_setLoop(m->game_music, sfTrue);
	}
	play_music = 1;
	if (b->sound_clicked == -1) {
		sfMusic_pause(m->game_music);
		play_music = 0;
	}
}

static int display_speech_two(window_s *w, char *file, int count)
{
	if (count == w->speech->speech_number) {
		w->speech->texture = T_createFF(file, NULL);
		count++;
	}
	S_sTexture(w->speech->sprite, w->speech->texture, sfTrue);
	Draw_sprite(w->window, w->speech->sprite, NULL);
	return (count);
}

static void my_sleep(float length)
{
	static sfTime duration;

	duration.microseconds = length;
	sfSleep(duration);
}

static int get_key(window_s *w, music_s *m)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
		w->speech->speech_number++;
		sfMusic_play(m->mouse_pressed);
		my_sleep(250000.0);
	}
	if (sfKeyboard_isKeyPressed(sfKeyS) && w->speech->speech_number != 3) {
		w->speech->speech_number = 4;
		sfMusic_play(m->mouse_pressed);
		my_sleep(250000.0);
	}
	return (w->speech->speech_number);
}

void display_speech(window_s *w, button_s *b, music_s *m)
{
	static int once;
	static char *player_name;

	set_music_loop(b, m);
	w->speech->speech_number = get_key(w, m);
	if (w->speech->speech_number == 0)
		once = display_speech_two(w, SPEECH_1, once);
	if (w->speech->speech_number == 1)
		once = display_speech_two(w, SPEECH_2, once);
	if (w->speech->speech_number == 2)
		once = display_speech_two(w, SPEECH_3, once);
	if (w->speech->speech_number == 3) {
		once = display_speech_two(w, SPEECH_4, once);
		player_name = my_strdup(get_input_highscore(w));
	}
	if (w->speech->speech_number == 4) {
		write_player_name(player_name);
		once = 0;
		w->speech->speech_number = 0;
		w->speech->on_speech = 0;
	}
}
