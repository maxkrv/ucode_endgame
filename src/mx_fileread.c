#include "header.h"
void mx_fileread(int map[33][60], char*s) {
    FILE *ptrfile;
    ptrfile = fopen(s,"r+");
    if(ptrfile == NULL)
     exit(1);
    for(int i = 0; i < 33; i++) {
        for(int j = 0; j < 60; j++) {
            fscanf(ptrfile, "%i", &map[i][j]);
        }
    }
    fclose(ptrfile);
}

