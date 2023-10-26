string z_func()
{
    string str;
    cin >> str;
    vector<int> Z(str.length(), 0);
    int n = str.length();
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (r >= i)
        {
            Z[i] = min(Z[i - l], r - i + 1);
        }
        while (Z[i] + i < n && str[Z[i]] == str[Z[i] + i])
            Z[i]++;

        if (r < i + Z[i] - 1)
        {
            l = i;
            r = i + Z[i] - 1;
        }
    }
}