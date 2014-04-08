/*RUN g++ % -Wall -Wextra -Wno-unused-value -ot && ./t; rm t*/
#include <cstdio>
#include <cassert>
#include <algorithm>

void traverse(int lo, int hi) {
  for (int it = lo; it < hi; ++it);
}

bool nonempty(int lo, int hi) {
  return lo < hi;
}

int count(int lo, int hi) {
  return nonempty(lo, hi) ? hi - lo : 0;
}

bool intersects(int lo1, int hi1, int lo2, int hi2) {
  return nonempty(std::max(lo1, lo2), std::min(hi1, hi2));
}

bool contains(int lo, int hi, int x) {
  return x >= lo && x < hi;
}

bool contains(int lo1, int hi1, int lo2, int hi2) {
  return lo2 >= lo1 && hi2 <= hi1;
}

// rezultantni intervali su disjunktni, odnosno nemaju presjek
// ukoliko je count(lo, hi) paran broj, tada oba intervala imaju jednaku velicinu.
// u suprotnom prvi interval sadrzi jedan broj manje.
// int mid = (lo + hi) / 2 je ekvivalentno, osim sto ima opasnost od overflow-a
void split(int lo, int hi) {
  int mid = lo + (hi - lo) / 2;
  (lo, mid);
  (mid, hi);
}

bool empty(int lo, int hi) {
  return !nonempty(lo, hi);
}

void test(int lo, int hi) {
  int size = 0;
  for (int x = lo; x < hi; ++x) {
    assert(contains(lo, hi, x));
    assert(!intersects(lo, x, x, hi));
    assert(count(lo, x) + count(x, hi) == count(lo, hi));
    ++size;
  }
  assert((size == 0) == empty(lo, hi));
  assert(size == count(lo, hi));
  assert((size > 0) == nonempty(lo, hi));
  int mid = lo + (hi - lo) / 2;
  if (size == 0) {
    assert(!intersects(lo, hi, lo, hi));
    assert(empty(lo, mid));
    assert(empty(mid, hi));
    return;
  }
  if (size % 2 == 0) {
    assert(count(lo, mid) == count(mid, hi));
    assert(count(lo, mid) == size / 2);
  } else {
    assert(count(lo, mid) + 1 == count(mid, hi));
    assert(count(lo, mid) == size / 2);
  }
  assert(!intersects(lo, mid, mid, hi));
  assert(contains(lo, hi, lo, mid));
  assert(contains(lo, hi, mid, hi));
}

int main() {
  test(2, 6);
  test(2, 8);
  test(2, 2);
  test(2, 1);
  test(-2, 1);
  test(-2, -8);
  return 0;
}
