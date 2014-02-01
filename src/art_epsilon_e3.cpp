/*RUN g++ --std=c++11 % -Wall -Wextra -ot && ./t; rm t*/
#include <vector>
#include <cstdio>
#include <cassert>
using namespace std;

/*BEGIN art_epsilon::e3*/
typedef double lf;

const lf EPSILON = 1e-12;

inline bool lt(const lf& a, const lf& b) { return b - a > EPSILON; }

inline bool gt(const lf& a, const lf& b) { return lt(b, a); }
inline bool eq(const lf& a, const lf& b) { return !lt(a, b) && !lt(b, a); }
inline bool le(const lf& a, const lf& b) { return !gt(a, b); }
inline bool ge(const lf& a, const lf& b) { return !lt(a, b); }
/*END art_epsilon::e3*/

int main() {
  vector< vector<double> > v{
    {-5, -10/2, -4.5 - 0.5},
    {-1},
    {0,-0.5+0.5,0.5-0.5,0.7-7*0.1},
    {1, 0.9+0.1, 0.1*10, 0.7+0.2+0.1},
    {5, 10/2, 4.5 + 0.5,},
  };

  for (size_t j = 0; j < v.size(); ++j) {
    for (size_t k = 0; k < j; ++k)
      for (auto b : v[k])
        for (auto c : v[j])
          assert(lt(b, c));
    for (size_t k = j; k < v.size(); ++k)
      for (auto b : v[k])
        for (auto c : v[j])
          assert(!lt(b, c));
  }

  printf("lt seems correct!\n");
  return 0;
}
