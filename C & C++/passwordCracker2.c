#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char answer;
 
void bruteForce(int passwordLength, int charMax, int type1, int type2, int type3) {
    //Only Lowercase letters
    FILE *f;
    char password[passwordLength+1], currentLine[256], emailFound[256], charset[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i, found = 0, charsetLength;
    long int passwordNumber = 0;
    charsetLength = strlen(charset);
    charset[charsetLength] = '\0';
    
    //Type 1: lowercase letters only
    if(type1==1) {
        printf("First password letter: ");
        scanf(" %c", &answer);
        password[0] = answer;
    }
    for(i=1; i<passwordLength; i++)
        password[i] = 'a';
    password[i] = '\0';

    i = passwordLength-1;
    clock_t start = clock();
    while(i>0) {
        printf("%s\n", password); //Comentando para o codigo nao ficar pesado ao verificar as senhas
        f = fopen("passwords.txt", "r");
        while(fgets(currentLine, 256, f)!=NULL) {
            size_t sizeCurrentLine = strlen(currentLine);
            if (sizeCurrentLine > 0 && currentLine[sizeCurrentLine - 1] == '\n') {
                currentLine[sizeCurrentLine - 1] = '\0';
            }
            strcpy(emailFound, currentLine); // Assume que esta linha é o email
            if(fgets(currentLine, 256, f) != NULL) { // Lê a linha seguinte (senha)
                sizeCurrentLine = strlen(currentLine);
                if (sizeCurrentLine > 0 && currentLine[sizeCurrentLine - 1] == '\n') {
                    currentLine[sizeCurrentLine - 1] = '\0';
                }
                if(strcmp(password, currentLine)==0) {
                    found++;
                    printf("Password number %d found:\n", found);
                    printf("%s\n", emailFound);
                    printf("%s\n\n", password);
                }
            }
        }
        fclose(f);
        passwordNumber++;

        if(password[i]!=charset[charsetLength-1]) {
            password[i] = charset[(strchr(charset,password[i])-charset)+1];
            i = passwordLength-1; //Voltando pro ultimo caractere da string password
        }
        else {
            password[i] = charset[0];
            i--;
        }
    }
    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Passwords that starts with '%c': %d\n", answer, found);
    printf("Password attepmts: %ld\n", passwordNumber);
    printf("Elapsed time: %lf s\n", elapsedTime);
}

int main() {
    int charQuantity = 0, maxDig;
    int opt1 = 0, opt2 = 0, opt3 = 0;
    
    printf("----- Password Cracker -----\n\n");
    printf("Password Length: ");
    scanf("%d", &maxDig);
    printf("Lowercase letters? (Y - Yes, N - No): ");
    scanf(" %c", &answer);
    if(answer=='Y' || answer=='y') {
        charQuantity += 26; // a ... z
        opt1 = 1;
    }
    printf("Uppercase letters? (Y - Yes, N - No): ");
    scanf(" %c", &answer);
    if(answer=='Y' || answer=='y') {
        charQuantity += 26; // A ... Z
        opt2 = 1;
    }
    printf("Numbers? (Y - Yes, N - No): ");
    scanf(" %c", &answer);
    if(answer=='Y' || answer=='y') {
        charQuantity += 10; // 0 ... 9
        opt3 = 1;
    }
    bruteForce(maxDig, charQuantity, opt1, opt2, opt3);
    return 0;
}