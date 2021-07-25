#include <iostream>
#include <cassert>
#include <vector>
#include <set>

using namespace std;

class AdjSet {
private:
  int V;
  int E;
  vector<set<int>> adj;
  
public:
  AdjSet(int V, int E) {
    assert(V >= 0 && E >= 0);
    this->V = V;
    this->E = E;
    adj.resize(V);
    for (int i = 0; i < E; i++) {
      int a, b;
      cin >> a >> b;
      if (a == b || adj[a].find(b) != adj[a].end()) {
        continue;
      }
      adj[a].insert(b);
      adj[b].insert(a);
    }
  }
  AdjSet(AdjSet& adjset) {
    this->V = adjset.getV();
    this->E = adjset.getE();
    for (int i = 0; i < V; i++) {
      adj.push_back(adjset.Adj(i));
    }
  }

  void operator= (const AdjSet& adjset) {
    this->V = adjset.getV();
    this->E = adjset.getE();
    for (int i = 0; i < V; i++) {
      adj.push_back(adjset.Adj(i));
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
    return  adj[v].find(w) != adj[v].end();
  }

  set<int> Adj(int v) {
    assert(v >= 0 && v < V);
    return adj[v];
  }
  

  int degree(int v) {
    return Adj(v).size();
  }

  void removeEdge(int v, int w) {
    assert(v >= 0 && v < V);
    assert(w >= 0 && w < V);
    adj[v].erase(w);
    adj[w].erase(v);
  }

};