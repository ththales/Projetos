#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

void mainMenu();

void charTypeInclude(char *charType, int currentType, int *charTypeSize) {
    //Variable declaration
    char *types[4] = {"abcdefghijklmnopqrstuvwxyz\0", "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0", "0123456789\0", "!?@#$%^&*().;:'\"`[]{}<>+-/=~_|\\\0"};

    if(strcmp(charType, "NULL")==0) {
        strcpy(charType, types[currentType]);
    }
    else {
        strcat(charType, types[currentType]);
    }
        *charTypeSize += strlen(types[currentType]);
}

void searchPasswords() {
    system("cls");

    FILE *passwordsList;
    char currentChar;

    printf("----- Passwords found -----\n\n");
    passwordsList = fopen("passwords.txt", "r");
    if(passwordsList==NULL) {
        printf("File opening error: Empty file\n\n");
        printf("Press any key to continue: ");
        getch();
        mainMenu();
        exit(1);
    }
    while((currentChar = fgetc(passwordsList))!=EOF) {
        if(currentChar!='\n') {
            printf("%c", currentChar);
        }
        else {
            printf("\n");
        }
    }
    fclose(passwordsList);
    printf("Press any key to return: ");
    getch();
    mainMenu();
}

void generatePassword() {
    system("cls");

    //Variable declaration
    FILE *passwordsList;
    char *options[4] = {"Lowercase Letters? (1-YES, 2-NO): \0", "Uppercase Letters? (1-YES, 2-NO): \0", "Numbers? (1-YES, 2-NO): \0", "Special Characters? (1-YES, 2-NO): \0"};
    char charType[94] = "NULL"; //+1 to the '\0' char, starting null
    int passwordsNumber, passwordLength;
    int charTypeSize = 0, choose, currentChar;

    printf("----- Password Configuration -----\n\n");

    printf("Select the number of passwords: ");
    scanf("%d", &passwordsNumber);
    while(passwordsNumber<=0) {
        printf("Invalid number! Try again: ");
        scanf("%d", &passwordsNumber);
    }

    printf("Select the password length: ");
    scanf("%d", &passwordLength);
    while(passwordLength<=0) {
        printf("Invalid number! Try again: ");
        scanf("%d", &passwordLength);
    }

    for(int i=0; i<4; i++) {
        printf("%s", options[i]);
        scanf("%d", &choose);
        while(choose<1 || choose>2) {
            printf("Invalid number! Try again: ");
            scanf("%d", &choose);
        }
        if(choose==1) {
            charTypeInclude(charType, i, &charTypeSize);
        }
    }
    charType[94] = '\0';

    printf("\nPassword Characters type: %s\n", charType);
    printf("Characters type size: %d\n\n", charTypeSize);

    if(strcmp(charType, "NULL")!=0) {
        printf("Passwords List:\n");
        passwordsList = fopen("passwords.txt", "a");
        fputs("Passwords List:\n", passwordsList);
        for(int i=0; i<passwordsNumber; i++) {
            for(int j=0; j<passwordLength; j++) {
                currentChar = (rand()%charTypeSize);
                printf("%c", charType[currentChar]);
                fputc(charType[currentChar], passwordsList);
            }
            printf("\n");
            fputc('\n', passwordsList);
        }
        fputc('\n', passwordsList);
        fclose(passwordsList);
    }
    else {
        printf("No password has been generated!\n");
    }
    printf("\nPress any key to return: ");
    getch();
    mainMenu();
}

void mainMenu() {
    system("cls");

    int choose;

    printf("----- Password Generator -----\n\n");
    printf("1 - Generate Passwords\n");
    printf("2 - Your passwords\n");
    printf("3 - Exit\n\n");
    printf("------------------------------\n\n");

    printf("Select a option: ");
    scanf("%d", &choose);
    while(choose<1 || choose>3) {
        printf("Invalid option, try again: ");
        scanf("%d", &choose);
    }

    if(choose==1) {
        generatePassword();
    }
    else {
        if(choose==2) {
            searchPasswords();
        }
    }
}

int main() {
    srand(time(NULL)); //Randomizing the seed

    system("color A"); //Terminal green color
    
    mainMenu();

    system("PAUSE");
    return 0;
}