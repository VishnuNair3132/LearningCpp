
#include <iostream>
using namespace std;
void reverseArr(int *a, int size) {
  for (int i = 0; i < size / 2; i++) {
    int temp = *(a + i);
    *(a + i) = *(a + size - 1 - i);
    *(a + size - 1 - i) = temp;
  }
}

class Person {
public:
  string firstname;
  string lastname;
  int age;
  Person(string firstname, string lastname, int age)
      : firstname(firstname), lastname(lastname), age(age) {};
};

class Point {
public:
  int x;
  int y;
  Point(int x, int y) : x(x), y(y) {};

  // Operator Overloading
  Point operator+(const Point &p) { return Point(x + p.x, y + p.y); }
};

int main() {
  int a[] = {2, 44, 1, 56, 4, 99};

  reverseArr(a, 6);

  for (int i = 0; i < 6; i++) {
    cout << a[i] << " ";
  }
  cout << " \n";
  Point p1(4, 5);
  Point p2(4, 5);
  Point p3(4, 5);
  Point result = p1 + p2 + p3;

  std::cout << result.x << " " << result.y;

  return 0;
}
