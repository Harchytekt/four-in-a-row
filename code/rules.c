#include <stdio.h>
#include <stdlib.h>

#include "rules.h"
#include "menu.h"

/**
* This function displays the rules of the game.
*/
void rules() {
	printf("\033[2J\033[1;1H");
	concatenation(" ", 10, 0);
	printf("\033[38;5;214m\033[48;5;235m   RULES   \033[0m\n\n");
	concatenation(" ", 8, 0);
	printf("\033[38;5;38m\033[48;5;235m  Introduction  \033[0m\n\n");
	printf("\033[38;5;42mConnect Four (also known as Four in a Row) is a "
		"two-player\ncconnection game in which the players first choose a "
		"color and then\ntake turns dropping colored discs from the top "
		"into a seven-column,\nsix-row vertically suspended grid.\n"
		"The pieces fall straight down, occupying the next available space\n"
		"within the column.\n"
		"The objective of the game is to connect four of one's own discs of\n"
		"the same color next to each other vertically, horizontally, or"
		" diagonally.\033[0m\n\n");
	concatenation(" ", 8, 0);
	printf("\033[38;5;38m\033[48;5;235m  User manual  \033[0m\n\n");
	printf("\033[38;5;42m1) You're in front of the menu.\n"
		"If you want to play, enter '1',\nelse, enter '2', if you want to "
		"see the rules.\nEnter 3 to quit the program.\n\n");
	printf("2) You are now in the game.\nThe first player (the yellow one) "
		"begins to play.\n"
		"To do that, he must enter the column (between 0 and 6):\n"
		"the pawn 'falls' down to the last available row.\n"
		"Now this is the red player's turn.\n"
		"If a player aligns 4 pawns vertically, horizontally or diagonally,\n"
		"this player win.\n"
		"Else if the grid is full and none of the players win,"
		"the game is drawn.\n\n");
	printf("3) Once the game is finished, press ENTER and the menu will "
		"reappear.\n\n");
	printf("4) If you are in the rules, press ENTER to go to the menu.\033[0m\n");
	getchar();
	getchar();
}
