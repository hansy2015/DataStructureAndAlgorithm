#include "AdjSet.h"

class HamiltonLoop {
private:
  AdjSet adjset;
  vector<int> mark;
  vector<int> pre;
  int ans;
  int end;
public:
  HamiltonLoop(AdjSet& adjset) : adjset(adjset){
    mark.resize(this->adjset.getV(), 0);
    pre.resize(this->adjset.getV(), 0);
    end = -1;
    ans = 0;
    Dfs(0, 0);
  }
private:
  bool Dfs(int u, int fa) {
    mark[u] = 1;
    pre[u] = fa;
    ans++;
    for (const int& v : adjset.Adj(u)) {
      if (mark[v] == 0) {
        if (dfs(v, u)) return true;
      } else if (v == 0 && ans == adjset.getV()) {
        end = v;
        return true;
      }
    }
    mark[u] = 0;
    ans--;
    return false;
  }

public:
  vector<int> result() {
    vector<int> res;
    if (end == -1) return res;
    int cur = end;
    while (cur != 0) {
      res.push_back(cur);
      cur = pre[cur];
    }
    res.push_back(0);
    reverse(res.begin(), res.end());
    return res;
  }

};
