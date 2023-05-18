 #include <stdio.h>

int maximumreward(int start, int end, int n, int edges[][n], int currentreward) {
  if (start == end) {
    return currentreward;
  }
  
  int maxreward = -1;
  int i;
  for (i = 0; i < n; i++) {
    if (edges[start][i] != -1) {
      int reward = maximumreward(i, end, n, edges, currentreward + edges[start][i]);
      if (reward > maxreward) {
        maxreward = reward;
      }
    }
  }
  
  return maxreward;
}

int main() {
  int n;
  printf("Number of Nodes: ");
  scanf("%d", &n);
  int edges[n][n];
  int i,j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      edges[i][j] = -1;
    }
  }
  
  int noe;
  printf("Number of Edges: ");
  scanf("%d", &noe);
  for (i = 0; i < noe; i++) {
    int start, end, reward;
    scanf("%d", &start);
    scanf("%d", &end);
    scanf("%d", &reward);
    if (start >= 0 && start < n && end >= 0 && end < n) {
      edges[start][end] = reward;
    } else {
      printf("Invalid Edge\n");
      i--;
    }
  }
  
  int start, end;
  while (1) {
    printf("Start Node: ");
    scanf("%d", &start);
    printf("End Node: ");
    scanf("%d", &end);
    if (start >= 0 && start < n && end >= 0 && end < n) {
      break;
    } else {
      printf("Invalid Details\nPlease Enter Again\n");
    }
  }
  
  printf("Maximum Reward: %d\n", maximumreward(start, end, n, edges, 0));
  
  return 0;
}