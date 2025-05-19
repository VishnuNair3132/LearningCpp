#include <iostream>
int binarySearch(int *a, int start, int end, int target) {

  while (start <= end) {
    int mid = start + (end - start) / 2;

    if (a[mid] == target) {
      return mid;
    }

    if (a[mid] < target) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }

  return -1;
}

int main() {

  int a[]{2, 4, 12, 23, 32, 41};

  int result = binarySearch(a, 0, 5, 332);
  if (result != -1) {
    std::cout << "Element Found ";
  } else {
    std::cout << "Element not found";
  }

  return 0;
}
