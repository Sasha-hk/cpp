#include <iostream>

using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx]) {
        min_idx = i;
      }
    }

    swap(&array[min_idx], &array[step]);
  }
}

int main() {
  int array[10] = { 93, 82, 3, -10, 0, 1, 23, 12, 9, 50 };
  int arrayLength = sizeof(array) / sizeof(array[0]);

  selectionSort(array, arrayLength);

  for (int i = 0; i < arrayLength; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  return 0;
}
