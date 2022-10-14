#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define EASY_MODE 12
#define NORMAL_MODE 8
#define HARD_MODE 5
#define MIN 1
#define MAX 100

void clearScreen();

int main(void){
    int difficulty, totalAttempts, secretNumber, inputNumber, repeated, *guesses, found;
    float lostPoints, points;
    char reset;

    while(1){
        printf(" __________________________________________ \n");
        printf("|                                          |\n");
        printf("|        Select the game difficulty        |\n");
        printf("|   (1) Easy     (2) Normal     (3) Hard   |\n");
        printf("| _________________________________________|\n");
        printf("|/\n");
        printf("-> Your choice: ");
        scanf("%d", &difficulty);

        switch(difficulty){
            case 1:
                totalAttempts = EASY_MODE;
                printf("Easy mode selected\n\n");
                break;
            case 2:
                totalAttempts = NORMAL_MODE;
                printf("Normal mode selected\n\n");
                break;
            case 3:
                totalAttempts = HARD_MODE;
                printf("Hard mode selected\n\n");
                break;
            default:
                clearScreen();
                printf("ERROR: Invalid difficulty!\n\n");
                continue;
        }

        srand(time(NULL));
        guesses = calloc(totalAttempts, sizeof(int));
        secretNumber = rand() % MAX + MIN;
        points = 100;

        printf("You have %d attempts to find the secret number in the range from %d to %d\n\n", totalAttempts, MIN, MAX);

        for(int i = 1; i <= totalAttempts; i++){
            printf("=== Attempt %d of %d ===\n", i, totalAttempts);
            printf("-> Your guess: ");
            scanf("%d", &inputNumber);
            
            if(inputNumber < MIN || inputNumber > MAX){
                printf("ERROR: Input number is out of range!\n\n");
                i--;
                continue;
            }

            repeated = 0;
            for(int j = 1; j < i; j++){
                if(inputNumber == guesses[j]){
                    printf("ERROR: You can't enter repeated numbers!\n\n");
                    repeated++;
                    break;
                }
            }
            if(repeated){
                i--;
                continue;
            }

            guesses[i] = inputNumber;
            found = (inputNumber == secretNumber);

            if(found || i == totalAttempts){
                break;
            }else if(inputNumber > secretNumber){
                printf("Try a lower number!\n\n");
            }else{
                printf("Try a higher number!\n\n");
            }

            lostPoints = (float) abs(inputNumber - secretNumber) / 2;
            points -= lostPoints;
        }

        if(found){
            printf("\n_________________________________\n");
            printf("    CONGRATULATIONS! YOU WON!    \n");
            printf("         ______________          \n");
            printf("        '._==_==_=_.=_.'         \n");
            printf("        .-\\:         /-.        \n");
            printf("       / /|:.        |\\ \\      \n");
            printf("       \\ \\::.        |/ /      \n");
            printf("        '-|::.       |-'         \n");
            printf("           \\::.     /           \n");
            printf("            ':'   :'             \n");
            printf("              )  (               \n");
            printf("           _.'    '._            \n");
            printf("          '----------'           \n");
            printf("_________________________________\n");
            printf("Total score: %.2f points.\n", points);
        }else{
            printf("\n_________________________________\n");
            printf("            YOU LOST!            \n");
            printf("        ________________         \n");
            printf("      /                 \\       \n"); 
            printf("    /                     \\     \n");
            printf("   |                       |     \n");
            printf("   |     XXXX     XXXX     |     \n");
            printf("    \\|   XXXX     XXXX   |/     \n");
            printf("     \\__       X       __/      \n");
            printf("       |\\     X^X     /|        \n");
            printf("       | |           | |         \n");
            printf("       | I I I I I I I |         \n");
            printf("        \\_           _/         \n");
            printf("         \\___________/          \n");
            printf("_________________________________\n");
            printf("The secret number was %d.\n\n", secretNumber);
        }

        printf(" ______________________________________ \n");
        printf("|                                      |\n");
        printf("|   Do you want to play again? (Y/N)   |\n");
        printf("| _____________________________________|\n");
        printf("|/\n");
        printf("-> Your answer: ");
        scanf(" %c", &reset);
        
        reset = toupper(reset);
        clearScreen();
        if(reset != 'Y') break;
    }

    printf("\nThank you for playing!\n");

    return 0;
}

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}