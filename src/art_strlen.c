#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const size_t n = 100000;

int main() {
  int cnt = 0, i;
  char *t = malloc(n), *it;
  memset(t, 'o', n - 1);
  t[n-1] = '\0';

  for (i = 0; i < strlen(t); ++i)
    cnt += (*it == 'o');

  cnt = 0;
  for (it = t; *it; ++it)
    cnt += (*it == 'o');

  printf("%d\n", cnt);
  return 0;
}

