/*RUN g++ % -Wall -Wextra -ot && ./t; rm t*/
#include <vector>
#include <cassert>
#include <cstdlib>

using namespace std;

struct union_find {
  vector<int> parent;

  union_find(size_t n) {
    parent.resize(n);
    while (n--) parent[n] = n;
  }

  int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
  }

  void spoji(int x, int y) {
    if (rand() % 2) swap(x, y);
    parent[find(x)] = find(y);
  }

  bool equiv(int x, int y) {
    return find(x) == find(y);
  }
};

int main() {
  union_find uf(5);
  uf.spoji(0, 1);
  assert(uf.equiv(0, 1));
  uf.spoji(0, 1);
  assert(!uf.equiv(0, 2));
  uf.spoji(1, 2);
  assert(uf.equiv(0, 2));
  uf.spoji(3, 4);
  uf.spoji(2, 3);
  for (int i = 0; i < 5; ++i)
    for (int j = 0; j < 5; ++j)
      assert(uf.equiv(i, j));
  return 0;
}
