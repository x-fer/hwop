/*RUN g++ % -Wall -Wextra -ot && ./t; rm t*/
#include <iostream>

using namespace std;

int main() {
  /*BEGIN art_epsilon::e1*/
  if (0.7 + 0.2 + 0.1 == 1) {
    cout << "da, naravno!" << endl;
  } else {
    cout << "wait." << endl;
  }
  /*END art_epsilon::e1*/
  return 0;
}
