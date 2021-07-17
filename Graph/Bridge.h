#include "AdjSet.h"

class Bridge {
private:
  AdjSet adjset;
  vector<int> ord;
  vector<int> low;
  vector<int> mark;
  int id;
public:
  vector<pair<int,int>> bridge;
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
    for (const int& v : adjset.Adj(u)) {
      if (mark[v] == 0) {
        Dfs(v, u);
        low[u] = min(low[u], low[v]);
        if (low[v] > ord[u]) {
          cout << "low[" << v << "]" << " = " << low[v] << endl;
          cout << "ord[" << u << "]" << " = " << ord[u] << endl;
          bridge.emplace_back(u, v);
        }
      } else {
        if (v != pre) {
          low[u] = min(low[u], ord[v]);
        }
      }
    }
  }

};
