#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename Type>
void swap(Type *a, Type *b) {
  Type tmp = *a;
  *a = *b;
  *b = tmp;
}

/**
 * Fill vector
 *
 * @param data vector to fill
 */
template <typename Type>
vector<Type> fill(vector<Type> data) {
  int length, node;

  cout << "Enter count of elements: ";
  cin >> length;

  for (int i = 0; i < length; i++) {
    cout << " > ";
    cin >> node;

    data.push_back(node);
  }

  return data;
}

/**
 * Print the contents of the vector
 *
 * @param data vector to browse
 * @param message before viewing vector
 */
template <typename Type>
void printVector(vector<Type> data, string message = "") {
  // Check if message exists
  if (message.length() != 0) {
    cout << message;
  }

  // Print vector
  for (int i = 0; i < data.size(); i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

/**
 * Bubble sort algorithm
 *
 * @param data vector
 */
template <typename Type>
vector<Type> bubbleSort(vector<Type> data) {
  Type swap;
  int length = data.size();

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (data[i] < data[j]) {
        swap = data[i];
        data[i] = data[j];
        data[j] = swap;
      }
    }
  }

  return data;
}

/**
 * Selection sort algorithm
 *
 * @param data vector
 */
template <typename Type>
vector<Type> selectionSort(vector<Type> data) {
  for (int step = 0; step < data.size() - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < data.size(); i++) {
      if (data[i] < data[min_idx]) {
        min_idx = i;
      }
    }

    swap(&data[min_idx], &data[step]);
  }

  return data;
}

/**
 * Insertion sort algorithm
 *
 * @param data vector
 */
template <typename Type>
vector<Type> insertSort(vector<Type> data) {
  int arrayLength = data.size();
  int swap;
  int item;

  for (int i = 1; i < arrayLength; i++) {
    swap = data[i];

    item = i - 1;

    while (item >= 0 && data[item] > swap) {
      data[item + 1] = data[item];
      data[item] = swap;
      item--;
    }
  }

  return data;
}

int main() {
  vector<int> data;

  // Fill vector
  data = fill(data);

  // Bubble sort
  vector<int> withBubbleSort = bubbleSort(data);
  printVector(withBubbleSort, "\nBubble sort algorithm: \n");

  // Selection sort
  vector<int> withSelectionSort = selectionSort(data);
  printVector(withSelectionSort, "\nSelection sort algorithm: \n");

  // Insertion sort
  vector<int> withInsertSort = insertSort(data);
  printVector(withInsertSort, "\nInsertion sort algorithm: \n");

  return 0;
}
