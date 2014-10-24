#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
using namespace std;
#define D(x) cerr << #x << " = " << x << endl;

const int maxn = 1000;
const int maxk = 1000000;

struct tournament_tree {
  tournament_tree(size_t n) {
    for (offset = 1; offset < n; offset *= 2);
    a.resize(2 * offset);
  }

  void add(int pos, const int &v) {
    pos += offset;
    a[pos] = a[pos] + v;
    for (pos /= 2; pos; pos /= 2)
      a[pos] = a[pos * 2] + a[pos * 2 + 1];
  }

  int query(int qlo, int qhi) const {
    return query(1, 0, offset, qlo, qhi);
  }

 private:
  int query(int v, int lo, int hi, int qlo, int qhi) const {
    if (lo >= qlo && hi <= qhi) return a[v];
    if (lo >= qhi || hi <= qlo) return 0;
    return query(2 * v + 0, lo, (lo + hi) / 2, qlo, qhi) +
           query(2 * v + 1, (lo + hi) / 2, hi, qlo, qhi);
  }

  size_t offset;
  vector<int> a;
};

struct tournament_tree_brute {
  tournament_tree_brute(size_t n) {a.resize(n);}

  void add(int pos, const int &v) {
    a[pos] = a[pos] + v;
  }

  int query(int lo, int hi) const {
    int ret = 0;
    for (int pos = lo; pos < hi; ++pos)
      ret = ret + a[pos];
    return ret;
  }

 private:
  vector<int> a;
};

int random_value() {
  return rand() % (maxk + 1) - maxk / 2;
}

int main() {
  tournament_tree_brute B(maxn);
  tournament_tree S(maxn);

  for (int j = 0; j < 1000; ++j) {
    for (int k = 0; k < 10; ++k) {
      int rnd = random_value();
      int pos = rand() % maxn;
      B.add(pos, rnd);
      S.add(pos, rnd);
    }
    int lo = rand() % maxn;
    int hi = rand() % (maxn + 1);
    assert(
      B.query(min(lo, hi), max(lo, hi)) ==
      S.query(min(lo, hi), max(lo, hi))
    );
  }
  return 0;
}
