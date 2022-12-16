#include "features.h"

void setGameDifficulty(int *difficulty, int *attempts){
    char valid = 0;
    
    do{
        showMenuDifficulty();
        inputDifficulty(difficulty, attempts, &valid);
    }while(!valid);
    
    printf("You have %d attempts to find the secret number in the range from %d to %d\n\n", *attempts, MIN_VALUE, MAX_VALUE);
}

void inputDifficulty(int *difficulty, int *attempts, char *valid){
    printf("-> Your choice: ");
    scanf("%d", difficulty);

    *valid = (*difficulty >= MIN_DIFFICULTY && *difficulty <= MAX_DIFFICULTY)? ++*valid : *valid;

    clearScreen();
    
    switch(*difficulty){
        case 1:
            *attempts = EASY_MODE_ATTEMPTS;
            printf("Easy mode selected.\n\n");
            break;
        case 2:
            *attempts = NORMAL_MODE_ATTEMPTS;
            printf("Normal mode selected.\n\n");
            break;
        case 3:
            *attempts = HARD_MODE_ATTEMPTS;
            printf("Hard mode selected.\n\n");
            break;
        default:
            printf("ERROR: Invalid difficulty.\n\n");
    }
}

void inputGuess(int *answer, int *guesses, int attempt, int totalAttempts){
    char valid = 0;

    do{
        printf("=== Attempt %d of %d ===\n", attempt, totalAttempts);
        printf("-> Your guess: ");
        scanf("%d", answer);
        
        if(*answer < MIN_VALUE || *answer > MAX_VALUE){
            printf("ERROR: Guess is out of range!\n\n");
            continue;
        }
    
        char repeated = 0;
        for(int j = 0; j < attempt && !repeated; j++){
            (*answer == guesses[j])? ++repeated : repeated;
        }
        (repeated)? printf("ERROR: You can't enter repeated numbers!\n\n") : ++valid;
    }while(!valid);
}

void askRestartGame(char *answer){
    char valid = 0;
    
    do{
        showRestartMessage();
        inputRestartOption(answer, &valid);
        clearScreen();
    }while(!valid);
}


void inputRestartOption(char *answer, char *valid){
    printf("-> Your answer: ");
    scanf(" %c", answer);

    clearBuffer();
    *answer = toupper(*answer);
    
    (*answer == OPTION_YES || *answer == OPTION_NO)? ++*valid : printf("ERROR: Invalid answer.\n");
}
