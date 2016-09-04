//This is a maze that a user can play
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
,'O','O','O','O','O','O','O','O','#','O'
};

int currSX;
int currSY;

void start();
void printMaze();
void printEmptyMaze();
int getCurrSX();
int getCurrSY();
void setCurrSX(int x);
void setCurrSY(int y);

char s = mazeSheet[1][0];


int main(void) {
	//start();
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

		c = 0;
		switch ((c = _getch())) {
		case 72:
			if (currY > 0) {
				if (mazeSheet[currX][currY - 1] == ' ') {
					mazeSheet[currX][currY] = ' ';
					mazeSheet[currX][currY+1] = 'S';
					setCurrSY(currY - 1);

				}
			}
			cout << endl << "Up" << endl;//key up
			break;

		case 80:
			cout << endl << "Down" << endl;   // key down
			break;

		case 75:
			cout << endl << "Left" << endl;  // key left
			break;

		case 77:
			if (currX < 10) {
				printf("%d and %d", currX, currY);
				if (mazeSheet[currX][currY+1] == ' ') {
					cout << endl << "Hello" << endl;  // key right

					mazeSheet[currX][currY] = ' ';
					mazeSheet[currX][currY + 1] = 'X';
					system("CLS");
					printMaze();
					setCurrSY(currY + 1);

				}
			}
			cout << endl << "Right" << endl;  // key right
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

	for (char c1 : s1) {
		printf("%c", c1);
		Sleep(50);
	}
	printf("\n");

	for (char c2 : s2) {
		printf("%c", c2);
		Sleep(50);
	}
} 


//Print the maze on screen
void printMaze() {
	for (int x = 0; x < 10; ++x) {
		printf("\n");
		for (int y = 0; y < 10; ++y) {
			printf("%c", mazeSheet[x][y]);
		}
	}
}


//Print an empty maze on screen
void printEmptyMaze() {
	for (int x = 0; x < 10; ++x) {
		printf("\n");
		for (int y = 0; y < 10; ++y) {
			printf("%c", ' ');
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
