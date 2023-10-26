#include <algorithm>
#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<int>>;

int knapsack(int max_weight, const std::vector<int> &weights,
             const std::vector<int> &values,
             std::vector<int> &selected_indices) {
    int n = (int)weights.size();
    matrix dp(n + 1, std::vector<int>(max_weight + 1));
    matrix selected(n + 1, std::vector<int>(max_weight + 1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= max_weight; ++j) {
            if (weights[i - 1] <= j) {
                dp[i][j] = std::max(values[i - 1] + dp[i - 1][j - weights[i - 1]],
                                    dp[i - 1][j]);
                if (values[i - 1] + dp[i - 1][j - weights[i - 1]] > dp[i - 1][j]) {
                    selected[i][j] = 1;
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int i = n;
    int j = max_weight;
    while (i > 0 && j > 0) {
        if (selected[i][j] == 1) {
            selected_indices.push_back(i - 1);
            j -= weights[i - 1];
        }
        i--;
    }
    return dp[n][max_weight];
}

int main() {
    // At the entrance we get the number of items, the capacity of the backpack,
    // then the weight and value of the items
    int n, max_weight;
    std::cin >> n >> max_weight;
    std::vector<int> weights(n), values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i] >> values[i];
    }

    std::vector<int> selected_indices;
    int max_value = knapsack(max_weight, weights, values, selected_indices);
    std::cout << max_value << "\n";
    std::sort(selected_indices.begin(), selected_indices.end());

    for (int index : selected_indices) {
        std::cout << index + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}
