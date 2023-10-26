void dfs(vector<vector<int>> &adj, int start, vector<bool> &visited) {
  stack<int> s;
  visited[start] = true;
  s.push(start);

  while (!s.empty()) {
    int current = s.top();
    s.pop();

    cout << current + 1 << " ";

    for (int neighbor : adj[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        s.push(neighbor);
      }
    }
  }
}
