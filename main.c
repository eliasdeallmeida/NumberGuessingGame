#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "features.h"

int main(void){
    int difficulty, totalAttempts, secretNumber, guess, *guesses, found;
    float points;
    char restart;
    
    srand(time(NULL));

    do{
        setGameDifficulty(&difficulty, &totalAttempts);

        if(!(guesses = malloc(totalAttempts * sizeof(int)))){
            printf("ERROR: Insufficient memory to allocate.");
            exit(1);
        }
        
        secretNumber = rand() % MAX_VALUE + MIN_VALUE;
        points = MAX_POINTS;

        for(int i = 0; i < totalAttempts; i++){
            inputGuess(&guess, guesses, i + 1, totalAttempts);

            guesses[i] = guess;
            found = (guess == secretNumber);

            if(found || i + 1 == totalAttempts){
                break;
            }else if(guess > secretNumber){
                printf("Try a lower number!\n\n");
            }else{
                printf("Try a higher number!\n\n");
            }

            points -= (float) abs(guess - secretNumber) / 2;
        }

        if(found){
            showVictoryMessage();
            printf("Total score: %.2f points.\n", points);
        }else{
            showDefeatMessage();
            printf("The secret number was %d.\n\n", secretNumber);
        }

        askRestartGame(&restart);
    }while(restart == OPTION_YES);

    printf("\nThank you for playing!\n");

    return 0;
}
