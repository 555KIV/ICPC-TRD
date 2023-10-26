void count_sort(vector<int> &p, vector<int> &c)
{
    int n = p.size();
    vector<int> cnt(n), p_new(n), pos(n);
    for (auto x : c)
        cnt[x]++;
    pos[0] = 0;
    for (int i = 1; i < n; i++)
        pos[i] = pos[i - 1] + cnt[i - 1];
    for (auto x : p)
    {
        int i = c[x];
        p_new[pos[i]] = x;
        pos[i]++;
    }
    p = p_new;
}
signed suffix_array()
{
    string str;
    cin >> str;
    str += "&";
    int len = str.length();
    vector<int> p(len), c(len);
    vector<pair<char, int>> a(len);
    for (int i = 0; i < len; i++)
        a[i] = {str[i], i};
    sort(a.begin(), a.end());
    for (int i = 0; i < len; i++)
        p[i] = a[i].second;
    c[p[0]] = 0;
    for (int i = 1; i < len; i++)
        if (a[i].first == a[i - 1].first)
            c[p[i]] = c[p[i - 1]];
        else
            c[p[i]] = c[p[i - 1]] + 1;
    int k = 0;
    while ((1 << k) < len)
    {
        for (int i = 0; i < len; i++)
            p[i] = (p[i] - (1 << k) + len) % len;
        count_sort(p, c);
        vector<int> c_new(len);
        c_new[p[0]] = 0;
        for (int i = 1; i < len; i++)
        {
            pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % len]};
            pair<int, int> now = {c[p[i]], c[(p[i] + (1 << k)) % len]};
            if (now == prev)
                c_new[p[i]] = c_new[p[i - 1]];
            else
                c_new[p[i]] = c_new[p[i - 1]] + 1;
        }
        c = c_new;
        k++;
    }
    for (int i = 0; i < len; i++)
        cout << p[i] << " ";
}
