#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"


/**
* This function displays the menu and takes the player's choice.
*
* @return
*		The player's choice.
*/
char displayMenu() {
	char choice;
	char sections[][40] = {"\033[38;5;160mProgram realized by:",
		"\033[38;5;160mSection:", "\033[38;5;160mGroupe:",
		"\033[38;5;160mAcademic year:", "\033[38;5;160mCreation date:\033[0m"}; //Creation date
	char data[][40] = {"\033[38;5;215mDUCOBU Alexandre", "\033[38;5;215mInfo",
		"\033[38;5;215m5", "\033[38;5;215m2015-2016", "\033[38;5;215m20/10/2015"};
	
	do {
		printf("\033[2J\033[1;1H");
		printf(" ");
		concatenation("\033[38;5;28m-", 45, 1);
		printf("|%s\033[0m", sections[0]);
		concatenation(" ", 9, 0);
		printf("%s\033[38;5;28m|\n|\033[0m%s", data[0], sections[1]);
		concatenation(" ", 8, 0);
		printf("%s", data[1]);
		concatenation(" ", 15, 0);
		printf("%s  %s\033[38;5;28m|\n|%s", sections[2], data[2], sections[3]);
		concatenation(" ", 22, 0);
		printf("%s\033[38;5;28m|\n|%s", data[3], sections[4]);
		concatenation(" ", 21, 0);
		printf("%s\033[38;5;28m|\n ", data[4]);
		concatenation("-", 45, 1);
		printf("\033[0m TP7: Four in row\n ");
		concatenation("\033[38;5;28m=", 18, 0);
		printf("[\033[1;33m Menu \033[38;5;28m]");
		concatenation("=", 19, 1);
		printf("\033[0m (1) Play a game\n (2) Display rules\n (3) Quit\n \033[38;5;28m");
		concatenation("=", 45, 1);
		printf("\033[0m What's your choice \033[5;37m?\033[0m ");
		scanf(" %c", &choice);
		printf(" ");
		concatenation("\033[38;5;28m-", 45, 1);
		printf("\033[0m");
	} while (choice < 49 || choice > 51);
	
	return choice;
}

//Code from Guillaume
/**
* This function concatenates characters.
* It simplifies the creation of strings like this: "-----".
*
* @param char letter[]
*		The chosen character.
* @param int n
*		The number of times we need the character.
* @param int returnAtTheAndOfLine
*		If we need to change of line, we enter 1,
*		otherwise, we enter 0.
*/
void concatenation(char letter[], int n, int returnAtTheAndOfLine) {
	int i = 0;
	
	while (i < n) {
		printf("%s", letter);
		i++;
	}
	if (returnAtTheAndOfLine == 1) {
		printf("\n");
	}
}
