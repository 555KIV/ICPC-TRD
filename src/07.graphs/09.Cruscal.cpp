#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

int findRoot(vector<int> &parent, int v) {
  if (parent[v] == v) {
    return v;
  } else {
    parent[v] = findRoot(parent, parent[v]);
    return parent[v];
  }
}

bool connected(vector<int> &parent, int v1, int v2) {
  return findRoot(parent, v1) == findRoot(parent, v2);
}

void merge(vector<int> &parent, int v1, int v2) {
  int r1 = findRoot(parent, v1);
  int r2 = findRoot(parent, v2);
  if (r1 != r2) {
    if (rand() % 2 == 0) {
      parent[r1] = r2;
    } else {
      parent[r2] = r1;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> mst(n);
  vector<int> parent(n);
  vector<pair<int, pair<int, int>>> G(m);

  for (int i = 0; i < m; i++) {
    int v, u, cost;
    cin >> v >> u >> cost;
    G[i] = {cost, {v - 1, u - 1}};
  }

  sort(G.begin(), G.end());

  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  int cost = 0;
  int all_sum = 0;

  for (int i = 0; i < m; i++) {
    int a = G[i].second.first;
    int b = G[i].second.second;
    int l = G[i].first;

    if (!connected(parent, a, b)) {
      mst[a].push_back(l + 1);
      mst[b].push_back(l + 1);
      merge(parent, a, b);
      all_sum += l;
    }
  }

  cout << all_sum << endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < mst[i].size(); j++) {
      cout << i + 1 << " " << mst[i][j] << endl;
    }
  }

  return 0;
}
