#include "header.h"
#include <stdio.h>

// clang collision.c -o collision `sdl2-config --cflags --libs` -lSDL2 -lSDL2_mixer -lSDL2_image -lSDL2_ttf
// 
//  1 = platform
//  2 = ladder
//  3 = spikes
//  4 = item
//  5 = button
//  6 = door

// menu
bool is_menu_open = false;

//Screen dimension constants
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT =  1056;
const int CHARACTER_SPEED = 20;
const int CHARACTER_WIDTH = 64;
const int CHARACTER_HEIGHT = 64;
const int SPEED = 4;// character's movement SPEED
bool left_col = false;
bool right_col = false;
bool up_col = false;
bool down_col = false;
int time1 = 0;
bool isspikes = false;
bool change_time = false;
bool block_change_time = false;

    int x_vel = 0;
    int y_vel = 0;
    bool running = true;
    int isladder = -1;
    bool isjump = false;
    int jump = 0;
    bool level_change = true;
    int level = -1;
    bool open_door = false;
    bool isleft = false;
    

int num_items = 2;
int num_cubes = 1;
int num_buttons = 1;

bool crate_down_col[2];
bool item_take[2];
bool button_on[2];

int map1[33][60];
int map2[33][60];
SDL_Rect character = {0, 995, CHARACTER_WIDTH, CHARACTER_HEIGHT};
SDL_Rect pers = {0, 995, 90, CHARACTER_HEIGHT +15};
SDL_Rect crop_character = {64, 0, 22, 240};

void restart_level_1(int *crates_x, int *crates_y, bool *item_take) {
    character.x = 300;
    pers.x = 288;
    character.y = 100;
    pers.y = 100-15;
    num_items = 2;
    num_cubes = 1;
    num_buttons = 1;
    crates_x[0] = 100;
    crates_y[0] = 200;
    item_take[0] = false;
    time1 = 0;    
    x_vel = 0;
    y_vel = 0;
    isladder = 1;
    isjump = false;
    jump = 0;
    open_door = false;
}

void restart_level_2(){/////////////////////////
    character.x =  128;
    pers.x = 128 - 12;
    character.y =  992 - 128;
    pers.y =  992 - 128 - 15;
    num_items = 2;
    num_cubes = 0;
    num_buttons = 0;
    time1 = 0;    
    x_vel = 0;
    y_vel = 0;
    isladder = 1;
    isjump = false;
    jump = 0;
}

void restart_level_3(int *crates_x, int *crates_y, bool *item_take) {

    character.x =  128;
    pers.x = 128 - 12;
    character.y =  992 - 128 -128;
    pers.y =  992 - 128 - 128 - 15;
    num_items = 2;
    num_cubes = 1;
    num_buttons = 1;
    item_take[0] = false;
    time1 = 0;    
    x_vel = 0;
    y_vel = 0;
    isladder = 1;
    isjump = false;
    jump = 0;
    open_door = true;
}

SDL_Texture* loadtex(SDL_Renderer* renderer, const char *img) {
    SDL_Surface* surface = IMG_Load(img);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;                
}

void open_menu() {
    is_menu_open = !is_menu_open;
    // tyt po idee mojno blockirovat' personaja i vse takoe
}

