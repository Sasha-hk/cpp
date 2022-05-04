#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  Stack<int> st = Stack<int>();

  st.push(256);
  st.push(512);

  cout << "Pop 1: " << st.pop() << endl;
  cout << "Pop 2: " << st.pop() << endl;

  return 0;
}
