/*Group Name: Code Crafters
Title:Rock,Paper,Scissor
***Project Members***
1. MIRZA SUMAIYA SHAKIL AHMED [ Team Leader ]
2. SHAIKH MISBAH ABDUL SAMAD
3. SHAIKH ZOYA AYUB
4. ANSARI RUHI MOHAMMED ATIQUE*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void getComputerChoice(char *computerChoice) {
    const char *choices[] = {"rock", "paper", "scissors"};
    int randomIndex = rand() % 3;
    strcpy(computerChoice, choices[randomIndex]);
}

const char* determineWinner(const char *choice1, const char *choice2) {
    if (strcmp(choice1, choice2) == 0) {
        return "It's a tie!";
    } else if ((strcmp(choice1, "rock") == 0 && strcmp(choice2, "scissors") == 0) ||
               (strcmp(choice1, "paper") == 0 && strcmp(choice2, "rock") == 0) ||
               (strcmp(choice1, "scissors") == 0 && strcmp(choice2, "paper") == 0)) {
        return "Player 1 wins!";
    } else {
        return "Player 2 wins!";
    }
}

void playAgainstComputer() {
    char playerChoice[10];
    char computerChoice[10];

    printf("Enter your choice (rock, paper, scissors): ");
    scanf("%s", playerChoice);

    while (strcmp(playerChoice, "rock") != 0 && strcmp(playerChoice, "paper") != 0 && strcmp(playerChoice, "scissors") != 0) {
        printf("Invalid choice. Please enter rock, paper, or scissors: ");
        scanf("%s", playerChoice);
    }

    getComputerChoice(computerChoice);
    printf("The computer chose: %s\n", computerChoice);

    const char *result = determineWinner(playerChoice, computerChoice);
    printf("%s\n", result);
}

void playAgainstPlayer() {
    char player1Choice[10], player2Choice[10];

    printf("Player 1, enter your choice (rock, paper, scissors): ");
    scanf("%s", player1Choice);

    while (strcmp(player1Choice, "rock") != 0 && strcmp(player1Choice, "paper") != 0 && strcmp(player1Choice, "scissors") != 0) {
        printf("Invalid choice. Player 1, please enter rock, paper, or scissors: ");
        scanf("%s", player1Choice);
    }

    printf("Player 2, enter your choice (rock, paper, scissors): ");
    scanf("%s", player2Choice);

    while (strcmp(player2Choice, "rock") != 0 && strcmp(player2Choice, "paper") != 0 && strcmp(player2Choice, "scissors") != 0) {
        printf("Invalid choice. Player 2, please enter rock, paper, or scissors: ");
        scanf("%s", player2Choice);
    }

    const char *result = determineWinner(player1Choice, player2Choice);
    printf("%s\n", result);
}

int main() {
    int choice;
    srand(time(NULL)); // Seed for random number generation

    printf("Rock-Paper-Scissors Game\n");
    printf("1. Play against Computer\n");
    printf("2. Play against Player\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playAgainstComputer();
                break;
            case 2:
                playAgainstPlayer();
                break;
            case 3:
                printf("Exiting the game. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}
