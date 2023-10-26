#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &mass, vector<bool> &used, int vertex) {
  used[vertex] = true;
  for (int i = 0; i < mass[vertex].size(); i++) {
    int neighbor = mass[vertex][i];
    if (!used[neighbor]) {
      dfs(mass, used, neighbor);
    }
  }
}

int main() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<vector<int>> mass(n);
  vector<bool> used(n, false);

  for (int i = 0; i < m; i++) {
    int first, second;
    cin >> first >> second;
    first--;
    second--;
    mass[first].push_back(second);
    mass[second].push_back(first);
  }

  int result = 0;
  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      dfs(mass, used, i);
      result++;
    }
  }

  cout << result << '\n';

  return 0;
}
