#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "printBoard.h"
#define dfltSpaces 8
#define arr(i,j,n) *(arr+(i*n)+j)

void printBoard(int *arr, int n, int score){
    //dynamic spacing - spaces are decided on length of the numbers
    int remSpaces,r,g,b,num;
    system("clear");
    printf("SCORE : %d\n\n",score);
    int colors[12][3] = {   {0,0,0},
                            {237,224,200},
                            {242,177,121},
                            {245,149,98},
                            {246,124,95},
                            {246,94,59},
                            {237,204,97},
                            {255,205,63},
                            {217,179,42},
                            {214,217,116},
                            {98,217,81},
                            {78,255,255}
                            };

    for(int i=0;i<(2*n)-1;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                num = arr(i/2,j,n);

                if(num == 0){
                    r=0;
                    g=0;
                    b=0;
                    printf("   .");
                    remSpaces = 4;
                }
                else{
                    int numLog = log2(num);
                    r = colors[numLog][0];
                    g = colors[numLog][1];
                    b = colors[numLog][2];
                    printf("\033[30;48;2;%d;%d;%dm   %d\033[0m",r,g,b,num);
                    //getting length of number
                    remSpaces = dfltSpaces - floor(log10(num) + 1) - 3;
                }
                for(int p=0;p<remSpaces;p++){
                    printf("\033[30;48;2;%d;%d;%dm \033[0m",r,g,b);
                }
            }
        }
        printf("\n");
    }

}
