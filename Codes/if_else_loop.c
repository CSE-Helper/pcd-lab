#include <stdio.h>

int main() {
  int i;
  for (i = 1; i <= 100; i++) {
    int divisibleBy3 = i % 3 == 0;
    int divisibleBy5 = i % 5 == 0;

    if (divisibleBy3) {
      printf("P");
      if (divisibleBy5)
        printf("R");
    } else if (divisibleBy5) {
      printf("R");
    } else {
      printf("%d", i);
    }
    
    printf("\n");
  }

  return 0;
}