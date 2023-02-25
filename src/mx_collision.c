#include "header.h"

const int character_height = 64;
const int character_width = 64;
const int box = 64;

void mx_check_collision(int *character_x, int *character_y, int map[33][60], bool *crate_down_col, bool *item_take, bool *button_on, int *crates_x, int *crates_y) {
    int count_left = 0;
    int count_right = 0;
    int count_down = 0;
    int count_up = 0;
    int crate_count_down[num_cubes];
    for (int i = 0; i < num_cubes; i++) {
        crate_count_down[i] = 0;
    }
    int button_count[num_buttons];
    for (int i = 0; i < num_buttons; i++) {
        button_count[i] = 0;
    }
    int take_item_count[num_cubes];
    for (int i = 0; i < num_cubes; i++) {
        take_item_count[i] = 0;
    }
    if(map[(*character_y / 32) + 1][*character_x / 32] == 3) { // spikes
        isspikes = true;
    }

    for (int left = 16; left <= character_height + 16; left +=32) {
        int cube_l = left - 16;
        if (left == character_height + 16) {
            left = character_height;
        }
        int index_y = (*character_y + left) / 32;
        int index_x = (*character_x - SPEED) / 32;
        if (map[index_y][index_x] == 1) {
            count_left++;
        } else {
            left_col = false;
        }
        for (int all = 0; all < num_cubes; all++) {
            bool crate_right_col = true;
            if (*character_x - SPEED == crates_x[all] + box && *character_y + cube_l < crates_y[all] + box && *character_y + cube_l > crates_y[all]) {
                for (int i = 0; i < num_items; i++) {
                    if (crates_x[all] == crates_x[i] + box + SPEED && crates_y[all] + box == crates_y[i] + box) {
                        crate_right_col = false;
                        count_left++;
                    }
                }
                for (int right_cube = 0; right_cube < box; right_cube += box) {
                    index_x -= 2;
                    if (map[index_y][index_x] != 1) {
                        if (crate_right_col == true) {
                            crates_x[all] -= SPEED;
                        }
                    } else {
                        count_left++;
                    }
                }

            }
        }
    }
    if (count_left != 0) {
        left_col = true;
    }
    for (int right = 16; right <= character_height + 16; right +=32) {
        int cube_r = right - 16;
        if (right == character_height + 16) {
            right = character_height;
        }
        int index_y = (*character_y + right) / 32;
        int index_x = (*character_x + character_width + SPEED) / 32;
        if (map[index_y][index_x] == 1) {
            count_right++;
        } else {
            right_col = false;
        }
        for (int all = 0; all < num_cubes; all++) {
            bool crate_left_col = true;
            if (*character_x + character_width + SPEED == crates_x[all] && *character_y + cube_r < crates_y[all] + box && *character_y + cube_r > crates_y[all]) {
                for (int i = 0; i < num_items; i++) {
                    if (crates_x[all] + box + SPEED == crates_x[i] && crates_y[all] + box == crates_y[i] + box) {
                        crate_left_col = false;
                        count_right++;
                    }
                }
                for (int right_cube = 0; right_cube < box; right_cube += box) {
                    index_x += 2;
                    if (map[index_y][index_x] != 1) {
                        if (crate_left_col == true) {
                            crates_x[all] += SPEED;
                        }
                    } else {
                        count_right++;
                    }
                }
            }
        }
    }
    if (count_right != 0) {
        right_col = true;
    }
    for (int up = 0; up <= character_width; up +=32) {
        int index_y = (*character_y - SPEED) / 32;
        int index_x = (*character_x + up) / 32;
        if (map[index_y][index_x] == 1) {
            up_col = true;
            count_up++;
        } else {
            up_col = false;
        }
    }
    if (count_up != 0) {
        up_col = true;
    }
    for (int down = 0; down <= character_width; down +=32) {
        int index_y = (*character_y + character_height + SPEED) / 32;
        int index_x = (*character_x + down) / 32;
        if (map[index_y][index_x] == 1) {
            down_col = true;
            count_down++;
        } else {
            down_col = false;
        }
        for (int i = 0; i < num_buttons; i++) {
            int num = 4;
            if (map[index_y - 1][index_x] == num) {
                 button_count[i]++;
            } else {
                 button_on[i] = false;
            }
            num++;
        }
        for (int i = 0; i < num_cubes; i++) {
                if (*character_x + down < crates_x[i] + box  && *character_x + down > crates_x[i] && *character_y + 1 + box == crates_y[i]) {
                    count_down++;
                }
        }
    }
    if (count_down != 0) {
        down_col = true;
    }
    for (int i = 0; i < num_cubes; i++) {
        for (int down = 0; down <= box; down +=32) {
            int index_y = (crates_y[i] + box + SPEED) / 32;
            int index_x = (crates_x[i] + down) / 32;
            if (map[index_y][index_x] == 1) {
                crate_count_down[i]++;
            }
            if (map[index_y][index_x] == 0) {
                crate_down_col[i] = false;
            }
            //butonchiki
            for (int i = 0; i < num_buttons; i++) {
                 int num = 7;
                 if (map[index_y - 1][index_x] == num) {
                      button_count[i]++;
                 } else {
                      button_on[i] = false;
                 }
                 num++;
            }
        }
        if (crate_count_down[i] != 0) {
            crate_down_col[i] = true;
        }
    }
    for (int i = 0; i < num_buttons; i++) {
        if (button_count[i] != 0) {
            button_on[i] = true;
        }
    }
    int index_y_center = (*character_y + character_height / 2) / 32;
    int index_x_center = (*character_x + character_width / 2) / 32;
    //item
    int num = 5;
    for (int i = 0; i < num_items ; i++) {
        if (map[index_y_center][index_x_center] == num) {
            item_take[i] = true;
        }
        num++;
    }
    if (map[index_y_center][index_x_center] == 20 && item_take[0] == true) {
        seed_r = true;
    }
    if (button_on[0] == true) {
        bucket_r = false;
    }
    if (item_take[1] == true) {
        open_door = true;
    }

    mx_check_button(button_on);

    
}
