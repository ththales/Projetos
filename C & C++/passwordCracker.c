#include <stdio.h>
 
char answer;
 
void bruteForce(int passwordLength, int charType, int type1, int type2, int type3) {
    //Only Lowercase letters
    char password[passwordLength+1], lowercaseLetters[27];
    int i, finished = 0;
    
    //All Lowercase letters
    lowercaseLetters[0] = 'a';
    for(i=1; i<26; i++) {
        lowercaseLetters[i] = lowercaseLetters[i-1]+1;
    }
    lowercaseLetters[i] = '\0';

    //1st password char
    if(type1==1) {
        //printf("First password letter: ");
        //scanf(" %c", &answer);
        password[0] = 'a';
    }
    for(i=1; i<passwordLength; i++)
        password[i] = 'a';
    password[i] = '\0';

    i = passwordLength-1;

    while(i>0) {
        printf("%s\n", password);
        if(password[i]<'z') {
            password[i]++;
            i = passwordLength - 1;
        }
        else {
            password[i] = 'a';
            i--;
        }
    }

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