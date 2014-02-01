/*RUN gcc % -Wall -Wextra -ot && ./t; rm t*/
#include <stdio.h>

int main() {
  /*BEGIN art_epsilon::e2*/
  union broj {
    long unsigned int ll;
    double lf;
  } A, B;

  A.lf = 1;
  B.lf = 0.7 + 0.2 + 0.1;

  printf("%lx %.20lf\n", A.ll, A.lf);
  // ispisuje 3ff0000000000000 1.00000000000000000000

  printf("%lx %.20lf\n", B.ll, B.lf);
  // ispisuje 3fefffffffffffff 0.99999999999999988898
  /*END art_epsilon::e2*/
  return 0;
}
