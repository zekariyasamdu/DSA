#include <iostream>

void bubble_sort(int *arr, int size) {

  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - i; j++) {
      if ((j + 1 > size - 1))
        break;
      if (arr[j] > arr[j + 1]) {
        int tmp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = tmp;
      }
    }
  }
}

int main() {
  int arr[] = {7, 4, 9, 1, 5, 8, 2, 3, 6};
  int size = 9;

  std::cout << "Before sort: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }

  bubble_sort(arr, size);

  std::cout << "After sort: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}


// Note: Time complexity: Big(n^2)
// Note: Space complexity: Big(1)
