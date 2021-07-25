#include "EulerLoop.h"
#include <iostream>

using namespace std;

int main() {
  AdjSet adj(5, 6);
  EulerLoop eulerLoop(adj);
  vector<int> res = eulerLoop.Result();
  for (int i = 0; i < (int)res.size(); i++) {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}