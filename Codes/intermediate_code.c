#include <stdio.h>

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  int sum = 0;
  int i = 1;

  loop:
  if (i <= n) {
    sum += i;
    i++;
    goto loop;
  }

  printf("The sum of numbers from 1 to %d is %d\n", n, sum);
  return 0;
}

#include <stdio.h>

int calculateSum(int n);

int main() {
  int n;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  int sum = calculateSum(n);

  printf("The sum of numbers from 1 to %d is %d\n", n, sum);
  return 0;
}

int calculateSum(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i;
  }
  return sum;
}
