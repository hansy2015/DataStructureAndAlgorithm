#include <iostream>
#include "MapHeap.h"

using namespace std;

int main() {
  MaxHeap<int> maxHeap;
  maxHeap.add(5);
  maxHeap.add(2);
  maxHeap.add(1);
  maxHeap.add(9);
  maxHeap.add(3);
  maxHeap.add(6);
  for (int i = 0; i < 6; i++) {
    cout << maxHeap.getMax() << " ";
  }
  cout << endl;
  return 0;
}