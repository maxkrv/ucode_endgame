#pragma once

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/begin_code.h>
void mx_check_collision(int *character_x, int *character_y, int map[33][60], bool crate_down_col[], bool item_take[], bool button_on[], int crates_x[], int crates_y[]);
void mx_fileread(int map[33][60], char*s);
void mx_render_level1_map1(SDL_Renderer *renderer, int **crates_x, int **crates_y, bool **crate_down_col, bool **item_take);
void mx_render_level1_map2(SDL_Renderer *renderer, int **crates_x, int **crates_y, bool **crate_down_col);
void mx_render_choice(int level, int time, SDL_Renderer *renderer, int *crates_x, int *crates_y, bool *crate_down_col, bool *item_take);
void restart_level_1(int *crates_x, int *crates_y, bool *item_take);
void default_var();
void mx_check_button(bool button_on[]);

// click handler
void handle_click(SDL_Event event, SDL_Rect rect, void (*callback)());
SDL_Texture* loadtex(SDL_Renderer* renderer, const char *img);
extern SDL_Texture *textures[50];

extern bool left_col;
extern bool right_col;
extern bool up_col;
extern bool down_col;
extern int num_items;
extern int num_cubes;
extern int num_buttons;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const int CHARACTER_WIDTH;
extern const int CHARACTER_HEIGHT;
extern const int SPEED;
extern bool isspikes;
extern bool change_time;
extern SDL_Rect character;
extern bool block_change_time;
extern bool open_door;

extern bool tree_r;
extern bool seed_r;
extern bool bucket_r;
extern int map1[33][60];

extern bool is_menu_open;
