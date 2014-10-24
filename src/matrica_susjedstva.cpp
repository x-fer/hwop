/*RUN g++ % -Wall -Wextra -ot && ./t < tp/{%/cpp/in}; rm t*/
#include <cstring>
#include <cstdio>

const int maxn = 100;

int org[maxn][maxn];

/*BEGIN matrica_susjedstva::e1*/
int N, graph[maxn][maxn];

void load() {
  int m, a, b;
  scanf("%d%d", &N, &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    --a; --b;
    graph[a][b] = graph[b][a] = 1;
  }
}
/*END matrica_susjedstva::e1*/

void output_dot() {
  printf("graph {\n  rankdir=LR;\n  node[shape=circle];\n");
  for (int i = 0; i < N; ++i) {
    for (int j = i + 1; j < N; ++j) {
      if (graph[i][j])
        printf("  %d -- %d;\n", i + 1, j + 1);
    }
  }
  printf("}\n");
}

void output_tex() {
  printf("$$\nA = \\begin{bmatrix}\n");
  for (int i = 0; i < N; ++i) {
    printf("  ");
    for (int j = 0; j < N; ++j) {
      printf("%d %s", graph[i][j], (j < N-1 ? "& " : ""));
    }
    printf("\\\\\n");
  }
  printf("\\end{bmatrix}\n$$\n");
}

void pomnozi() {
  int tmp[maxn][maxn];
  memset(tmp, 0, sizeof tmp);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        tmp[i][j] += (graph[i][k] * org[k][j]);
      }
    }
  }
  memcpy(graph, tmp, sizeof graph);
}

int main() {
  load();
  memcpy(org, graph, sizeof graph);

  output_dot();
  output_tex();
  pomnozi();
  output_tex();
  pomnozi();
  output_tex();
  return 0;
}
