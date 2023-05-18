#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char input[100];
int position = 0;
bool isValid = true;

void match(char expected) {
  if (input[position] == expected)
    position++;
  else
    isValid = false;
}

void identifier() {
  if (isalpha(input[position])) {
    position++;
    while (isalnum(input[position]))
      position++;
  } else {
    isValid = false;
  }
}

void letterOrDigit() {
  if (isalpha(input[position]) || isdigit(input[position])) {
    position++;
  } else {
    isValid = false;
  }
}

void letter() {
  char letters[] = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 0; i < 26; i++) {
    if (input[position] == letters[i]) {
      position++;
      return;
    }
  }
  isValid = false;
}

void digit() {
  char digits[] = "0123456789";
  for (int i = 0; i < 10; i++) {
    if (input[position] == digits[i]) {
      position++;
      return;
    }
  }
  isValid = false;
}

int main() {
  printf("Enter an identifier to validate: ");
  fgets(input, sizeof(input), stdin);

  // Remove the newline character from input
  input[strlen(input) - 1] = '\0';

  identifier();

  if (input[position] != '\0')
    isValid = false;

  if (isValid)
    printf("Valid identifier!\n");
  else
    printf("Invalid identifier!\n");

  return 0;
}