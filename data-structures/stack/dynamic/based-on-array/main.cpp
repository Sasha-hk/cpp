#include "stack.cpp"
#include <iostream>

using namespace std;

int main() {
  Stack<int> st = Stack<int>(2);

  st.push(256);
  st.push(512);

  cout << "Pop 1: " << st.pop() << endl;
  cout << "Pop 2: " << st.pop() << endl;

  return 0;
}
