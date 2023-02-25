#include "header.h"

void mx_check_button(bool *button_on) {
    if (button_on[0] == true && seed_r == true) {
        tree_r = true;
        map1[20][24] = 1;
        map1[20][25] = 1;
        map1[20][26] = 1;
        map1[20][27] = 1;
        map1[15][28] = 1;
        map1[15][29] = 1;
        map1[15][30] = 1;
        map1[15][31] = 1;
        map1[11][32] = 1;
        map1[11][33] = 1;
        map1[11][34] = 1;
        map1[11][35] = 1;
    } else if (button_on[0] == false) {
    }
}



