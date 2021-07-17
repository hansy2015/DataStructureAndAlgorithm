#include <iostream>
#include <bits/stdc++.h>
#include "SegmentTree.h"

using namespace std;

int main() {
  function<int(int, int)> Merge = [&](int x, int y){return x + y;};
  SegmentTree st({1, 2, 4, 5}, Merge);
  cout << st.query(0, 2) << endl;
  st.Set(0, 100);
  cout << st.query(0, 2) << endl;
  return 0;
}