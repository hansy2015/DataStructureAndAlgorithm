#include <iostream>
#include <string>
#include "Set.h"
#include "BST.h"

using namespace std;

//template<class E>
class BSTSet : public Set{
private:
  BST<string>* bst;

public:
  BSTSet() {
    bst = new BST<string>();
  }
public:
  int getSize() {
    return bst->Size();
  }

  bool isEmpty() {
    return bst->isEmpty();
  }

  bool contains(string e) {
    return bst->contains(e);
  }

  void remove(string e) {
    bst->remove(e);
  }

  void add(string e) {
    bst->add(e);
  }
};

int main() {
  Set* s = new BSTSet();
  s->add("a");
  s->add("b");
  s->add("c");
  s->add("d");
  s->add("e");
  cout << s->getSize() << endl;
  return 0;
}