#include "Bridge.h"
#include <iostream>

using namespace std;

int main() {
  AdjSet adj(7, 8);
  Bridge bridge(adj);
  cout << "-----------------------" << endl;
  for (int i = 0; i < (int)bridge.bridge.size(); i++) {
    cout << bridge.bridge[i].first << " " << bridge.bridge[i].second << endl;
  }
  return 0;
}