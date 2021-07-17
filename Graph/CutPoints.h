#include "AdjSet.h"

class CutPoints {
private:
  AdjSet adjset;
  vector<int> ord;
  vector<int> low;
  vector<int> mark;
  int id;
public:
  vector<int> points;
  Bridge(AdjSet& adjset) : adjset(adjset){
    ord.resize(this->adjset.getV());
    low.resize(this->adjset.getV());
    mark.resize(this->adjset.getV(), 0);
    this->id = 0;
    Dfs(0, -1);
  }
private:
  void Dfs(int u, int pre) {
    mark[u] = 1;
    ord[u] = low[u] = id++;
    int child = 0;
    for (const int& v : adjset.Adj(u)) {
      if (mark[v] == 0) {
        Dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (v != pre && low[v] >= ord[u]) { // 回不去了
          points.push_back(u);
        }
        child++;
        if (v == pre && child > 1) {
          points.push_back(v);
        }
      } else {
        if (v != pre) {
          low[u] = min(low[u], ord[v]);
        }
      }
    }
  }

};
