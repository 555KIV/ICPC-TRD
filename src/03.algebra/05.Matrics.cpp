vector<vector<int>> matrix_production(vector<vector<int>>& a, vector<vector<int>>& b, int mod) {
    vector<vector<int>> result(a.size(), vector<int>(b[0].size()));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                result[i][j] += a[i][k] * b[k][j];
                if (mod) result[i][j] %= mod;
            }
        }
    }
    return result;
}

vector<vector<int>> fast_pow(vector<vector<int>>& a, int n) {
    if (n == 0) {
        vector<vector<int>> temp(a.size(), vector<int>(a[0].size()));
        for (int i = 0; i < a.size(); i++) {
            temp[i][i] = 1;
        }
        return temp;
    }
    if (n % 2 == 1) {
        vector<vector<int>> temp = fast_pow(a, n - 1);
        return matrix_production(temp, a, 1e7 + 7);
    }
    else {
        vector<vector<int>> b = fast_pow(a, n / 2);
        return matrix_production(b, b, 1e7 + 7);
    }
}