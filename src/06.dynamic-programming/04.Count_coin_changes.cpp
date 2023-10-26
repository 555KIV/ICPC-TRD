int change(int amount, const std::vector<int>& coins) {
    int numCoins = coins.size();
    std::vector<std::vector<int>> wayToChange(numCoins, std::vector<int>(amount + 1, 0));

    for (int i = 0; i < numCoins; i++) {
        wayToChange[i][0] = 1;
    }

    for (int i = numCoins - 1; i >= 0; i--) {
        for (int j = 1; j <= amount; j++) {
            if (j - coins[i] >= 0) {
                wayToChange[i][j] += wayToChange[i][j - coins[i]];
            }
            if (i + 1 < numCoins) {
                wayToChange[i][j] += wayToChange[i + 1][j];
            }
        }
    }

    return wa
