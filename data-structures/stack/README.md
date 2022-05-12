# STACK

Code from [./dynamic//based-on-array/stack.h](./dynamic//based-on-array/stack.h), the STACK based on array.

Using example:

```cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
  Stack<int> st = Stack<int>(2);

  st.push(256);
  st.push(512);

  cout << "Pop  2: " << st.pop() << endl;
  cout << "peek 1: " << st.peek() << endl;
  cout << "Pop  1: " << st.pop() << endl;

  return 0;
}
```

Output:

```sh
Pop  2: 512
peek 1: 256
Pop  1: 256
```

The number in the constructor indicates how many elements it can hold before copying the array, in this case, it can store 10 elements before copying:

```cpp
Stack<int>(10)
```
