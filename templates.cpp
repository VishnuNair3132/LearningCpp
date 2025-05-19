#include <cstdint>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

// function template
template <typename T> T returnMax(T x, T y) { return x > y ? x : y; }

static int gobal = 3;
// class template
template <class T> class CustomFunction {
public:
  T getMax(T x, T y) { return x > y ? x : y; }
};

// Template Specialization
template <> class CustomFunction<string> {

public:
  static char getFirstCharacter(string word) { return word[0]; }

public:
  static bool isPalindrome(string word) {
    string str = "";
    int left = 0;
    int right = word.size() - 1;

    while (left != right) {

      if (word.at(left) == word.at(right)) {
        left++;
        right--;
      } else {
        return false;
      }
    }
    return true;
  }
};

template <> class CustomFunction<int> {
public:
  static bool isPalindrome(int number) {
    int reversed = 0;
    int copyNum = number;

    if (copyNum < 0) {
      return false;
    }
    while (copyNum > 0) {
      int a = copyNum % 10;
      reversed = reversed * 10 + a;

      copyNum = copyNum / 10;
    }

    return number == reversed;
  }
};

class Person {

public:
  string Firstname;
  string Lastname;
  string Address;
  int Age;

  Person(string Firstname, string Lastname, string Address, int Age) {
    this->Firstname = Firstname;
    this->Lastname = Lastname;
    this->Address = Address;
    this->Age = Age;
  }

  static void printPerson(Person person) {
    cout << person.Firstname << endl;
    cout << person.Lastname << endl;
    cout << person.Address << endl;
    cout << person.Age << endl;
  }
};

// int a = 0;

int a{};

// ptr = nullptr;
int *ptr{};

// class template
template <class T> class bubbleSort {
public:
  static int compare(T x, T y) {
    if (x > y) {
      return 1;
    } else {
      return -1;
    }
  }

public:
  void sort(T *a, int n, int (*compare)(T, T)) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n - 1; j++) {
        if (compare(a[j], a[j + 1])) {
          T temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
        }
      }
    }
  }
};

int main() {
  /* int max = returnMax<int>(2, 4);

   cout << max << endl;

   Max<int> giveMax;

   int result = giveMax.getMax(9, 2);

   cout << result << endl;
 */

  int a[] = {1, 3, 2, 4, 55, 32, 1, 2};
  char c[] = {'a', 'x', 'b', 'a', 'h', 'q', 't'};

  bubbleSort<int> sortInt;

  bubbleSort<char> sortChar;

  sortInt.sort(a, 8, bubbleSort<int>::compare);

  sortChar.sort(c, 6, bubbleSort<char>::compare);

  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }

  for (int i = 0; i < 8; i++) {
    printf("%c ", a[i]);
  }

  Person p1("Vishnu", "Lastname", "313/2 Sagar Darshan", 22);

  cout << ::a << endl;
  Person::printPerson(p1);
  cout << ::gobal << endl;

  CustomFunction<string> stringFucn;
  string word = "aaabbbaaa";
  bool result = stringFucn.isPalindrome(word);
  cout << "is string a Palindrome: " << result << endl;

  CustomFunction<int> intFucn;
  bool result1 = intFucn.isPalindrome(8854488);
  cout << "is the number a Palindrome: " << result1;
  return 0;
}
