#include "util.h"

void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #elif __linux__ || __APPLE__
        system("clear");
    #else
        #error "Operational System not supported."
    #endif
}
    
void clearBuffer(){
    while(getchar() != '\n');
}
