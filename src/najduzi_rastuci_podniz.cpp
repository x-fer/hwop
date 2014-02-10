/*RUN g++ --std=c++11 % -Wall -Wextra -ot && ./t; rm t*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 100;
const int oo = 0x3f3f3f3f;

int N = 13;
int a[maxn] = {1, 5, 4, 5, 2, 6, 3, 7, 10, 5, 8, 10, oo};

int iterative_lcs() {
  int dp[maxn];

  for (int k = 0; k < N; ++k) {
    dp[k] = 1;
    for (int i = 0; i < k; ++i) {
      if (a[i] >= a[k]) continue;
      dp[k] = max(dp[k], dp[i] + 1);
    }
  }

  return dp[N - 1];
}

int dp[maxn];

int solve(int k) {
  // ako na mjestu dp[k] pise nesto sto nije 0,
  // znaci da smo vec obradili ovaj problem, informaciju
  // za ovo stanje smo upisali upravo na mjesto dp[k]
  // (vidi zadnju liniju u rekurziji)
  if (dp[k] != 0) return dp[k];

  int ret = 1;
  for (int i = 0; i < k; ++i) {
    if (a[i] >= a[k]) continue;
    ret = max(ret, solve(i) + 1);
  }
  return dp[k] = ret;
}

int recursive_lcs() {
  memset(dp, 0, sizeof dp);
  return solve(N - 1);
}

int lcs_with_reconstruct() {
  int dp[maxn], last[maxn];
  bool flag[maxn];

  for (int k = 0; k < N; ++k) {
    dp[k] = 1;
    for (int i = 0; i < k; ++i) {
      if (a[i] >= a[k]) continue;
      if (dp[i] + 1 > dp[k]) {
        last[k] = i;
        dp[k] = dp[i] + 1;
      }
    }
  }

  // oznacimo stranice koje cine rjesenje koje zavrsava
  // na zadnjem elementu (koji smo namjestili da je najveci)
  memset(flag, false, sizeof flag);
  int it = N - 1;
  while (dp[it] != 1) {
    it = last[it];
    flag[it] = true;
  }

  // ispis brojeva na svim oznacenim stranicama
  for (int i = 0; i < N; ++i)
    if (flag[i])
      printf("%d ", a[i]);
  printf("\n");

  return dp[N - 1];
}

int main() {
  printf("%d\n", iterative_lcs());
  printf("%d\n", recursive_lcs());
  printf("%d\n", lcs_with_reconstruct());
  return 0;
}
