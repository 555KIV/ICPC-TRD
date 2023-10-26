#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> g;
vector<bool> used;
int timer = 0;
vector<int> tin, fup;
vector<pair<int, int>> result;

void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  for (int i = 0; i < g[v].size(); i++) {
    int to = g[v][i];
    if (to == p)
      continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v] && count(g[v].begin(), g[v].end(), to) == 1) {
        result.push_back({min(v, to), max(to, v)});
      }
    }
  }
}

void find_bridges(int n) {
  timer = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
}

int main() {
  int n;
  cin >> n;
  g.resize(n);
  used.assign(n, false);
  tin.resize(n);
  fup.resize(n);
  cin.ignore();

  for (int i = 0; i < n; i++) {
    int current = 0, count = 0;
    cin >> current >> count;
    for (int j = 0; j < count; j++) {
      int temp = 0;
      cin >> temp;
      g[current].push_back(temp);
    }
  }

  find_bridges(n);

  if (!result.empty()) {
    sort(result.begin(), result.end());
    for (auto bridge : result) {
      cout << bridge.first << " " << bridge.second << endl;
    }
  } else {
    cout << "Empty" << endl;
  }

  return 0;
}
