#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define dfltSpaces 8
#define arr(i,j,n) *(arr+(i*n)+j)

void printBoard(int *arr, int n, int score){
    int remSpaces;
    system("cls");
    printf("SCORE : %d\n\n",score);
    //dynamic spacing - spaces are decided on length of the numbers
    

    for(int i=0;i<(2*n)-1;i++){
        if(i%2==0){
            for(int j=0;j<n;j++){
                if(arr(i/2,j,n) == 0){
                    printf(".");
                    remSpaces = 7;
                }
                else{
                    printf("%d",arr(i/2,j,n));
                    //getting length of number
                    remSpaces = dfltSpaces - floor(log10(arr(i/2,j,n)) + 1);
                }
                for(int p=0;p<remSpaces;p++){
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

}