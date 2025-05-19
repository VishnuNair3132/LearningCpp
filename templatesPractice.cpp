
#include <iostream>
#include <string>
using namespace std;

// Specilized class in  Templates
template <typename T, int size> class CreateArr {
private:
  T arr[size];

public:
  T *getArray() { return arr; }

  const T &operator[](int index) const { return arr[index]; }

  T &operator[](int index) { return arr[index]; }

  void print() {
    for (int count{0}; count < size; count++) {
      cout << arr[count] << endl;
    }
  }
};

/*template fucntion
template <typename T, int size> void print(CreateArr<T, size> &Array) {
  for (int count{0}; count < size; count++) {
    cout << Array[count] << endl;
  }
}
*/
/// Partialy Specilized class in Templates

template <int size> class CreateArr<char, size> {
private:
  char arr[size];

public:
  char *getArray() { return arr; }

  const char &operator[](int index) const { return arr[index]; }

  char &operator[](int index) { return arr[index]; }

  void print() {
    for (int count{0}; count < size; count++) {
      cout << arr[count] << "_";
    }
  }
};
// C++ does not allow partial specialization of function templates directly.
// But you can achieve the same result using overloading

template <typename T> void printF(T *ptr) {
  T a = *ptr;
  cout << a << "++" << endl;
};

void printF(char *charPtr) {
  char a = *charPtr;
  cout << a << "--" << endl;
}

int main() {
  CreateArr<int, 5> int5;
  int5[0] = 1;
  int5[1] = 2;
  int5[2] = 3;
  int5[3] = 4;
  int5[4] = 5;

  CreateArr<char, 5> char5;
  char5[0] = 'a';
  char5[1] = 'b';
  char5[2] = 'c';
  char5[3] = 'd';
  char5[4] = 'e';

  int5.print();
  char5.print();

  int a = 1;
  char b = 'a';

  printF(&a);
  printF(&b);

  return 0;
}
