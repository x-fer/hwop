// task http://www.spoj.com/MINMOVE/

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned long long llint;

const int maxn = 200002;
const llint prim = 3133;

int N;
char a[maxn];
llint p[maxn], s[maxn];

void load() {
  scanf("%s", a);
  N = strlen(a);
  memcpy(a + N, a, N);
  N *= 2;
}

void init() {
  p[0] = 1;
  for (int j = 1; j < N; ++j)
    p[j] = p[j - 1] * prim;
  s[0] = 0;
  for (int j = 1; j <= N; ++j)
    s[j] = s[j - 1] * prim + a[j - 1];
}

llint hash(int lo, int hi) {
  return s[hi] - s[lo] * p[hi - lo];
}

bool eq(int lo1, int hi1, int lo2, int hi2) {
  return hash(lo1, hi1) == hash(lo2, hi2);
}

int lcp(int lo1, int hi1, int lo2, int hi2) {
  int lo = 0, hi = std::min(hi2 - lo2, hi1 - lo1) + 1;
  while (lo != hi) {
    int mid = lo + (hi - lo) / 2;
    if (!eq(lo1, lo1 + mid, lo2, lo2 + mid)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo - 1;
}

bool lt(int lo1, int hi1, int lo2, int hi2) {
  int L = lcp(lo1, hi1, lo2, hi2);
  int len1 = hi1 - lo1, len2 = hi2 - lo2;
  if (L == len1 && L == len2) return 0;
  if (L == len1 || L == len2) return len1 < len2;
  return a[lo1 + L] < a[lo2 + L];
}

int solve() {
  int sol = -1, n = N / 2;
  for (int i = 0; i < n; ++i)
    if (sol == -1 || lt(i, i + n, sol, sol + n))
      sol = i;
  return sol;
}

int main() {
  load();
  init();
  printf("%d\n", solve());
  return 0;
}
