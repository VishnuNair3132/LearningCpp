
#include <algorithm>
#include <cassert>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

// there are three ways to do opreator overloading
// 1.Normal function
// 2.Class Member function
// 3.Friend Function
// Remember:
// When dealing with binary operators that do modify the left operand
//(e.g. operator+=), the member function version is typically preferred.
// When dealing with binary operators that don’t modify the left operand
//(e.g. operator+), the normal or friend function version is typically preferred
// If you’re overloading assignment (=), subscript ([]), function call (()),
// or member selection (->), do so as a member function

class Matrix {
private:
  double matrix[4][4]{};

public:
  double &operator()(int row, int col);

  const double &operator()(int row, int col) const;

  void operator()();
};

double &Matrix::operator()(int row, int col) {
  assert(row > 0 && row < 4);
  assert(col > 0 && col < 4);
  return matrix[row][col];
}

const double &Matrix::operator()(int row, int col) const {
  assert(row > 0 && row < 4);
  assert(col > 0 && col < 4);
  return matrix[row][col];
}

void Matrix::operator()() {
  for (int i{}; i < 4; i++) {
    for (int j{}; j < 4; j++) {

      cout << matrix[i][j] << "  ";
    }
    cout << "\n";
  }
}

class Point {
public:
  int x;
  int y;
  int z;

public:
  Point() {};
  Point(int x, int y, int z) : x(x), y(y), z(z) {};

  friend Point operator+(const Point &a, const Point &b);

  friend ostream &operator<<(ostream &out, const Point &point);

  friend bool operator<(const Point &a, const Point &b);

  friend bool operator!=(const Point &a, const Point &b);

  ~Point() { cout << "Destroy Point" << endl; }

  // pre-increment
  Point &operator++() {
    ++y;
    ++x;
    ++z;
    return *this;
  }

  Point &operator++(int) {
    x++;
    y++;
    z++;
    return *this;
  }

  Point operator--(int) {
    x--;
    y--;
    z--;
    return *this;
  }

  Point operator!() {
    x = -x;
    y = -y;
    z = -z;
    return *this;
  }

  Point &operator+() { return *this; }

  operator string() const {
    string result =
        "Point(" + to_string(x) + "," + to_string(y) + "," + to_string(z) + ")";
    return result;
  };
};

ostream &operator<<(ostream &out, const Point &point) {
  out << "Point(" << point.x << "," << point.y << "," << point.z << ")" << endl;
  return out;
}

bool operator<(const Point &a, const Point &b) {
  if (a.x != b.x)
    return a.x < b.x;
  if (a.y != b.y)
    return a.y < b.y;
  return a.z < b.z;
}

bool operator!=(const Point &a, const Point &b) {
  if (a.x != b.x && a.y != b.y && a.z != b.z) {
    return true;
  }
  return false;
}

Point operator+(const Point &a, const Point &b) {
  return Point(b.x + a.x, b.y + a.y, b.z + a.z);
}

void printAll(string str) { cout << str << endl; }
int main() {

  int x = 5;
  int y = -x;
  Point temp(1, 1, 1);
  Point temp2(1, 1, 1);
  Point p1(4, 5, 7);
  Point p2(4, 5, 7);
  Point p3 = p1 + p2;
  bool result = temp < p3;
  cout << p3;
  cout << result << endl;
  bool result3 = temp != temp2;
  bool result2 = temp != p2;
  cout << result2 << endl;
  !p3;
  p3++;
  cout << p3;
  p3--;
  cout << +p3;
  cout << result3 << endl;

  cout << "**********=====**********" << endl;
  printAll(p3);

  Point p4;
  p4 = p3;

  cout << p4 << endl;

  /*
    vector<Point> points = {p1, p2, p3, temp, temp2};

    sort(points.begin(), points.end());

    for (auto &point : points) {
      cout << point << " " << endl;
    }
  */
  cout << "**********=====**********" << endl;

  int a = 10;
  cout << a << endl;
  cout << a++ << endl;
  cout << a << endl;
  cout << ++a << endl;
  cout << a << endl;

  cout << "**********=====**********" << endl;

  Matrix m1{};
  m1(1, 1) = 45.3;

  m1();

  return 0;
}
