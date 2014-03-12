#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long llint;

struct bignum {
  bignum(llint k) : a(1, k) {norm();}

  void out() const {
    printf("%lld", a.back());
    for (int it = a.size() - 2; it >= 0; --it)
      printf("%07lld", a[it]);
    printf("\n");
  }

  bignum& norm() {
    while (!a.back()) a.pop_back();
    llint residue = 0;
    for (size_t it = 0; it < a.size(); ++it) {
      a[it] += residue;
      residue = a[it] / B, a[it] = a[it] % B;
      if (residue && it + 1 == a.size())
        a.push_back(0);
    }
    return *this;
  }

  bignum operator+ (const bignum &rhs) const {
    int size = max(a.size(), rhs.a.size());
    bignum sol(0, size);
    for (size_t it = 0; it < size; ++it)
      sol.a[it] = (*this)[it] + rhs[it];
    return sol.norm();
  }

  bignum operator* (const bignum &rhs) const {
    bignum sol(0, a.size() + rhs.a.size());
    for (size_t it1 = 0; it1 < a.size(); ++it1)
      for (size_t it2 = 0; it2 < rhs.a.size(); ++it2)
        sol.a[it1 + it2] += (*this)[it1] * rhs[it2];
    return sol.norm();
  }

 private:
  static const llint B;
  vector<llint> a;

  bignum(llint k, size_t size) : a(size, k) {}

  llint operator[] (const int index) const {
    return index < a.size() ? a[index] : 0;
  }
};

const llint bignum::B = 10000000;

int main() {
  bignum dva(2);
  for (int i = 0; i < 10; ++i) {
    dva = dva * dva;
  }
  dva.out();
  return 0;
}
