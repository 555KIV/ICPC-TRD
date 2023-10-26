#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int mass[100001];
  vector<int> check;
  vector<int> result;
  vector<vector<pair<int, int>>> mass(100001);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n - 1; i++) {
    check.push_back(i + 1);
  }

  result.push_back(0);

  for (int i = 0; i < m; i++) {
    int first, second, third;
    cin >> first >> second >> third;
    first--;
    second--;
    mass[first].push_back(make_pair(second, third));
    mass[second].push_back(make_pair(first, third));
  }

  while (!check.empty()) {
    int temp = 10e5;
    int top = 10e5;
    int parent = 0;

    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < mass[result[i]].size(); j++) {
        if (mass[result[i]][j].second < temp &&
            find(check.begin(), check.end(), mass[result[i]][j].first) !=
                check.end()) {
          temp = mass[result[i]][j].second;
          top = mass[result[i]][j].first;
          parent = result[i];
        }
      }
    }

    result.push_back(top);

    int count = 0;
    for (int k = 0; k < check.size(); k++) {
      if (check[k] == top) {
        count = k;
        break;
      }
    }

    check.erase(check.begin() + count);

    int sum = 0;
    count = 0;
    temp = 10e5;
    top = 10e5;
  }

  cout << sum << endl;

  return 0;
}
