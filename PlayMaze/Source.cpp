//This is a maze that a user can play
//Author: Borhan Alizadeh
//Date: September 3, 2016

#include <iostream>
#include <Windows.h>
#include <conio.h>



using namespace std;

char mazeSheet[10][10] =
{
'O','O','O','O','O','O','O','O','O','O'
,'X',' ',' ','O','O','O','O','O','O','O'
,'O','O',' ','O','O','O','O','O','O','O'
,'O','O',' ','O',' ',' ',' ',' ',' ','O'
,'O','O',' ','O',' ','O','O','O',' ','O'
,'O','O',' ','O',' ','O','O','O',' ','O'
,'O','O',' ',' ',' ','O','O','O',' ','O'
,'O','O','O','O','O','O','O','O',' ','O'
,'O','O','O','O','O','O','O','O',' ','O'
,'O','O','O','O','O','O','O','O',' ','O'
};

int currSX;
int currSY;

void start();
void printMaze();
int getCurrSX();
int getCurrSY();
void setCurrSX(int x);
void setCurrSY(int y);
boolean checkWin(int x, int y);

char s = mazeSheet[1][0];


int main(void) {
	start();
	system("CLS");
	printMaze();
	setCurrSX(1);
	setCurrSY(0);
	
	

	int c = 0;
	int currX;
	int currY;
	while (1)
	{

		currX = getCurrSX();
		currY = getCurrSY();

		c = 0; //key up
		switch ((c = _getch())) {
		case 72:
			if (currX >= 0) {
				if (mazeSheet[currX - 1][currY] == ' ') {
					setCurrSX(currX - 1);

					if (!checkWin(currX - 1, currY)) {
						mazeSheet[currX][currY] = ' ';
						mazeSheet[currX - 1][currY] = 'X';
						system("CLS");
						printMaze();
					}
					else {
						mazeSheet[1][0] = 'X';
						printf("\t\t\t\t\t\t\t");
						printf("You win!");
						Sleep(3000);
						main();
					}
				}
			}
			break;

		case 80: //key down
			if (currX < 10) {
				if (mazeSheet[currX + 1][currY] == ' ') {
					setCurrSX(currX + 1);

					if (!checkWin(currX+1, currY)) {
						mazeSheet[currX][currY] = ' ';
						mazeSheet[currX + 1][currY] = 'X';
						system("CLS");
						printMaze();
					}
					else {
						mazeSheet[1][0] = 'X';
						printf("\t\t\t\t\t\t\t");
						printf("You win!");
						Sleep(3000);
						main();

					}
				}
			}
			break;

		case 75: //key left
			if (currY > 0) {
				if (mazeSheet[currX][currY - 1] == ' ') {
					setCurrSY(currY - 1);
					if (!checkWin(currX, currY - 1)) {
						mazeSheet[currX][currY] = ' ';
						mazeSheet[currX][currY - 1] = 'X';
						system("CLS");
						printMaze();
					}
					else {
						mazeSheet[1][0] = 'X';
						printf("\t\t\t\t\t\t\t");
						printf("You win!");
						Sleep(3000);
						main();
					}

				}
			}
			break;

		case 77: //key right
			if (currY < 10) {
				if (mazeSheet[currX][currY+1] == ' ') {
					setCurrSY(currY + 1);
					if (!checkWin(currX, currY + 1)) {
						mazeSheet[currX][currY] = ' ';
						mazeSheet[currX][currY + 1] = 'X';
						system("CLS");
						printMaze();
					}
					else {
						mazeSheet[1][0] = 'X';
						printf("\t\t\t\t\t\t\t");
						printf("You win!");
						Sleep(3000);
						main();
					}

				}
			}
			break;

		default:
			cout << endl << "null" << endl;  // not arrow
			break;
		}

	}

	return 0;
}



//Welcome message
void start() {

	string s1 = "Welcome to this Maze";
	string s2 = "Please use arrows keys on your keyboard to play!";
	printf("\n\n\n");
	printf("\t\t\t\t\t\t");

	for (char c1 : s1) {
		printf("%c", c1);
		Sleep(20);
	}
	printf("\n");
	printf("\t\t\t\t");

	for (char c2 : s2) {
		printf("%c", c2);
		Sleep(20);
	}
	Sleep(3000);
} 


//Print the maze on screen
void printMaze() {
	for (int x = 0; x < 10; ++x) {
		printf("\n");
		printf("\t\t\t\t\t\t\t");
		for (int y = 0; y < 10; ++y) {
			printf("%c", mazeSheet[x][y]);
		}
	}
}



//set the corrdinate of X for start point
void setCurrSX(int x) {
	currSX = x;
}


//Get the coordinate of X
int getCurrSX() {
	return currSX;
}

//set the corrdinate of Y for start point
void setCurrSY(int y) {
	currSY = y;
}

//Get the coordinate of y
int getCurrSY() {
	return currSY;
}


//Check to see if user wins
boolean checkWin(int x, int y) {
			if ((x == 9) && (y == 8)) {
				return true;
	}
			return false;
}
