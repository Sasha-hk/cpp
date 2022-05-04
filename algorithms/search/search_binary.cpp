#include <iostream>
#define N 10
#define MAX_VALUE 100

using namespace std;

void fill(int *array) {
  srand (time(NULL));

  for (int i = 0; i < N; i++) {
    array[i] = rand() % MAX_VALUE + 1;
  }
}

void bable_sort(int *array) {
  int swap;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (array[i] < array[j]) {
        swap = array[j];
        array[j] = array[i];
        array[i] = swap;
      }
    }
  }
}

void browse(int *array) {
  for (int i = 0; i < N; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}

int binarySearch(int arr[], int left, int right, int x) {
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (arr[mid] == x) {
      return mid;
    } else if (arr[mid] < x) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return -1;
}

int main() {
  int a[N];

  fill(a);

  bable_sort(a);

  browse(a);

  int res = binarySearch(a, 0, N, 2);

  cout << res << endl;

  if (res) {
      cout << "Not found\n";
  }
  else {
      cout << "Found\n";
  }
}
