#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "menu.h"

/**
* This function returns a random number.
*
* @param int start
*		The first possible number.
* @param int boundary
*		The last possible number.
* @return
*		A random number between 'start' and 'boundary'.
*/
int giveMeRandint(int start, int boundary) {
	srand(rand() + time(NULL));
	return start + rand() % boundary;
}

/**
* Verifies if there're 4 identical pawns aligned.
*
* @param char alArray[6][7]
*		The grid.
* @return
*		0 if the yellow pawns are,
*		1 if the red's one are,
*		-1 otherwise.
*/
int isAligned(Pawn alArray[6][7]) {
	int l, c;
	Pawn pawn = {' '};
		
	for (l = 0; l < 6; l++) {
		for (c = 0; c < 7; c++) {
			// Horizontal
			if (!pawnCmp(alArray[l][c], pawn) && pawnCmp(alArray[l][c], alArray[l][c+1])
				&& pawnCmp(alArray[l][c+1], alArray[l][c+2])
				&& pawnCmp(alArray[l][c+2], alArray[l][c+3])) {
					return (alArray[l][c].team + 1) % 2;
			}//Vertical
			else if (!pawnCmp(alArray[l][c], pawn) && pawnCmp(alArray[l][c], alArray[l+1][c])
				&& pawnCmp(alArray[l+1][c], alArray[l+2][c])
				&& pawnCmp(alArray[l+2][c], alArray[l+3][c])) {
					return (alArray[l][c].team + 1) % 2;
			}
		}
	} //Oblique1
	for (l = 0; l < 3; l++) {
		for (c = 0; c < 4; c++) {
			if (!pawnCmp(alArray[l][c], pawn) && pawnCmp(alArray[l][c], alArray[l+1][c+1])
				&& pawnCmp(alArray[l+1][c+1], alArray[l+2][c+2]) 
				&& pawnCmp(alArray[l+2][c+2], alArray[l+3][c+3])) {
					return (alArray[l][c].team + 1) % 2;
			}
		}
	} //Oblique2
	for (l = 0; l < 3; l++) {
		for (c = 6; c > 2; c--) {
			if (!pawnCmp(alArray[l][c], pawn) && pawnCmp(alArray[l][c], alArray[l+1][c-1])
				&& pawnCmp(alArray[l+1][c-1], alArray[l+2][c-2]) 
				&& pawnCmp(alArray[l+2][c-2], alArray[l+3][c-3])) {
					return (alArray[l][c].team + 1) % 2;
			}
		}
	}
	return -1;
}

/**
* This function returns a value that says if the game is over.
*
* @return
*		The same as the isAligned function
*		plus 3 if the game is drawn.
*/
int isDone(Pawn finishedArray[6][7]) {
	int i, j;
	
	if (isAligned(finishedArray) == -1) {
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 7; j++) {
				if (finishedArray[i][j].team == 32) {
					return -1;
				}
			}
		}
		return 3;
	}
	return isAligned(finishedArray);
}

/**
* This function compare two Pawn objects.
*
* @param Pawn first
*		The first pawn to compare.
* @param Pawn second
*		The second pawn to compare.
* @return
*		0 if they're different, 1 otherwise.
*/
int pawnCmp(Pawn first, Pawn second) {
	return (first.team == second.team);
}

/**
* This function verifies if there's still place in
* the chosen column.
* If there is'nt anymore, it returns -1.
* Else, the function returns the line.
*
* @param char pArray[6][7]
*		The grid.
* @param column
*		The chosen column.
* @return
*		The line of the pawn.
*/
int verifCase(Pawn verifArray[6][7], int column) {
	int line = 5;
	Pawn pawn = {' '};
	
	while (!pawnCmp(verifArray[line][column], pawn)) {
		if (line < 0) { //If the column is full
			return -1;
		}
		line--;
	}
	
	return line;
}

