#include "header.h"

SDL_Rect background = {0, 0, 1920, 1080}; //background
SDL_Rect platform_first = {0, 990, 1920, 96}; //first platforma
SDL_Rect platform1 = {448 ,794, 384, 64};//platforma nomer 1
SDL_Rect platform2 = {32, 570, 384, 64};//platforma nomer 2
SDL_Rect platform3 = {224, 189, 384, 64};//platforma nomer 3
SDL_Rect platform4 = {1200, 217, 448, 64};//platforma nomer 4
SDL_Rect platform5 = {1700, 378, 192, 64};//platforma nomer 5 future lvl
SDL_Rect wood1 = {768, 615 , 128, 32};//wood nomer 1 future lvl
SDL_Rect wood2 = {864, 455, 128, 32};//wood nomer 2 future lvl
SDL_Rect wood3 = {992, 325 , 128, 32};//wood nomer 3 future lvl
SDL_Rect ladder = {242, 218, 64, 380};//lestnica
SDL_Rect tree = {720, 210, 608, 800};// tree ebanoe
SDL_Rect seed = {990, 895, 64, 106};
SDL_Rect seed_item = {250, 920, 32, 53};
SDL_Rect crate = {500, 95, 64, 64};// ne eby naxuia v 1 lvle// character's initial position and size
SDL_Rect potion = {1920 - (5*32), 9*32, 96, 96};
SDL_Rect portal = {1920 - (6*32), 831, 3*32, 2*64};


SDL_Rect platform_first_lvl2 = {0, 992, 1920, 96}; 
SDL_Rect platform_1_lvl2 = {1312, 864, 384, 64}; 
SDL_Rect platform_2_lvl2 = {800, 704, 320, 64};
SDL_Rect platform_3_lvl2 = {224, 576, 320, 64};
SDL_Rect platform_4_lvl2 = {1216, 544, 320, 64};
SDL_Rect platform_5_lvl2 = {672, 384, 448, 64};
SDL_Rect platform_6_lvl2 = {32, 352, 256, 64};
SDL_Rect platform_7_lvl2 = {1344, 192, 576, 64};
SDL_Rect platform_8_lvl2 = {320, 128, 192, 64};

SDL_Rect platform_9_lvl2 = {1184, 736, 192, 64};
SDL_Rect platform_10_lvl2 = {576, 670, 192, 64};

SDL_Rect spear1 = {608, 928, 96, 64};
SDL_Rect spear2 = {704, 928, 96, 64};
SDL_Rect spear3 = {1120, 928, 96, 64};
SDL_Rect spear4 = {448, 514, 96, 64};
SDL_Rect spear5 = {1216, 482, 96, 64};
SDL_Rect spear6 = {1312, 482, 96, 64};
SDL_Rect spear7 = {1440, 482, 96, 64};
SDL_Rect spear8 = {672, 322, 96, 64};
SDL_Rect spear9 = {32, 290, 96, 64};
SDL_Rect spear10 = {352, 66, 96, 64};
SDL_Rect spearlvl2_1 = {608, 928, 96, 64};
SDL_Rect spearlvl2_2 = {704, 928, 96, 64};
SDL_Rect spearlvl2_3 = {800, 928, 96, 64};
SDL_Rect spearlvl2_4 = {1216, 482, 96, 64};
SDL_Rect spearlvl2_5 = {1312, 482, 96, 64};
SDL_Rect spearlvl2_6 = {1440, 482, 96, 64};
SDL_Rect spearlvl2_7 = {672, 322, 96, 64};
SDL_Rect spearlvl2_8 = {768, 322, 96, 64};
SDL_Rect spearlvl2_9 = {864, 322, 96, 64};
SDL_Rect spearlvl2_10 = {32, 290, 96, 64};
SDL_Rect spearlvl2_11 = {192, 290, 96, 64};
SDL_Rect spearlvl2_12 = {1376, 130, 96, 64};
SDL_Rect spearlvl2_13 = {1472, 130, 96, 64};
SDL_Rect spearlvl2_14 = {1568, 130, 96, 64};

SDL_Rect spearcon1 = {1184, 736, 64, 96};
SDL_Rect spearcon2 = {896, 512, 64, 96};
SDL_Rect spearcon3 = {1216, 258, 64, 96};
SDL_Rect spearconlvl2_1 = {1184, 736, 64, 96};
SDL_Rect spearconlvl2_2 = {896, 512, 64, 96};
SDL_Rect spearconlvl2_3 = {576, 670, 64, 96};
SDL_Rect spearconlvl2_4 = {480, 352, 64, 96};





