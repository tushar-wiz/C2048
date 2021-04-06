#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "move.h"
#define arr(i,j,n) *(arr+((i)*n)+j)
#define temp(i,j,n) *(temp+((i)*n)+j)

void rotate(int *arr, int n, int rotations){
    rotations %= 4;
    if(rotations==0)
        return;
    
    int r;
    int *temp = (int* )calloc(n*n,sizeof(int));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp(j,i,n) = arr(i,j,n);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr(i,n-1-j,n) = temp(i,j,n);
        }
    }
    
    free(temp);
    temp = NULL;
    
    if(rotations==1)
        return;
    else
        return rotate(arr,n,rotations-1);
}

int moveUp(int *arr, int n, int rot){
    int score = 0;
    int legalMove = -1;
    rotate(arr,n,rot);
    
    //loops column wise and does it again n-1 times as it is 
    //the least required to put a number from the bottom of 
    //the column to the top
    for(int repeat=0;repeat<n-1;repeat++){
        for(int j=0;j<n;j++){
            for(int i=1;i<n;i++){
                if(arr(i-1,j,n)==0 && arr(i,j,n)!=0){
                    arr(i-1,j,n) = arr(i,j,n);
                    arr(i,j,n) = 0; 
                    legalMove = 1;
                }
            }
        }
    }
    
    //loops column wise
    for(int j=0;j<n;j++){
        for(int i=1;i<n;i++){
            if(arr(i,j,n)==0){
                continue;
            }
            //case 1 - when above number is same ADD
            else if(arr(i-1,j,n)==arr(i,j,n)){
                arr(i-1,j,n) *= 2;
                score += arr(i-1,j,n);
                arr(i,j,n) = 0;
                legalMove = 1;
            }
            // case 2 - when above number is 0 MOVE UP
            else if(arr(i-1,j,n)==0){
                arr(i-1,j,n) = arr(i,j,n);
                arr(i,j,n) = 0;
                legalMove = 1;
            }
            //case 3 - when above number is a non zero and not equal DO NOTHING
            else{
                continue;
            }
        }
    }
    
    rotate(arr,n,4-rot);
   
    return (legalMove==1)?score:legalMove;
}