/**
* Displays the grid.
*
* @param char arr[6][7]
*		The grid.
*/
void displayGrid(Pawn dispArray[6][7]) {
	int i, j;
	
	printf("\033[2J\033[1;1H");
	for (i = 0; i < 6; i++) {
		concatenation(" ", 4, 0);
		concatenation("\033[38;5;28m-\033[0m", 29, 1);//Code de coloration
		for (j = 0; j < 7; j++) {
			if (j == 0) {
				concatenation(" ", 4, 0);
			}
			if (dispArray[i][j].team == 32) {
				printf("\033[38;5;28m|\033[0m   ");
			} else if (dispArray[i][j].team == 82) {
				printf("\033[38;5;28m|\033[0m \033[1;31m%c\033[0m ",
					dispArray[i][j].team);
			} else {
				printf("\033[38;5;28m|\033[0m \033[1;33m%c\033[0m ",
					dispArray[i][j].team);
			}
			if (j == 6) {
				printf("\033[38;5;28m|\033[0m\n");
			}
		}
	}
	concatenation(" ", 4, 0);
	concatenation("\033[38;5;28m-\033[0m", 29, 1);
	concatenation(" ", 6, 0);
	printf("\033[1;36m0   1   2   3   4   5   6\033[0m\n\n");
}

/**
* Displays the result of the game.
*
* @param int result
*		The result:
*		0 if the yellow wins,
*		1 if this is the red one,
*		3 it's a drawn.
*/
void displayResult(int result) {
	char win[7][15] = {"  🎉  ", "  🎊  ", "  😀",  "  🙃 " , "  😎", "  👏🏻",
		"  👍🏻 "};
	char drawn[5][10] = {"  😞", "  😩 ", "  😧", "  😢" , "  👎🏻"};
	
	if (result == 0) {
		printf("The winner is the yellow player !%s\n", win[giveMeRandint(0, 7)]);
	} else if (result == 1) {
		printf("The winner is the red player !%s\n", win[giveMeRandint(0, 7)]);
	} else {
		printf("The game is drawn%s\n", drawn[giveMeRandint(0, 4)]);
	}
}

/**
* This is the main function of the file.
* It initializes the grid and launches the game.
* When the game is over, it displays the result
* and re-launches the menu.
*/
void game() {
	Pawn grid[6][7];
	int turn = 0;
	
	initGrid(grid);
	while (isDone(grid) == -1) {
		playerChoice(grid, turn++);
	}
	
	printf("\033[2J\033[1;1H");
	displayGrid(grid);
	
	displayResult(isDone(grid));
	getchar(); //To take the previous entered key.
	getchar(); //To pause before displaying the menu.
}

/**
* Initializes the grid.
*
* @param char array[6][7]
*		The grid.
*/
void initGrid(Pawn initArray[6][7]) {
	int i, j;
	
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 7; j++) {
			initArray[i][j].team = ' ';
		}
	}
}

/**
* This function places a pawn in the chosen case of the grid.
*
* @param char placeArray[6][7]
*		The grid.
* @param int line
*		The chosen line.
* @param int col
*		The chosen column.
* @param player
*		The current player.
*/
void placePawn(Pawn placeArray[6][7], int line, int col, int player) {
	if (player % 2 == 0) {
		placeArray[line][col].team = 'Y';
	} else {
		placeArray[line][col].team = 'R';
	}
}

/**
* This function displays the grid and ask a column
* to the current player.
* If the chosen column isn't full, the pawn is placed.
* Else, the player has to enter another column.
*
* @param char pArray[6][7]
*		The grid.
* @param int turn
*		The current turn.
*/
void playerChoice(Pawn pArray[6][7], int turn) {
	char col;
	int x, n = 0;
	
	do {
		if (n != 0) {
			printf("\a"); //Beeps when the player makes a mistake
		}
		displayGrid(pArray);
		concatenation(" ", 6, 0);
		if (turn % 2 == 0) {
			printf("Yellow's turn (column)\033[5;37m:\033[0m ");//le 5 fait clignoter
		} else {
			printf("Red's turn (column)\033[5;37m:\033[0m ");
		}
		scanf(" %c", &col);
		x = verifCase(pArray, (col - 48));
		n++;
	} while (col < 48 || col > 54 || x == -1);
	
	placePawn(pArray, x, (col - 48), turn);
}
