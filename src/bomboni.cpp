#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 100;

int N = 4, M = 6;
int a[maxn][maxn] = {
  { 0 , 0 , 2 , 3 , 1 , 0 },
  { 1 , 0 , 0 , 4 , 2 , 2 },
  { 1 , 0 , 0 , 0 , 1 , 1 },
  { 1 , 0 , 0 , 0 , 1 , 0 }
};

const int oo = 0x3f3f3f3f;
int dp[maxn][maxn];

int solve(int r, int s) {
  if (r < 0 || s < 0) return -oo;
  if (!r && !s) return a[r][s];
  if (dp[r][s] != oo) return dp[r][s];

  int ret = a[r][s];
  ret += std::max(solve(r-1, s), solve(r, s-1));
  return dp[r][s] = ret;
}

int recursive_dp() {
  memset(dp, oo, sizeof dp);
  return solve(N - 1, M - 1);
}

int iterative_dp() {
  dp[0][0] = a[0][0];
  for (int i = 1; i < N; ++i)
    dp[i][0] = a[i][0] + dp[i-1][0];
  for (int j = 1; j < M; ++j)
    dp[0][j] = a[0][j] + dp[0][j-1];

  for (int i = 1; i < N; ++i) {
    for (int j = 1; j < M; ++j) {
      dp[i][j] = a[i][j];
      dp[i][j] += std::max(dp[i-1][j], dp[i][j-1]);
    }
  }
  return dp[N-1][M-1];
}


int main() {
  printf("%d\n", recursive_dp());
  printf("%d\n", iterative_dp());
  return 0;
}