SDL_Rect platform_down_lvl3 = {0, 824, 1920, 256};
SDL_Rect platform_top_mid_lvl3 = {0, 0, 1920, 736};
SDL_Rect ladder_lvl3 = {480, 352, 64, 96};
SDL_Rect platform_top_lvl3 = {0, 0, 1920, 441};
SDL_Rect platform_mid_lvl3 = {220, 408, 1696, 328};
SDL_Rect spikes_lvl3 = {855, 576, 192, 64};
SDL_Rect ladder_1_lvl3 = {784, 180, 64, 384};
SDL_Rect ladder_2_lvl3 = {690, 244, 64, 384};
SDL_Rect platform1_lvl3 = {768, 256, 192, 64};
SDL_Rect platform2_lvl3 = {992, 352, 192, 64};
SDL_Rect spikes_1_lvl3 = {1088, 288, 32, 64};
SDL_Rect spikes_2_lvl3 = {1408, 345, 64, 64};
SDL_Rect dirt_lvl3 = {560, 738, 256, 96};
SDL_Rect button1_lvl3 = {192, 777, 64, 60};
SDL_Rect button2_lvl3 = {1216, 777, 64, 60};

SDL_Rect up_door_close = {5*32, 1920 - (21*32), 128 ,6*32};
SDL_Rect up_door_open = {5*32, 1920 - (21*32), 128,6*32};
SDL_Rect down_door_open = {1920 - 416, 920 - (6*32), 64, 96};
SDL_Rect down_door_close = {1920 - 416, 920 - (6*32), 64, 96};
SDL_Rect crate_lv3 = {15*32, 992 - 128 - 128 +32, 64, 64};


int back_crates_x[3];
int back_crates_y[3];
SDL_Texture *textures[50];
bool tree_r = false;
bool seed_r = false;
bool start = false;
bool bucket_r = true;



