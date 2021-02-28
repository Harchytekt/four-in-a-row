#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "game.h"
#include "rules.h"

/**
* This function launches the menu of the game.
*
* In this project, the functions are sorted alphabetically.
*/
int main() {
	char choiceMenu = displayMenu();
	
	if (choiceMenu == 49) {
		game();
		main();
	} else if (choiceMenu == 50) {
		rules();
		main();
	} else {
		concatenation(" ", 4, 0);
		printf("\033[38;5;38mGoodbye !\033[0m 👋🏻\n");
	}
	
	return 0;
}
