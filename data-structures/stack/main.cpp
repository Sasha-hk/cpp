#include "stack.cpp"
#include <iostream>

using namespace std;

int main() {
  cout << "Hello world" << endl;

  Stack st = Stack(2);

  st.push(256);
  st.push(512);
  st.push(1024);

  cout << st.pop() << endl;
  cout << st.getSize() << endl;
  cout << st.getMaxSize() << endl;

  return 0;
}