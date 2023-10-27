#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// const int N = 1e4;

bool compare(int& _i, int& _j, int& size) {
    int count = 0;
    bitset<16> j_prof = _j, i_prof = _i;
    for (int i = 0; i < size; i++) {
        if (j_prof[i] && !i_prof[i]) {
            if (count % 2 != 0) {
                return false;
            }
            else {
                count = 0;
                continue;
            }
        }

        if (j_prof[i] && i_prof[i]) {
            return false;
        }

        if (!i_prof[i]) {
            count++;
            continue;
        }

        if (i_prof[i]) {
            if (count % 2) {
                return false;
            }
            else {
                count = 0;
                continue;
            }
        }
    }

    return !(count % 2);
}

bool lastOrNo(int& i, int& size) {
    bitset<16> a = i;
    int count = 0;
    for (int j = 0; j < size; j++) {
        if (!a[j]) {
            count++;
        }
        else if (a[j]) {
            if (count % 2) {
                return false;
            }
            else {
                count = 0;
                continue;
            }
        }
    }

    return !(count % 2);
}

long long dp[4096][4096];

signed main() {
    int m, n;
    cin >> n >> m;
    if (n % 2 && m % 2) {
        cout << 0 << endl;
        return 0;
    }
    if (n > m) {
        swap(m, n);
    }
    int size_N = (1 << m);
    int N = (1 << n);

    dp[0][0] = 1;
    for (int k = 1; k < m; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                dp[k][i] += dp[k - 1][j] * compare(j, i, n);
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (lastOrNo(i, n)) {
            ans += dp[m - 1][i];
        }
    }

    cout<<ans;

}