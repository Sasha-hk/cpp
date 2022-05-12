#include "binary-tree.h"
#include <iostream>

using namespace std;

int main() {
  Tree<int> tree = Tree<int>(0, 7);

  tree.insert(4);
  tree.insert(12);
  tree.insert(54);
  tree.insert(22);
  tree.insert(12);
  tree.insert(34);
  tree.insert(-1);
  tree.insert(7);
  tree.insert(-356);

  tree.printTree(tree.getRoot());

  return 0;
}
