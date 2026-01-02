#include <iostream>
using namespace std;

int binary_search(int *arr, int target, int left, int right) {
  if (left > right) {
    return -1;
  }
  int mid = (right + left) / 2;

  if (*(arr + mid) == target) {
    return mid;
  }

  if (arr[mid] > target) {
    return binary_search(arr, target, left, mid - 1);
  } else {
    return binary_search(arr, target, mid + 1, right);
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  int target = 4;
  int left_index = 0;
  int right_index = 8;
  int index = binary_search(arr, target, left_index, right_index);
  cout << index;
  return 0;
}
