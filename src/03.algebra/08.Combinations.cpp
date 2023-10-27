int c(int n, int k)
{
    int result = 1;
    for (int i = 1; i <= k; i++)
    {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}
//triangle pascal
const int N = 20;
vector<vector<int>> C(N + 1, vector<int>(N + 1, 1));
for (int i = 1; i < N + 1; i++)
    for (int j = 1; j < N + 1; j++)
        C[i][j] = C[i - 1][j] + C[i][j - 1];