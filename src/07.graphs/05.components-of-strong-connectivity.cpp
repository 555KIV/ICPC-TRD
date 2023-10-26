#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g, gr;
vector<bool> used;
vector<int> order, component;

void dfs1(int v) {
  used[v] = true;
  for (size_t i = 0; i < g[v].size(); ++i) {
    if (!used[g[v][i]]) {
      dfs1(g[v][i]);
    }
  }
  order.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  component.push_back(v);
  for (size_t i = 0; i < gr[v].size(); ++i) {
    if (!used[gr[v][i]]) {
      dfs2(gr[v][i]);
    }
  }
}

int main() {
  int n;
  cin >> n;

  g.resize(n);
  gr.resize(n);
  used.assign(n, false);

  for (int i = 0; i < n; i++) {
    int a = 0, b = 0;
    cin >> a >> b;
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  for (int i = 0; i < n; ++i) {
    if (!used[i]) {
      dfs1(i);
    }
  }

  used.assign(n, false);

  for (int i = n - 1; i >= 0; --i) {
    int v = order[i];
    if (!used[v]) {
      dfs2(v);
      for (int j = 0; j < component.size(); j++) {
        cout << component[j] << " ";
      }
      cout << '\n';
      component.clear();
    }
  }

  return 0;
}
