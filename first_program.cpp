#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int main() {

  cout << "Hello" << endl;

  vector<int> nums = {1, 3, 4, 5, 3, 2, 1, 1};
  for (int num : nums) {
    cout << num << endl;
  }
  return 0;
}
