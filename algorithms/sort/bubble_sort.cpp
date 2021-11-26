#include <iostream>
#define N 20
#define MAX_VALUE 50

using namespace std;

int array[N];

void browse() {
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void fill() {
    srand (time(NULL));

    for (int i = 0; i < N; i++) {
        array[i] = rand() % MAX_VALUE + 1;
    }
}

void bable_sort() {
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

int main() {

    fill();

    browse();

    bable_sort();

    browse();

    return 0;
}
