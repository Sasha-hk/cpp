#include <iostream>

using namespace std;

int f(int n) {
  if (n == 0) {
    n = 1;
  }
  else {
    n = f(n-1)*n;
  }

  return n;
}

int fLoop(int n) {
  int factorial = 1;

  for (int i = 2; i < n + 1; i++) {
    factorial = factorial * i;
  }

  return factorial;
}

int main() {
  int n;

  cout << "Enter n: ";
  cin >> n;

  cout << "Recursion: " << f(n) << endl;
  cout << "Loop:      " << fLoop(n) << endl;

  return 0;
}
