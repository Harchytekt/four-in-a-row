#ifndef GAME_H
# define GAME_H

typedef struct Pawn Pawn;
struct Pawn {
	char team;
};

int isAligned(Pawn alArray[6][7]);
int isDone(Pawn finishedArray[6][7]);
int pawnCmp(Pawn first, Pawn second);
int verifCase(Pawn verifArray[6][7], int column);

void displayGrid(Pawn dispArray[6][7]);
void displayResult(int result);
void game();
void initGrid(Pawn initArray[6][7]);
void placePawn(Pawn placeArray[6][7], int line, int col, int player);
void playerChoice(Pawn pArray[6][7], int turn);

#endif /* !GAME_H */