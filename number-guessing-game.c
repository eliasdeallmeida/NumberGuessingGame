#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define EASY_MODE 12
#define NORMAL_MODE 8
#define HARD_MODE 5

#define NONE "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"

int main(void){
    int difficulty, totalAttempts, secretNumber, inputNumber;
    int found = 0, min = 1, max = 100;
    float lostPoints;
    char reset;

    for(int i = 0; i < 3; i++){
        system("cls");
        for(int j = 0; j < 3; j++){
            printf(" . ");
            fflush(stdout);
            Sleep(200);
        }
    }

    system("cls");
    printf("\n%s", COLOR_BLUE);
    printf("  _   _                 _                  _____                     _                _____                       \n");
    printf(" | \\ | |               | |                / ____|                   (_)              / ____|                      \n");
    printf(" |  \\| |_   _ _ __ ___ | |__   ___ _ __  | |  __ _   _  ___  ___ ___ _ _ __   __ _  | |  __  __ _ _ __ ___   ___  \n");
    printf(" | . ` | | | | '_ ` _ \\| '_ \\ / _ \\ '__| | | |_ | | | |/ _ \\/ __/ __| | '_ \\ / _` | | | |_ |/ _` | '_ ` _ \\ / _ \\ \n");
    printf(" | |\\  | |_| | | | | | | |_) |  __/ |    | |__| | |_| |  __/\\__ \\__ \\ | | | | (_| | | |__| | (_| | | | | | |  __/ \n");
    printf(" |_| \\_|\\__,_|_| |_| |_|_.__/ \\___|_|     \\_____|\\__,_|\\___||___/___/_|_| |_|\\__, |  \\_____|\\__,_|_| |_| |_|\\___| \n");
    printf("                                                                              __/ |                               \n");
    printf("                                                                             |___/                                \n");
    printf("%s", NONE);

    sleep(1);
    printf("\nWelcome! In this game you will need to find a randomly drawn number in the range from %d to %d. But calm down... You have a different amount of attempts for each difficulty. Therefore, the harder the game mode, the fewer attempts you will have. If you can get it right, I'll reveal your score. Are you able to find out the secret number?", min, max);

    while(1){
        sleep(1);
        printf("\n%s", COLOR_BLUE);
        printf(" ______________________________________________ \n");
        printf("|                                              |\n");
        printf("|          Select the game difficulty          |\n");
        printf("|    (1) Easy      (2) Normal      (3) Hard    |\n");
        printf("| _____________________________________________|\n");
        printf("|/%s\n", NONE);
        printf("-> Your choice: ");
        scanf("%d", &difficulty);

        switch(difficulty){
            case 1: totalAttempts = EASY_MODE; printf("%sEasy mode selected%s\n\n", COLOR_GREEN, NONE); break;
            case 2: totalAttempts = NORMAL_MODE; printf("%sNormal mode selected%s\n\n", COLOR_YELLOW, NONE); break;
            default: totalAttempts = HARD_MODE; printf("%sHard mode selected%s\n\n", COLOR_RED, NONE);
        }

        Sleep(500);
        printf("You have %d attempts to find the secret number in the range from %d to %d", totalAttempts, min, max);

        char message[12] = "\nGood luck!";
        for(int i = 0; i < strlen(message); i++){
            Sleep(100);
            printf("%s%c%s", COLOR_GREEN, message[i], NONE);
            fflush(stdout);
        }

        srand(time(NULL));
        secretNumber = (rand() % max) + min;

        int guesses[totalAttempts];
        float points = 100;

        for(int i = 1; i <= totalAttempts; i++){
            sleep(1);
            printf("\n\n");
            printf("%s=== Attempt %d of %d ===%s\n", COLOR_BLUE, i, totalAttempts, NONE);
            printf("-> Your guess: ");
            scanf("%d", &inputNumber);
            
            if(inputNumber < min || inputNumber > max){
                printf("%s* ERROR! | Input number is out of range! *%s", COLOR_RED, NONE);
                i--;
                continue;
            }

            int repeated = 0;
            for(int j = 1; j < i; j++){
                if(inputNumber == guesses[j]){
                    printf("%s* ERROR! You can't enter repeated numbers! *%s", COLOR_RED, NONE);
                    repeated = 1;
                    break;
                }
            }
            if(repeated != 0){
                i--;
                continue;
            }

            guesses[i] = inputNumber;
            found = inputNumber == secretNumber;

            if(found || i == totalAttempts){
                break;
            }else if(inputNumber > secretNumber){
                printf("%sTry a lower number!%s", COLOR_YELLOW, NONE);
            }else{
                printf("%sTry a higher number!%s", COLOR_YELLOW, NONE);
            }

            lostPoints = abs(inputNumber - secretNumber) / 2.0;
            points = points - lostPoints;
        }

        if(found){
            Sleep(500);
            printf("\n%s_________________________________\n", COLOR_GREEN);
            printf("    CONGRATULATIONS! YOU WON!    \n");
            printf("%s         ______________          \n", COLOR_YELLOW);
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
            printf("%s_________________________________%s\n", COLOR_GREEN, NONE);
            printf("Total score: %.2f points.", points);
        }else{
            Sleep(500);
            printf("\n%s_________________________________\n", COLOR_RED);
            printf("            YOU LOST!            \n");
            printf("%s        ________________         \n", NONE);
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
            printf("%s_________________________________%s\n", COLOR_RED, NONE);
            printf("The secret number was %d.", secretNumber);
        }

        sleep(1);
        printf("\n\n%s", COLOR_BLUE);
        printf(" ________________________________________ \n");
        printf("|                                        |\n");
        printf("|    Do you want to play again? (Y/N)    |\n");
        printf("| _______________________________________|\n");
        printf("|/%s\n", NONE);
        printf("-> Your answer: ");
        scanf(" %c", &reset);
        
        reset = toupper(reset);
        system("cls");
        if(reset != 'Y'){
            break;
        }
    }

    char message[25] = "Thank you for playing!";
    for(int i = 0; i < strlen(message); i++){
        printf("%s%c%s", COLOR_GREEN, message[i], NONE);
        fflush(stdout);
        Sleep(150);
    }
    printf("\n");
    system("pause");
    return 0;
}