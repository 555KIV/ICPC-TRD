void bfs(vector<vector<int>> &adj, int start, vector<bool> &visited) {
  queue<int> q;
  visited[start] = true;
  q.push(start);

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    cout << current + 1 << " ";

    for (int neighbor : adj[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}
