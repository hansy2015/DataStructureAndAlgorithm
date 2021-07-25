#include "AdjSet.h"
#include <unordered_set>
class EulerLoop {
private:
  AdjSet adjset;
  vector<int> paths;
  vector<unordered_set<int>> mark;
public:
  EulerLoop(AdjSet& adjset) : adjset(adjset) {
    mark.resize(adjset.getV());
  }

  bool hasEulerLoop() {
    return true;
  }
private:
  bool Dfs(int u, int pre, int edge) {
    if (edge == 0) {
      return true;
    }
    for (const int& v : adjset.Adj(u)) {
      if (v == pre) continue;
      if (mark[u].count(v) == 0) {
        mark[u].insert(v);
        mark[v].insert(u);
        if (!Dfs(v, u, edge - 1)) {
          mark[u].erase(v);
          mark[v].erase(u);
        } else {
          paths.push_back(v);
          return true;
        }
      }
    }
    return false;
  }
public:
  vector<int> Hierholzer() {
    vector<int> res;
    stack<int> stk;
    int curv = 0;
    stk.push(curv);
    while (!stk.empty()) {
      if (adjset.degree(curv) != 0) {
        stk.push(curv);
        int w = *adjset.adj(curv).begin();
        adjset.removeEdge(curv, w);
        curv = w;
      } else {
        res.push_back(curv);
        curv = stk.pop();
      }
    }
    return res;
  }

public:
  vector<int> Result() {
    Dfs(0, 0, adjset.getE());
    paths.push_back(0);
    return paths;
  }

};