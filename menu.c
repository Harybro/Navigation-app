#include <stdio.h>

int menu() {
    int menu;
    printf("Welcome to Navigation!\n"); //menu 
    printf("Menu:\n");
    printf("1: Navigate\n");
    printf("2: add locatoin\n");
    printf("3: add connection\n");
    printf("4: view locations\n");
    printf("5: help\n");
    printf("6: exit\n");
    printf("Choice: ");

    while(1) { //user picks what menu it wants to go to next
        int choice;
        if (scanf("%d",  &choice) != 1) { //checks its a number
            printf("Invalid character! Wrong input enter again: ");

            int c;
            while ((c = getchar()) != '\n' && c != EOF); //clears the invalid characrs from the last input buffer

            continue;
        }
    
        if (choice == 1) {
            menu = 1;
            break;
        } else if (choice == 2) {
            menu = 2;
            break;
        } else if (choice == 3) {
            menu = 3;
            break;
        } else if (choice == 4) {
            menu = 4;
            break;
        } else if (choice == 5) {
            menu = 5;
            break;
        } else if (choice == 6) {
            menu = 6;
            break;
        } else {
            printf("Wrong input enter again: ");
        }

    }

    printf("%d", menu);

    return menu;
}
