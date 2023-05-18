#include <stdio.h>

int accept(int state, int end, int n , char transition[][n], char input[]) {
  if (input[0] == '\0') {
    if (state == end) {
      return 1; // Accept the input if current state is the final state and input is empty
    } else {
      return 0; // Reject the input otherwise
    }
  }
  
  int i = 0;
  while (transition[state][i] != '-1' && i<n) {
    if (transition[state][i] == input[0]) {
      if (accept(i, end, n , transition, input + 1) == 1) {
        return 1; // Accept the input if the remaining input is accepted by the next state
      }
    }
    i++;
  }
  
  return 0; // Reject the input if no valid transition is found for the current state and input symbol
}

int main() {
  int n;
  printf("Number of States: ");
  scanf("%d", &n);
  char transition[n][n];
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      transition[i][j] = '-1';
    }
  }
  
  int noe;
  printf("Number of transitions: ");
  scanf("%d", &noe);
  for (i = 0; i < noe; i++) {
    int start, end;
    char symbol;
    scanf("%d", &start);
    scanf("%d", &end);
    scanf(" %c", &symbol); // Read a single character for the transition symbol
    if (start >= 0 && start < n && end >= 0 && end < n) {
      transition[start][end] = symbol;
    } else {
      printf("Invalid Transition\n");
      i--;
    }
  }
  
  int start, end;
  while (1) {
    printf("Start state: ");
    scanf("%d", &start);
    printf("Final State: ");
    scanf("%d", &end);
    if (start >= 0 && start < n && end >= 0 && end < n) {
      break;
    } else {
      printf("Invalid Selection\nPlease Enter Again\n");
    }
  }
  
  char input[20];
  printf("Input string: ");
  scanf("%s", input);
  
  if (accept(start, end, n , transition, input) == 1) {
    printf("Accepted\n");
  } else {
    printf("Rejected\n");
  }
  
  return 0;
}