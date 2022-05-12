#include "binary-tree.h"
#include <iostream>

using namespace std;

int main() {
  Tree<int> tree = Tree<int>(7);

  tree.insert(4);
  tree.insert(12);

  cout << tree.search(20)->data << endl;

  Node<int>* x = tree.get(4);

  if (x != NULL) {
    cout << x->data << " <<< " << endl;
  }
  else {
    cout << "Data not found" << endl;
  }

  return 0;
}
