#include <iostream>

void selection_sort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    int smallest = arr[i];
    int index = i;
    for (int j = i; j < size; j++) {
      if(smallest > arr[j]){
        smallest = arr[j];
        index = j;
      }
    }
      int temp = arr[index];
      arr[index] = arr[i];
      arr[i] = temp;

  }
}

int main() {
  int arr[] = {7, 4, 9, 1, 5, 8, 2, 3, 6};
  int size = 9;

  std::cout << "Before sort: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
    std::cout << "\n";

  selection_sort(arr, size);

  std::cout << "After sort: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  return 0;
}


