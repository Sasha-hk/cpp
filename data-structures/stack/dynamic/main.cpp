#include "stack.cpp"
#include <iostream>

using namespace std;

int main() {
  Stack<int> st = Stack<int>(1);

  st.push(256);
  st.push(512);
  // st.push(1024);
  // st.push(2048);

  // cout << st.pop() << endl;
  // cout << st.pop() << endl;
  cout << st.pop() << endl;
  cout << st.pop() << endl;

  cout << endl << st.size() << endl;

  return 0;
}