#include "output.h"

void showMenuDifficulty(){
    printf("\n __________________________________________ \n");
    printf("|                                          |\n");
    printf("|        Select the game difficulty        |\n");
    printf("|   (1) Easy     (2) Normal     (3) Hard   |\n");
    printf("| _________________________________________|\n");
    printf("|/\n");
}

void showVictoryMessage(){
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
}

void showDefeatMessage(){
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
}

void showRestartMessage(){
    printf("\n ______________________________________ \n");
    printf("|                                      |\n");
    printf("|   Do you want to play again? (Y/N)   |\n");
    printf("| _____________________________________|\n");
    printf("|/\n");
}
