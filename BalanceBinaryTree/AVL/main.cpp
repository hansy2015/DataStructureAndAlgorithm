#include <iostream>
#include <vector>
#include "AVLTree.h"

using namespace std;

int main() {
  vector<int> a{2, 1, 4, 5, -1, 0};
  AVLTree<int,int> b;
  for (int i = 0; i < 6; i++) {
    b.add(a[i], i);
  }
  cout << b.isBST() << endl;
  cout << b.isBalanced() << endl;
  return 0;
}