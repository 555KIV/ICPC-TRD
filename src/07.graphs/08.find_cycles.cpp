#include <iostream>
#include <vector>

using namespace std;

int cycle_start = -1, cycle_end = 0;
vector<int> p;

bool dfs(vector<vector<int>> &g, vector<bool> &used, vector<int> &color,
         int vertex) {
  color[vertex] = 1;
  for (int i = 0; i < g[vertex].size(); i++) {
    int to = g[vertex][i];
    if (color[to] == 0) {
      if (dfs(g, used, color, to)) {
        p[to] = vertex;
        return true;
      }
    } else if (color[to] == 1) {
      cycle_start = to;
      cycle_end = vertex;
      return true;
    }
  }
  color[vertex] = 2;
  return false;
}

int main() {
  int n = 0, m = 0;
  cin >> m >> n;

  vector<vector<int>> mass(n);
  vector<bool> used(n, false);
  vector<int> color(n, 0);
  vector<int> cycle;

  p.assign(n, -1);

  for (int i = 0; i < m; i++) {
    int first, second;
    cin >> first >> second;
    first--;
    second--;
    mass[first].push_back(second);
  }

  for (int i = 0; i < n; i++) {
    if (dfs(mass, used, color, i)) {
      break;
    }
  }

  if (cycle_start == -1) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
    cycle.push_back(cycle_start);
    for (int v = cycle_end; v != cycle_start; v = p[v]) {
      cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    for (int i = 0; i < cycle.size(); i++) {
      cout << cycle[i] + 1 << " ";
    }
    cout << endl;
  }

  return 0;
}
