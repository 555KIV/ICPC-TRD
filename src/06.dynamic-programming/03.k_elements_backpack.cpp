#include <algorithm>
#include <iostream>
#include <vector>

using matrix = std::vector<std::vector<int>>;

int knapsack(int max_weight, const std::vector<int> &weights,
             const std::vector<int> &values,
             std::vector<int> &selected_indices, int k) {
    int n = (int)weights.size();
    matrix dp(n + 1, std::vector<int>(max_weight + 1));
    matrix selected(n + 1, std::vector<int>(max_weight + 1, 0));
    for (int i = 1; i <= std::min(n, k); ++i) {
        for (int j = 1; j <= max_weight; ++j) {
            if (weights[i - 1] <= j) {
                dp[i][j] = std::max(values[i - 1] + dp[i - 1][j - weights[i - 1]],
                                    dp[i - 1][j]);
                if (values[i - 1] + dp[i - 1][j - weights[i - 1]] > dp[i - 1][j]) {
                    selected[i][j] = i;
                }
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int i = std::min(n, k);
    int j = max_weight;
    while (i > 0 && j > 0) {
        if (selected[i][j] != 0) {
            selected_indices.push_back(selected[i][j] - 1);
            j -= weights[selected[i][j] - 1];
        }
        i--;
    }
    return dp[std::min(n, k)][max_weight];
}

int main() {
    int n, max_weight, k;
    std::cin >> n >> max_weight >> k;
    std::vector<int> weights(n), values(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> weights[i] >> values[i];
    }

    std::vector<int> selected_indices;
    int max_value = knapsack(max_weight, weights, values, selected_indices, k);
    std::cout << max_value << "\n";
    std::sort(selected_indices.begin(), selected_indices.end());

    for (int index : selected_indices) {
        std::cout << index + 1 << " ";
    }
    std::cout << std::endl;

    return 0;
}
