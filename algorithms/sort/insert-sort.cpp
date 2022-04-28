#include <iostream>

using namespace std;

int main() {
  int array[7] = { 0, 5, 9, 3, 2, 1, 7 };
  int arrayLength = sizeof(array) / sizeof(array[0]);
  int swap;
  int item;


  for (int i = 1; i < arrayLength; i++) {
    swap = array[i];

    item = i - 1;

    while (item >= 0 && array[item] > swap) {
      array[item + 1] = array[item];
      array[item] = swap;
      item--;
    }
  }

  for (int i = 0; i < arrayLength; i++) {
    cout << array[i] << " ";
  }

  cout << endl;

  return 0;
}
