#include <iostream>

void insertion_sort(int *arr, int size) {

  for (int i = 1; i < size; i++) {
    int key = arr[i];
    for (int j = i; j > 0; j--) {
      if (arr[j - 1] > key ) {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        continue;
      }
      break;
    }
  }
}

int main() {
  int arr[] = {7, 4, 9, 1, 5, 8, 2, 3, 6};
  int size = 9;

  std::cout << "before sort: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";

  insertion_sort(arr, size);

  std::cout << "after sort: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}