int main() {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);


    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    Mix_Music *music_bg = Mix_LoadMUS("resource/going_on_foot-133469.mp3");
    Mix_Chunk *walking = Mix_LoadWAV("resource/shagi.wav");
    Mix_Chunk *jumping = Mix_LoadWAV("resource/shagi.wav");
    Mix_Chunk *power = Mix_LoadWAV("resource/ability");
    Mix_Chunk *menu_mus = Mix_LoadWAV("resource/menu_mus");
    Mix_PlayMusic(music_bg, -1);
     SDL_Event event;

    int num_frames = 8;
    int current_frame = 0;
 SDL_Window* window = SDL_CreateWindow("Puzzle Realams", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
   
    Uint32 last_frame_time = SDL_GetTicks();
    SDL_Texture *character_texture = loadtex(renderer, "resource/player/run.png");
    SDL_Texture *character_texture_ladder = loadtex(renderer, "resource/player/ladder.png");
    SDL_Texture *character_texture_cast = loadtex(renderer, "resource/player/cast.png");

    SDL_Surface * temp_surf = NULL;
    temp_surf = IMG_Load("resource/level1/background.jpg");
    textures[0] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/down.png");
    textures[1] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/plat.png");
    textures[2] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/ladder.png");
    textures[3] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/wood.png");
    textures[4] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);

    
    temp_surf = IMG_Load("resource/level2/future/background.jpg");
    textures[5] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/down.png");
    textures[6] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/platform 3.png");
    textures[7] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/platform 4.png");
    textures[8] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/platform 5.png");
    textures[9] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/platform 6.png");
    textures[10] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/platform 7.png");
    textures[11] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/platform 9.png");
    textures[12] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/spear.png");
    textures[13] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level2/future/spearcon.png");
    textures[14] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    
    
    
    
    temp_surf = IMG_Load("resource/menu/menu.jpg");
    textures[15] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/menu/select_level.png");
    textures[16] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);


    temp_surf = IMG_Load("resource/rules/rules.png");
    textures[17] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/menu/rules.jpg");
    textures[19] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/rules/button.png");
    textures[18] = SDL_CreateTextureFromSurface(renderer, temp_surf);


    temp_surf = IMG_Load("resource/level1/plat6.png");
    textures[21] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/plat7.png");
    textures[22] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/tree1.png");
    textures[23] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/seed.png");
    textures[24] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/bucket.png");
    textures[25] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/potion.png");
    textures[26] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level1/portal.png");    
    textures[27] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    
 temp_surf = IMG_Load("resource/level3/cave-down.png");   
    textures[28] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/cave-top-mid.png");   
    textures[29] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/ladder_6.png");   
    textures[30] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/cave-top.png");   
    textures[31] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/dirt.png");   
    textures[32] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/cave-platform_3.png");   
    textures[33] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/cave-mid.png");
    textures[34] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/spikes_4.png");
    textures[35] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/button.png");
    textures[36] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/spikes_2.png");
    textures[37] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/spikes.png");
    textures[38] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/Cave_Background_1.png");
    textures[39] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);
    temp_surf = IMG_Load("resource/level3/crate.png");
    textures[40] = SDL_CreateTextureFromSurface(renderer, temp_surf);
    SDL_FreeSurface(temp_surf);


    
    SDL_Rect rules = {0, 0, 1920, 1080};
    SDL_Rect rules_button = {0, 0, 70, 73};



    bool iscast = false;
    bool crate_down_col[num_cubes];
    bool item_take[num_items];
    bool button_on[num_buttons];
    
    for (int i = 0; i < num_cubes; i++) {
        crate_down_col[i] = false;
    }
    for (int i = 0; i < num_cubes; i++) {
        crate_down_col[i] = false;
    } 
    for (int i = 0; i < num_buttons; i++) {
        button_on[i] = false;
    }
    int crates_x[3];
    int crates_y[3];
    
    //bool level_change = false
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    while (running) {
    if (level_change == true) {
        if (level == -1) {
            restart_level_1(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
            mx_fileread(map1, "resource/level1/map/map1.txt");
            mx_fileread(map2, "resource/level1/map/map1.txt");
            level_change = false;
        }
        else if (level == -2) {
            restart_level_1(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
            mx_fileread(map1, "resource/level1/map/map1.txt");
            mx_fileread(map2, "resource/level1/map/map1.txt");
            level_change = false;
        }
        else if (level == -3) {
            restart_level_1(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
            mx_fileread(map1, "resource/level1/map/map1.txt");
            mx_fileread(map2, "resource/level1/map/map1.txt");
            level_change = false;
        }
        else if (level == 1) {
            Mix_PlayChannel(-1, menu_mus, 0);
            restart_level_1(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
            mx_fileread(map1, "resource/level1/map/map1.txt");
            mx_fileread(map2, "resource/level1/map/map2.txt");
            level_change = false;
        }
        else if (level == 2) {
            Mix_PlayChannel(-1, menu_mus, 0);
            restart_level_2();
            mx_fileread(map1, "resource/level2/map/map3.txt");
            mx_fileread(map2, "resource/level2/map/map4.txt");
            level_change = false;
        }
        else if (level == 3) {
            Mix_PlayChannel(-1, menu_mus, 0);
            restart_level_3(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
            mx_fileread(map1, "resource/level3/map5.txt");
            mx_fileread(map2, "resource/level3/map6.txt");
            level_change = false;
        }
        else if (level == 4) {
            level = -1;
            level_change = false;
        }
    }
        // proshloe abo mynule
        if(time1 == 0){
            mx_check_collision(&character.x, &character.y, map1, &crate_down_col[num_cubes], &item_take[num_items], &button_on[num_buttons], &crates_x[num_cubes], &crates_y[num_cubes]);
        }
        else if(time1 == 1){
            mx_check_collision(&character.x, &character.y, map2, &crate_down_col[num_cubes], &item_take[num_items], &button_on[num_buttons], &crates_x[num_cubes], &crates_y[num_cubes]);
        }
        
        if(isjump == false && isladder == 1) {
            switch (event.type) {
                case SDL_KEYDOWN:           
                    switch ( event.key.keysym.sym ) { 
                    case SDLK_UP:                       
                    isjump = true;
                    jump = 1;
                    Mix_PlayChannel(-1, jumping, 0);
                    break;                    
                }
            }
        }
        while (SDL_PollEvent(&event)) {
            x_vel = 0;
            y_vel = 0;

            // click handler, check utils.c file
            handle_click(event, rules_button, open_menu);

            switch (event.type) {
            case SDL_MOUSEBUTTONDOWN: 
            if(level == -1) {       
                switch ( event.button.button ) { 
                    case SDL_BUTTON_LEFT:
                    if(event.motion.x >= 770 && event.motion.x <= 1160 && event.motion.y >= 500 && event.motion.y <= 595) {
                        level = -3;
                        level_change = true;
                        Mix_PlayChannel(-1, menu_mus, 0);
                    }
                    if(event.motion.x >= 770 && event.motion.x <= 1160 && event.motion.y >= 620 && event.motion.y <= 715) {
                        level = -2;
                        level_change = true;
                        Mix_PlayChannel(-1, menu_mus, 0);
                    }
                    if(event.motion.x >= 770 && event.motion.x <= 1160 && event.motion.y >= 745 && event.motion.y <= 840) {
                        running = false;
                    }
        
                break;                    
                }
            }
            else if(level == -3) {       
                switch ( event.button.button ) { 
                    case SDL_BUTTON_LEFT:
                    if(event.motion.x >= 395 && event.motion.x <= 635 && event.motion.y >= 385 && event.motion.y <= 625) {
                        level = 1;
                        level_change = true;
                    }
                    if(event.motion.x >= 840 && event.motion.x <= 1080 && event.motion.y >= 385 && event.motion.y <= 625) {
                        level = 2;
                        level_change = true;
                    }
                    if(event.motion.x >= 1285 && event.motion.x <= 1525 && event.motion.y >= 385 && event.motion.y <= 625) {
                        level = 3;
                        level_change = true;
                    }
                     if(event.motion.x >= 711 && event.motion.x <= 1215 && event.motion.y >= 895 && event.motion.y <= 1015) {
                        level = -1;
                        level_change = true;
                    }
        
                    break;                    
                }
            }
            else if(level == -2) {       
                switch ( event.button.button ) { 
                    case SDL_BUTTON_LEFT:
                    Mix_PlayChannel(-1, menu_mus, 0);
                    if(event.motion.x >= 715 && event.motion.x <= 1110 && event.motion.y >= 920 && event.motion.y <= 1015) {
                        level = -1;
                        level_change = true;
                        }
        
                    break;                    
                }
            }
			case SDL_KEYDOWN:
				switch ( event.key.keysym.sym ) {
					case SDLK_q: 
                    if(down_col == true && block_change_time == false) {
                        Mix_PlayChannel(-1, power, 0);
                        iscast = !iscast;
                        change_time = true;
                        if(time1 == 0)
                            time1++;
                        else if(time1 == 1)
                                time1--;
                    }
                    break;
                    case SDLK_r:  
                        if (level == 1)  {                   
                            restart_level_1(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
                        }
                        if (level == 2) {
                            restart_level_2();
                        }
                        if(level == 3){
                            restart_level_3(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
                        }

                    break; 
                    case SDLK_ESCAPE: 
                        Mix_PlayChannel(-1, menu_mus, 0);  
                        level = -1;
                        level_change = true;
                    break;
				}
				break;
		    }
            
            if ( keystates[SDL_SCANCODE_1] )
                running = false;
            else {
                  if (time1 == 0) {
                    if(map1[(character.y + 32) / 32][(character.x + 16) / 32] == 2 && map1[(character.y + 32) / 32][(character.x + 48) / 32] == 2) {
                         isladder = 0;
                    }
                } else {
                    if(map2[(character.y + 32) / 32][(character.x + 16) / 32] == 2 && map2[(character.y + 32) / 32][(character.x + 48) / 32] == 2) {
                         isladder = 0;
                    }
                }
		        if (keystates[SDL_SCANCODE_LEFT]) {
                    Mix_PlayChannel(-1, walking, 0);
		            x_vel -= SPEED;
                }
		        if(keystates[SDL_SCANCODE_RIGHT]) {
                    Mix_PlayChannel(-1, walking, 0);
                    x_vel += SPEED;
                }
                if(keystates[SDL_SCANCODE_UP] && isladder == 0) {
                    Mix_PlayChannel(-1, jumping, 0);
                    y_vel -= 1;
                }
                if(keystates[SDL_SCANCODE_DOWN] && isladder == 0) {
                    y_vel += 1;
                }
            }
        }

        if(isspikes == true) {
            if (level == 1)  {                   
                restart_level_1(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
            }
            if (level == 2) {
                restart_level_2();
            }
            if(level == 3){
                restart_level_3(&crates_x[num_cubes], &crates_y[num_cubes], &item_take[num_items]);
            }
            isspikes = false;
        }

        // jump
        if (time1 == 0) {
            if (map1[(character.y / 32) + 1][(character.x + 8) / 32] != 2 && map1[(character.y / 32) + 1][(character.x + 24) / 32] != 2) { 
                if(jump != 0 && jump < 40) {
                    if (up_col == false) { 
                        character.y -= 8;
                        pers.y -= 8;
                        if(time1 == 0) {
                            mx_check_collision(&character.x, &character.y, map1, &crate_down_col[num_cubes], &item_take[num_items], &button_on[num_buttons], &crates_x[num_cubes], &crates_y[num_cubes]);
                        }
                        else if(time1 == 1) {
                            mx_check_collision(&character.x, &character.y, map2, &crate_down_col[num_cubes], &item_take[num_items], &button_on[num_buttons], &crates_x[num_cubes], &crates_y[num_cubes]);
                        }
                    }
                    else if (up_col == true) {
                        jump = 40;
                    }
                    jump++;
                }
            }
            }
        else {
            if (map2[(character.y / 32) + 1][(character.x + 8) / 32] != 2 && map2[(character.y / 32) + 1][(character.x + 24) / 32] != 2) { 
                if(jump != 0 && jump < 40) {
                    if (up_col == false) { 
                        character.y -= 8;
                        pers.y -= 8;
                        if(time1 == 0) {
                            mx_check_collision(&character.x, &character.y, map1, &crate_down_col[num_cubes], &item_take[num_items], &button_on[num_buttons], &crates_x[num_cubes], &crates_y[num_cubes]);
                        }
                        else if(time1 == 1) {
                            mx_check_collision(&character.x, &character.y, map2, &crate_down_col[num_cubes], &item_take[num_items], &button_on[num_buttons], &crates_x[num_cubes], &crates_y[num_cubes]);
                        }
                    }
                    else if (up_col == true) {
                        jump = 40;
                    }
                    jump++;
                }
            }
        }
        if (down_col == true) {
            isjump = false;
            jump = 0;
        }

        // right left
        if ((x_vel < 0 && left_col == false) || (x_vel > 0 && right_col == false) ) { 
            character.x += x_vel;
            pers.x += x_vel;
        }
        
        // gravity
        for(int i = 0; i < 2; i++) { 
            if (down_col == false && isladder == 1 && !(jump != 0 && jump < 40)) { 
                character.y += 4;
                pers.y += 4;
            }
            if(time1 == 0){
                mx_check_collision(&character.x, &character.y, map1, &crate_down_col[num_cubes], &item_take[num_items], &button_on[num_buttons], &crates_x[num_cubes], &crates_y[num_cubes]);
            }
            else if(time1 == 1){
                mx_check_collision(&character.x, &character.y, map2, &crate_down_col[num_cubes], &item_take[num_items], &button_on[num_buttons], &crates_x[num_cubes], &crates_y[num_cubes]);
            }
        }
        
        //ladder
        if (isladder == 0) {
            character.y += y_vel;
            pers.y += y_vel;
                if (time1 == 0) {
                    if(map1[(character.y + 32) / 32][(character.x + 16) / 32] != 2 && map1[(character.y + 32) / 32][(character.x + 48) / 32] != 2) {
                         isladder = 1;
                    }
                    } else {
                    if(map2[(character.y + 32) / 32][(character.x + 16) / 32] != 2 && map2[(character.y + 32) / 32][(character.x + 48) / 32] != 2) {
                         isladder = 1;
                    }
                }
        }
        if (time1 == 0) {
            if((map1[(character.y - 32) / 32][(character.x + 16)/ 32] == 2 && isladder == 1) || (map1[(character.y - 32) / 32][(character.x + 48)/ 32] == 2 && isladder == 1)) {
                character.y -= 1;
                pers.y -= 1;
            }
        } else {
            if((map2[(character.y - 32) / 32][(character.x + 16)/ 32] == 2 && isladder == 1) || (map2[(character.y - 32) / 32][(character.x + 48)/ 32] == 2 && isladder == 1)) {
                character.y -= 1;
                pers.y -= 1;
            }
        }

        //level changes
        if(open_door && map1[(character.y + 31) / 32][(character.x + 16)/ 32] == 4 && time1 == 0) {
            level_change = true;
            level += 1;
        }

        //render
        mx_render_choice(level, time1, renderer, &crates_x[num_cubes], &crates_y[num_cubes], &crate_down_col[num_cubes], &item_take[num_items]);
        
        Uint32 current_time = SDL_GetTicks();
        if (current_time - last_frame_time >= 100) {
            current_frame = (current_frame + 1) % num_frames;
            crop_character.x = current_frame * 32;
            last_frame_time = current_time;
        }
    

                
        if (level > 0) {
            // SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
            // SDL_RenderFillRect(renderer, &character);
            if (current_time - last_frame_time >= 100) {
            current_frame = (current_frame + 1) % num_frames;
            crop_character.x = current_frame * 32;
            last_frame_time = current_time;
        }
        if (keystates[SDL_SCANCODE_LEFT] && iscast == false) {
            SDL_RenderCopyEx(renderer, character_texture, &crop_character, &pers, 0, NULL, SDL_FLIP_HORIZONTAL);
            isleft = true;
        } 
        else if(keystates[SDL_SCANCODE_RIGHT] && iscast == false){
            SDL_RenderCopyEx(renderer, character_texture, &crop_character, &pers, 0, NULL, SDL_FLIP_NONE);
            isleft = false;
        }
        else if(((keystates[SDL_SCANCODE_UP] && isladder == 0) || (keystates[SDL_SCANCODE_DOWN] && isladder == 0))&& iscast == false){
            SDL_RenderCopyEx(renderer, character_texture_ladder, &crop_character, &pers, 0, NULL, SDL_FLIP_NONE);
        }
        else if(isleft == true && iscast == false){
            SDL_Texture *tex = loadtex(renderer, "resource/player/stay.png");
            SDL_RenderCopyEx(renderer, tex, NULL, &pers, 0, NULL, SDL_FLIP_HORIZONTAL);
        }
        else if(isleft == false && iscast == false){
           SDL_Texture *tex = loadtex(renderer, "resource/player/stay.png");
           SDL_RenderCopyEx(renderer, tex, NULL, &pers, 0, NULL, SDL_FLIP_NONE);
        }
            if(isleft == true) {
                if(iscast){
                    SDL_RenderCopyEx(renderer, character_texture_cast, &crop_character, &pers, 0, NULL, SDL_FLIP_HORIZONTAL);

                    if ((current_frame + 1) % 6 == 3) {
                    iscast = false;
                    }
                }
            }
            else {
                if(iscast){
                    SDL_RenderCopyEx(renderer, character_texture_cast, &crop_character, &pers, 0, NULL, SDL_FLIP_NONE);

                    if ((current_frame + 1) % 6 == 3) {
                    iscast = false;
                    }
                }
            }
        }

    SDL_RenderCopy(renderer, textures[18], NULL, &rules_button);
    if (is_menu_open == true)
            SDL_RenderCopyEx(renderer, textures[17], NULL, &rules, 0, NULL, SDL_FLIP_NONE);

        SDL_RenderPresent(renderer);
    }
        Mix_FreeChunk(walking);
    Mix_FreeChunk(jumping);
    Mix_FreeChunk(power);
    Mix_FreeChunk(menu_mus);
    SDL_DestroyRenderer(renderer);
    Mix_FreeMusic(music_bg);
    Mix_CloseAudio();
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
        
