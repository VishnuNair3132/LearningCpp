

#include <iostream>
using namespace std;
constexpr int square(int x) { return x * x; }

int main() {

  // this keyword constexpr tell the compiler that the value is known and can be
  // used on compile time to save total runtime.
  //
  constexpr int a = 9;

  constexpr int total = square(9);
  cout << total << endl;

  return 0;
}
