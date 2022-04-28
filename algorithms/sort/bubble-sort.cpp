#include <iostream>

using namespace std;

int main() {
  int arr[7] = {0, 5, 1, 2, 9, 6, 3};
  int arrLen = sizeof(arr) / sizeof(arr[0]);

  int swap = 0;

  for (int i = 0; i < arrLen; i++) {
    for (int j = 0; j < arrLen; j++) {
      if (arr[i] < arr[j]) {
        swap = arr[j];
        arr[j] = arr[i];
        arr[i] = swap;
      }
    }
  }

  for (int i = 0; i < arrLen; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  return 0;
}
