#include <iostream>
using namespace std;

bool linear_search(int *arr, int val, int size) {
  for (int i = 0; i < size; i++) {
    if (*(arr + i) == val)
      return true;
  }
  return false;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int val = 4;
  bool ans = linear_search(arr, val, 9);
  cout << ans;
  return 0;
}
