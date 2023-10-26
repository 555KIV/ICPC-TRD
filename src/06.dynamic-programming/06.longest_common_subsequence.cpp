int longestCommonSubsequence(const std::string& text1, const std::string& text2) {
        int n = text1.length();
        int m = text2.length();
        std::vector<std::vector<int>> longestSubseqInPosition(n + 1, std::vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j]) {
                    longestSubseqInPosition[i][j] = 1 + longestSubseqInPosition[i + 1][j + 1];
                } else {
                    longestSubseqInPosition[i][j] = std::max(
                        longestSubseqInPosition[i][j + 1],
                        longestSubseqInPosition[i + 1][j]
                    );
                }
            }
        }

        return longestSubseqInPosition[0][0];
    }
