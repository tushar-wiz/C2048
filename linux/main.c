#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "check.h"
#include "move.h"
#include "printBoard.h"
#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3


int main(){
    int n=5, legal, score=0, direction,keyPress,temp;
    size_t win = 0;
    int *arr = calloc(n*n, sizeof(int));
    
    printf("Welcome to the 2048 game\nTo play use the wasd keys\n");
    printf("NOTE-You would be required to press Enter after every command\n");
    printf("Entering multiple keys like aswad will execute them one by one\n");
    printf("Pressing q will end the game\n");
    printf("Enter s to start\n");
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

    keyPress = getchar();

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
        printBoard(arr,n,score);
        goto START;
    }

    legal = moveUp(arr,n,direction);

    if(legal == -1){
        goto START;
    }
    else
        score += legal;
    spawn_zero(arr,n);
    printBoard(arr,n,score);
    goto START;
END:
    if(win)
        printf("YOU WIN!!");
    printf("Exiting in 5 seconds..\n");
    printf("YOUR SCORE : %d\n",score);
    sleep(5);
    return 0;
}
