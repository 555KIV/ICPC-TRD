int palindromes(std::string s) {
    int n = s.length();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    std::vector<std::vector<int>> pal(n, std::vector<int>(n, 1));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                dp[i][j] = 1;
            } else {
                pal[i][j] = pal[i + 1][j - 1] && (s[i] == s[j]);
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] + pal[i][j];
            }
        }
    }

    return dp[0][n - 1];
}
