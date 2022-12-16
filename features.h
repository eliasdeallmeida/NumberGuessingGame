#ifndef FEATURES_HEADER
#define FEATURES_HEADER

#include <stdio.h>
#include "util.h"
#include "output.h"

#define MIN_DIFFICULTY 1
#define MAX_DIFFICULTY 3

#define EASY_MODE_ATTEMPTS 12
#define NORMAL_MODE_ATTEMPTS 8
#define HARD_MODE_ATTEMPTS 5

#define MAX_POINTS 100

#define MIN_VALUE 1
#define MAX_VALUE 100

#define OPTION_YES 'Y'
#define OPTION_NO 'N'

void setGameDifficulty(int *, int *);
void inputDifficulty(int *, int *, char *);
void inputGuess(int *, int *, int, int);
void askRestartGame(char *);
void inputRestartOption(char * , char *);

#endif
