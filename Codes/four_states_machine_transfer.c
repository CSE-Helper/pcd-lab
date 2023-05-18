#include <stdio.h>

int nextState(int currentState, char symbol) {
    if (symbol == '0') {
        if (currentState == 0 || currentState == 1)
            return 0;
        else if (currentState == 2)
            return 3;
    } else if (symbol == '1') {
        if (currentState == 0)
            return 1;
        else if (currentState == 1)
            return 2;
        else if (currentState == 2)
            return 3;
    }
    
    return -1; // Invalid symbol or state
}

int main() {
    int currentState = 0;
    char input[100];

    printf("Enter a string of 0s and 1s: ");
    scanf("%s", input);

    int i = 0;
    while (input[i] != '\0') {
        currentState = nextState(currentState, input[i]);
        i++;
    }

    if (currentState == 3)
        printf("Accepted.\n");
    else
        printf("Rejected.\n");

    return 0;
}
