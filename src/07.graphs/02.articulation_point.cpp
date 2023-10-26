#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
int timer = 0;
vector<int> tin, fup;
set<int> result;

void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  int children = 0;
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p)
      continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] >= tin[v] && p != -1)
        result.insert(v);
      children++;
    }
  }
  if (p == -1 && children > 1)
    result.insert(v);
}

int main() {
  int n, m, k;
  cin >> n >> m;
  g.resize(n);
  used.assign(n, false);
  tin.resize(n);
  fup.resize(n);

  for (int i = 0; i < m; i++) {
    int first, second;
    cin >> first >> second;
    first--;
    second--;
    g[first].push_back(second);
    g[second].push_back(first);
  }

  for (int i = 0; i < n; i++) {
    dfs(i);
  }

  for (int it : result) {
    cout << it + 1 << " ";
  }

  return 0;
}
