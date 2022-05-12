#include "binary-tree.h"
#include <iostream>

using namespace std;

int main() {
  Tree<int> tree = Tree<int>(0, 7);

  tree.insert(4);
  tree.insert(12);

  cout << tree.search(4)->data << endl;

  return 0;
}
