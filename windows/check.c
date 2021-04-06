#include <stdlib.h>
#include <time.h>
#define arr(i,j,n) *(arr+((i)*n)+j)
#define temp(i,j,n) *(temp+((i)*n)+j)

int checkMovePossible(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr(i,j,n)==2048){
                return -1;
            }
        }
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr(i-1,j,n)==arr(i,j,n) || arr(i,j,n)==0){
                return 1;
            }
        }
    }
    
    for(int j=1;j<n;j++){
        for(int i=0;i<n;i++){
            if(arr(i,j-1,n)==arr(i,j,n) || arr(i,j,n)==0){
                return 1;
                }
        }
    }

    return 0;
}

void spawn_zero(int *arr, int n){
    int count=0, place;
    int *zeroArr = (int *)calloc(n*n, sizeof(int));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr(i,j,n)==0){
                zeroArr[count] = (i*n)+j;
                count++;
            }
        }
    }
    
    srand((unsigned)time(NULL));
    place = rand()%count;

    arr[zeroArr[place]] = (rand()%10 > 1)?2:4;
    free(zeroArr);
    return;
}