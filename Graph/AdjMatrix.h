#include <iostream>
#include <cassert>

using namespace std;

class AdjMatrix {
private:
  int V;
  int E;
  int **adj;
  
public:
  AdjMatrix(int V, int E) {
    assert(V >= 0 && E >= 0);
    adj = new int*[V];
    for (int i = 0; i < V; i++) {
      adj[i] = new int[V];
    }
    for (int i = 0; i < E; i++) {
      int u, v;
      cin >> u >> v;
      adj[u][v] = adj[v][u] = 1;
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
    return adj[v][w] == 1;
  }

  vector<int> Adj(int v) {
    assert(v >= 0 && v < V);
    vector<int> res;
    for (int i = 0; i < V; i++) {
      if (adj[v][i] == 1) {
        res.push_back(i);
      }
    }
    return res;
  }

  int degree(int v) {
    return Adj(v).size();
  }

};