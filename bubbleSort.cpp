#include <cstdlib>
#include <iostream>
using namespace std;
int comparePointer(int a, int b) {
  if (a > b) {
    return 1;
  } else {
    return -1;
  }
}

int compare(const void *a, const void *b) {
  char A = *((char *)a);
  char B = *((char *)b);

  return B - A;
};
void bubbleSort(int *a, int n, int (*compare)(int, int)) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      if (compare(a[j], a[j + 1]) > 0) {
        int temp = a[j];
        a[j] = a[j + 1];
        a[j + 1] = temp;
      }
    }
  }
}

int main() {
  int a[] = {3, 55, 4, 3};
  bubbleSort(a, 4, comparePointer);
  for (int i = 0; i < 4; i++) {
    cout << a[i] << " ";
  }
  char c[] = {'a', 'c', 'x', 'q', 'a'};

  qsort(c, 5, sizeof(char), compare);
  for (int i = 0; i < 6; i++) {
    cout << c[i] << " ";
  }
}
