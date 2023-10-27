ull dp[20][20][5000];
ull binpow(ull a, unsigned long long  int b, ull p = 0) {
    ull res = 1;
    while (b) {
        if (b & 1) res = p ? (res * a) % p : (res * a);
        a = p ? (a * a) % p : (a * a);
        b >>= 1;
    }
    return res;
}
int main()  {
    ull n, m, i, j, k, l2, r;
    cin >> n >> m;
    char tiling[20][20];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)tiling[i][j] = '.';
    }
    for (k = 0; k < n + 1;k++) {
        for (j = 0; j < m; j++) {
            for (ull mask = 0; mask < (ull)pow(2, m); mask++) {
                if (k != 0 || j != 0 || mask != 0)dp[k][j][mask] = 0;
                else dp[k][j][mask] = 1;
            }
        }
    }
    for (k = 0; k < n; k++) {
        for (j = 0; j < m; j++) {
            for (ull mask = 0; mask < (ull)pow(2, m); mask++) {
                if (k < n - 1 && tiling[k][j] == '.' && tiling[k + 1][j] == '.' && (mask & (1 << j)) == 0)
                    dp[k + ((j + 1) / m)][(j + 1) % m][mask + (1 << j)] += dp[k][j][mask];
                if (j < m - 1 && tiling[k][j] == '.' && tiling[k][j + 1] == '.' && (mask & (3 << j)) == 0)
                    dp[k + ((j + 1) / m)][(j + 1) % m][mask + (2 << j)] += dp[k][j][mask];
                if (((1 << j) & mask) != 0 || tiling[k][j] != '.')
                    dp[k + ((j + 1) / m)][(j + 1) % m][(mask | (1 << j)) - (1 << j)] += dp[k][j][mask];
            }
        }
    }
    cout << binpow(2, n * m / 2, 1000000007) * (dp[n][0][0] % 1000000007) % 1000000007; 
    return 0;
}
