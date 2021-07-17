#include <iostream>
#include <cassert>

using namespace std;

class AdjList {
private:
  int V;
  int E;
  vector<vector<int>> adj;
  
public:
  AdjList(int V, int E) {
    assert(V >= 0 && E >= 0);
    this->V = V;
    this->E = E;
    adj.resize(V);
    for (int i = 0; i < E; i++) {
      int a, b;
      cin >> a >> b;
      if (a == b || find(adj[a].begin(), adj[a].end(), b) != adj[a].end()) {
        continue;
      }
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }

  int getV() {
    return V;
  }
  int getE() {
    return E;
  }

  bool hasEdge(int v, int w) {
    assert(v >= 0 && v < V);
    assert(w >= 0 && w < V);
    return find(adj[v].begin(), adj[v].end(), w) != adj[v].end();
  }

  vector<int> Adj(int v) {
    assert(v >= 0 && v < V);
    return adj[v];
  }

  int degree(int v) {
    return Adj(v).size();
  }

};