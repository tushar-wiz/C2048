#include <stdio.h>
#include <stdint.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "check.h"
#include "move.h"
#include "printBoard.h"
#define arr(i,j,n) *(arr+((i)*n)+j)
#define temp(i,j,n) *(temp+((i)*n)+j)
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3


int main(){
    int n=5, legal, score=0, direction,keyPress,temp;
    size_t win = 0;
    int *arr = calloc(n*n, sizeof(int));

    printf("Welcome to the 2048 game\nTo play use the wasd keys\n");
    printf("NOTE-Key press doesnt require to have Enter pressed once the game starts\n");
    printf("Pressing q will end the game\n");
    printf("Enter s to start(Press Enter)\n");
    printf("ONLY USE LOWERCASE Letters\n");
    if(getchar()!=115)
        goto END;
    
    spawn_zero(arr,n);
    spawn_zero(arr,n);
    printBoard(arr,n,score);

START:
    temp = checkMovePossible(arr,n);
    if(temp == -1){
        win = 1;
        goto END;
    }
    else if(temp==0)
        goto END;

    keyPress = getch();

    switch (keyPress){
    case 119:
        direction = UP;
        break;
    case 97:
        direction = LEFT;
        break;
    case 115:
        direction = DOWN;
        break;
    case 100:
        direction = RIGHT;
        break;
    case 113:
        goto END;
    default:
        goto START;
    }

    legal = moveUp(arr,n,direction);

    if(legal == -1)
        goto START;
    else
        score += legal;
    spawn_zero(arr,n);
    printBoard(arr,n,score);
    goto START;
END:
    if(win)
        printf("You WIN!!");
    printf("Exiting in 5 seconds..\n");
    printf("YOUR SCORE : %d",score);
    Sleep(5000);
    return 0;
}