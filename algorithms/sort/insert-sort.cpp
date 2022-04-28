#include <iostream>

using namespace std;

int main() {
  int array[7] = { 0, 5, 9, 3, 2, 1, 7 };

  int swap = 0;
  int minElement = 0;
  int minPosition = 0;
  int arrayLength = sizeof(array) / sizeof(array[0]);
  int start = 0;

  while (start != arrayLength) {
    minElement = array[start];
    minPosition = start;

    for (int i = start + 1; i < arrayLength; i++) {
      if (array[i] < minElement) {
        minElement = array[i];
        minPosition = i;
        break;
      }
    }

    if (minPosition != arrayLength) {
      swap = array[start];
      array[start] = minElement;
      array[minPosition] = swap;
    }

    start++;
  }

  for (int i = 0; i < arrayLength; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  return 0;
}
