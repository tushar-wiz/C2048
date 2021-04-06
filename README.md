# C2048
I have chosen to make two versions of 2048 based on the OS.
Primarily I made the code for windows but I found that you could have colors in the executable in Linux with the help of Escape Sequence codes otherwise both versions rely on the same underlying logic.

### Windows 
Compiled using gcc 9.2.0
```
gcc -o main main.c check.c printBoard.c move.c
```
* Uses getch() which doesnt require Enter to be hit after every character key is pressed
* Uses system("cls") to clear the screen
* Only select versions of windows support escape sequence codes to output colour
![alt text](https://imgur.com/hdVf0Jh.png)

### Linux
You may have to compile again as the executable in the folder has been compiled on Raspberry Pi(which is arm based)
```
gcc -o main main.c check.c printBoard.c move.c -lm
```
* Uses getchar() which requires the enter key to be hit after every input
* Uses system("clear") to clear the screen
* Uses Escape Sequence codes to output colour in the program
![alt text](https://imgur.com/rAhMcPj.png)

## How to Play

* At the start, the Program will give a brief introduction of how to play 
* Enter 's' to start
* NOTE - Program only accepts lowercase letters
* If you have entered the 's' key the program will start, otherwise it will terminate
* After that the board will Load and you would be able to use wasd keys to move the board around, where wasd corresponds to the arrow keys direction.
* You can use the q key to exit the game anytime.
* After exiting the program will wait for 5 seconds, display your score and then exit the program
