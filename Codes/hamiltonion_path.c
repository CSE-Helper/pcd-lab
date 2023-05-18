#include <stdio.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int num_vertices;

void print_cycle(int path[]) {
  printf("Hamiltonian cycle: ");
  for (int i = 0; i < num_vertices; i++) {
    printf("%d ", path[i]);
  }
  printf("%d\n", path[0]);
}

int hamiltonian_cycle(int path[], int pos) {
  if (pos == num_vertices) {
    if (graph[path[pos-1]][path[0]]) {
      print_cycle(path);
      return 1;
    }
    else {
      return 0;
    }
  }
  for (int v = 1; v < num_vertices; v++) {
    if (!visited[v] && graph[path[pos-1]][v]) {
      visited[v] = 1;
      path[pos] = v;
      if (hamiltonian_cycle(path, pos+1)) {
        return 1;
      }
      visited[v] = 0;
    }
  }
  return 0;
}

int main() {
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);
  printf("Enter the adjacency matrix:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      scanf("%d", &graph[i][j]);
    }
  }
  int path[MAX_VERTICES];
  path[0] = 0;
  visited[0] = 1;
  if (!hamiltonian_cycle(path, 1)) {
    printf("No Hamiltonian cycle exists.\n");
  }
  return 0;
}