void mx_render_choice(int level, int time1, SDL_Renderer *renderer, int *crates_x, int *crates_y, bool *crate_down_col, bool *item_take) {
    if(level == -1) {
        SDL_RenderClear(renderer);
        SDL_RenderCopyEx(renderer, textures[15], NULL, &background, 0, NULL, SDL_FLIP_NONE);
    }
    else if(level == -3) {
        SDL_RenderClear(renderer);
        SDL_RenderCopyEx(renderer, textures[16], NULL, &background, 0, NULL, SDL_FLIP_NONE);
    }
    else if(level == -2) {
        SDL_RenderClear(renderer);
        SDL_RenderCopyEx(renderer, textures[19], NULL, &background, 0, NULL, SDL_FLIP_NONE);
    }
    else if(level == 1) {
        if (time1 == 0) {
         if (start == false) {
        start = true;
        change_time = true;
     }
        
     if (change_time == true) {
        back_crates_x[0] = crate.x;
        back_crates_y[0] = crate.y;
        crates_x[0] = -100;
        crates_y[0] = -100;
        change_time = false;
    }
    int count_block_time = 0;
    for (int i = 0; i < num_cubes; i++) {
        for (int centre = 0; centre <= 32; centre += 32) {
            if (back_crates_x[i] < character.x + centre && character.x + centre < back_crates_x[i] + 64) {
                count_block_time++;
            } else {
                block_change_time = false;
            }
        }
    }
    if (count_block_time != 0) {
        block_change_time = true;
    }
     
    SDL_RenderClear(renderer);
    SDL_RenderCopyEx(renderer, textures[0], NULL, &background, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[1], NULL, &platform_first, 0, NULL, SDL_FLIP_NONE);
    if (seed_r == true) {
        SDL_RenderCopyEx(renderer, textures[24], NULL, &seed, 0, NULL, SDL_FLIP_NONE);
    }
    if (tree_r == true) {
        SDL_RenderCopyEx(renderer, textures[23], NULL, &tree, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, textures[4], NULL, &wood1, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, textures[4], NULL, &wood2, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, textures[4], NULL, &wood3, 0, NULL, SDL_FLIP_NONE);
    }
    if(item_take[1] == true) {
        SDL_RenderCopyEx(renderer, textures[27], NULL, &portal, 0, NULL, SDL_FLIP_NONE);
    }
    if(item_take[1] == false) { 
        SDL_RenderCopyEx(renderer, textures[26], NULL, &potion, 0, NULL, SDL_FLIP_NONE);
    }
    SDL_RenderCopyEx(renderer, textures[21], NULL, &platform1, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[21], NULL, &platform2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[3], NULL, &ladder, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[21], NULL, &platform3, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[22], NULL, &platform4, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[2], NULL, &platform5, 0, NULL, SDL_FLIP_NONE);
    } 

 else if (time1 == 1) {

 for (int i = 0; i < num_cubes; i++) {
        if (crate_down_col[i] == false) {
            crates_y[i] += 6;
        }
        }
        if (change_time == true) {
            crates_x[0] = back_crates_x[0];
            crates_y[0] = back_crates_y[0];
            change_time = false;
        }
        crate.x = crates_x[0];
        crate.y = crates_y[0];
        
        SDL_RenderClear(renderer);
        SDL_RenderCopyEx(renderer, textures[0], NULL, &background, 0, NULL, SDL_FLIP_NONE);
        SDL_RenderCopyEx(renderer, textures[1], NULL, &platform_first, 0, NULL, SDL_FLIP_NONE);
        if (seed_r == true) {
                SDL_RenderCopyEx(renderer, textures[23], NULL, &seed, 0, NULL, SDL_FLIP_NONE);
            }
            SDL_RenderCopyEx(renderer, textures[21], NULL, &platform1, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[21], NULL, &platform2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[3], NULL, &ladder, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[21], NULL, &platform3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[22], NULL, &platform4, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[2], NULL, &platform5, 0, NULL, SDL_FLIP_NONE);
                if (item_take[0] == false) {
                    SDL_RenderCopyEx(renderer, textures[24], NULL, &seed_item, 0, NULL, SDL_FLIP_NONE);
                }
                if (bucket_r == true) {
                    SDL_RenderCopyEx(renderer, textures[25], NULL, &crate, 0, NULL, SDL_FLIP_NONE);
                }
        }
    }
    else if (level == 2) {
        if (time1 == 0) {
            portal.y = 64;
            portal.x = 1920 - (5*32);
                   
            SDL_RenderCopyEx(renderer, textures[5], NULL, &background, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[6], NULL, &platform_first_lvl2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[10], NULL, &platform_1_lvl2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[9], NULL, &platform_2_lvl2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[9], NULL, &platform_3_lvl2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[9], NULL, &platform_4_lvl2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[11], NULL, &platform_5_lvl2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[8], NULL, &platform_6_lvl2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[12], NULL, &platform_7_lvl2, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[7], NULL, &platform_8_lvl2, 0, NULL, SDL_FLIP_NONE); 
           

            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear1, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear2, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear3, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear4, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear5, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear6, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear7, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear8, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear9, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spear10, 0, NULL, SDL_FLIP_VERTICAL);

            SDL_RenderCopyEx(renderer, textures[14], NULL, &spearcon1, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[14], NULL, &spearcon2, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[14], NULL, &spearcon3, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_3, 0, NULL, SDL_FLIP_VERTICAL);
            SDL_RenderCopyEx(renderer, textures[27], NULL, &portal, 0, NULL, SDL_FLIP_NONE); 
    
    } 
    
    else if (time1 == 1) {

    SDL_RenderCopyEx(renderer, textures[5], NULL, &background, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[6], NULL, &platform_first_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[10], NULL, &platform_1_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[9], NULL, &platform_2_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[9], NULL, &platform_3_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[9], NULL, &platform_4_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[11], NULL, &platform_5_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[8], NULL, &platform_6_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[12], NULL, &platform_7_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[7], NULL, &platform_8_lvl2, 0, NULL, SDL_FLIP_NONE);
     SDL_RenderCopyEx(renderer, textures[7], NULL, &platform_9_lvl2, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(renderer, textures[7], NULL, &platform_10_lvl2, 0, NULL, SDL_FLIP_NONE);

    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_2, 0, NULL, SDL_FLIP_VERTICAL);

    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_4, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_5, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_6, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_7, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_8, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_9, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_10, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_11, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_12, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_13, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[13], NULL, &spearlvl2_14, 0, NULL, SDL_FLIP_VERTICAL);

   // SDL_RenderCopyEx(renderer, textures[14], NULL, &spearconlvl2_1, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[14], NULL, &spearconlvl2_2, 0, NULL, SDL_FLIP_VERTICAL);
  //  SDL_RenderCopyEx(renderer, textures[14], NULL, &spearconlvl2_3, 0, NULL, SDL_FLIP_VERTICAL);
    SDL_RenderCopyEx(renderer, textures[14], NULL, &spearconlvl2_4, 0, NULL, SDL_FLIP_VERTICAL);

    
    }
    }

    else if (level == 3) {
        portal.x = 39*32;
        portal.y = 352 - 128 - 32;
        potion.x = 28*32;
        potion.y = 922 - 8*32 + 64;
        
        if (time1 == 0) {


            SDL_RenderCopyEx(renderer, textures[39], NULL, &background, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[28], NULL, &platform_down_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[29], NULL, &platform_top_mid_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[36], NULL, &button1_lvl3, 0, NULL, SDL_FLIP_NONE);   
            SDL_RenderCopyEx(renderer, textures[36], NULL, &button2_lvl3, 0, NULL, SDL_FLIP_NONE); 
            SDL_RenderCopyEx(renderer, textures[30], NULL, &ladder_2_lvl3, 0, NULL, SDL_FLIP_NONE);
            if(item_take[0] == true) {
                SDL_RenderCopyEx(renderer, textures[27], NULL, &portal, 0, NULL, SDL_FLIP_NONE);
            }


        }
        else if (time1 == 1) {
            SDL_RenderCopyEx(renderer, textures[39], NULL, &background, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[32], NULL, &dirt_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[28], NULL, &platform_down_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[31], NULL, &platform_top_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[34], NULL, &platform_mid_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[35], NULL, &spikes_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[33], NULL, &platform1_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[33], NULL, &platform2_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[30], NULL, &ladder_1_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[38], NULL, &spikes_1_lvl3, 0, NULL, SDL_FLIP_NONE);
            SDL_RenderCopyEx(renderer, textures[36], NULL, &button1_lvl3, 0, NULL, SDL_FLIP_NONE);        

                        if(item_take[0] == false) { 
                SDL_RenderCopyEx(renderer, textures[26], NULL, &potion, 0, NULL, SDL_FLIP_NONE);
            }
        }
    }
}