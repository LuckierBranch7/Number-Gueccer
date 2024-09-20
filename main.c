#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void space(int amountOfSpaces) {
    for(int i = 1; i <= amountOfSpaces; i++) {
        printf("\n");
    }
}

int randomNumber(int numberLimit) {
    srand(time(0));
    int num = (rand() % numberLimit) + 1;

    return num;
}

void onWin(int winNum, int attempts) {
    space(20);

    printf("----------------------\n");
    printf("        You Win!      \n");
    printf("----------------------\n");

    printf("\nCorrect number: %d\n", winNum);
    printf("Attempts: %d", attempts);
    space(1);
}

void onLose(int winNum) {
    space(20);

    printf("**********************\n");
    printf("      You Lose :(     \n");
    printf("**********************\n");

    printf("\nCorrect number : %d\n", winNum);
    printf("\nBetter luck next time!");
    space(1);
}

int main() {
    int numberLimit;
    int guessedNumber;
    int attempts = 0;
    int overrideLo = 0;
    int overrideHi = 0;
    bool win;

    space(20);

    printf("Before we begin, enter the number limit for gueccer: ");
    scanf("%d", &numberLimit);
    int randNum = randomNumber(numberLimit);

    space(20);

    printf("You have 20 attempts. Good luck!");
    space(2);

    while(attempts <= 20) {
        if(attempts >= 20) {
            win = false;
            break;
        }

        printf("\nGuess a number: ");
        scanf("%d", &guessedNumber);

        attempts += 1;

        if(guessedNumber < 1 || guessedNumber > numberLimit) {
            printf("That's not a valid number. Pick a number between 1-%d.", numberLimit);
        } else if(guessedNumber > randNum) {
            printf("Too high. Try lowering the number.");
            overrideHi += 1;

            if(overrideHi >= numberLimit+5) {
                printf("Kill Switch Activated. Fatal Error!");
                break;
            }
        } else if(guessedNumber < randNum) {
            printf("Too low. Try raising the number.");
            overrideLo += 1;

            if(overrideLo >= numberLimit+5) {
                printf("Kill Switch Activated. Fatal Error!");
                break;
            }
        } else if(guessedNumber == randNum) {
            win = true;
            break;
        } else {
            printf("Fatal error");
            break;
        }
    }

    if(win == true) {
        onWin(randNum, attempts);
    } else if(win == false) {
        onLose(randNum);
    }

    printf("\n");
    return 0;
}