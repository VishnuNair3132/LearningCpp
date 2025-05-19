#include <iostream>
#include <vector>
using namespace std;
int main() {

  vector<int> numbers = {1, 3, 4, 22, 4, 3, 1, 4};

  vector<string> name = {"vishnu",  "abhishek", "rohit",   "sharama",
                         "mangesh", "eric",     "ronaldo", "dembele",
                         "pedri",   "whatsUp "};

  vector<int>::iterator it;

  for (it = numbers.begin(); it != numbers.end(); ++it) {
    cout << *it << endl;
  }
  vector<string>::iterator stringIterator;

  for (stringIterator = name.begin(); stringIterator != name.end();
       ++stringIterator) {
    cout << *stringIterator << "\n";
  }

  return 0;
}
