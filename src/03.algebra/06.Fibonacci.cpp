signed fibonacci()
{
    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<int>> mass(2, vector<int>(2));
    mass[0][0] = 0;
    mass[0][1] = 1;
    mass[1][0] = 1;
    mass[1][1] = 1;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n == 3)
    {
        cout << 2 << endl;
        return 0;
    }
    vector<vector<int>> powed = fast_pow(mass, n - 3, m);
    int result = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            result += powed[i][j];
    }
    cout << result % m << endl;
}