

#include <iostream>
using namespace std;
int main() {
  int a = 22;
  int b = 11;

  int *ptr1 = &a;
  int *ptr2 = &b;

  int **pptr1 = &ptr1;

  int **pptr2 = &ptr2;

  *pptr1 = *pptr2;
  **pptr2 = 85;

  cout << a << endl;
  cout << b << endl;
  cout << *ptr1 << endl;
  cout << *ptr2 << endl;
  cout << *(*pptr2) << endl;
  cout << *(*pptr2) << endl;
}
