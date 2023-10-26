ll dfs(vector<vector<int>> &Map, int i, int j, vector<vector<bool>> &used, vector<int> &Xvalue, vector<int> &Yvalue)    {
    used[i][j] = true;
    bool flag = false;
    ll sum = Xvalue[i] * Yvalue[j];
    int a[] = {0, -1, 1, 0};
    int b[] = {-1, 0, 0, 1};
    for (int h = 0; h < 4; h++)
        if (Map[i + a[h]][j + b[h]] == 0 && !used[i + a[h]][j + b[h]]) {
            flag = true;
            sum += dfs(Map, i + a[h], j + b[h], used, Xvalue, Yvalue);
        }
    if (!flag)  {
        return Xvalue[i] * Yvalue[j];
    }
    return sum;
}
int main()  {
    int w, h, n;
    cin >> w >> h >> n;
    set<int> x, y;
    unordered_map<int, int> X, Y;
    vector<vector<int>> lines;
    vector<int> Xvalue, Yvalue;
    x.insert(0);
    y.insert(0);
    x.insert(w);
    y.insert(h);
    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 < 0)    x1 = 0;
        if (x1 > w)    x1 = w;
        if (y1 < 0)    y1 = 0;
        if (y1 > h)    y1 = h;
        if (x2 < 0)    x2 = 0;
        if (x2 > w)    x2 = w;
        if (y2 < 0)    y2 = 0;
        if (y2 > h)    y2 = h;
        lines.push_back({x1, y1, x2, y2});
        x.insert(x1);
        x.insert(x2);
        y.insert(y1);
        y.insert(y2);
    }
    int index = 0;
    for (auto _x : x)   {
        X[_x] = index;
        index += 2;
    }
    index = 0;
    for (auto _y : y)    {
        Y[_y] = index;
        index += 2;
    }
    int prev = 0;
    for (auto _x = ++x.begin(); _x != x.end(); _x++) {
        Xvalue.push_back(0);
        Xvalue.push_back(*_x - prev);
        prev = *_x;
    }
    Xvalue.push_back(0);
    prev = 0;
    for (auto _y = ++y.begin(); _y != y.end(); _y++) {
        Yvalue.push_back(0);
        Yvalue.push_back(*_y - prev);
        prev = *_y;
    }
    Yvalue.push_back(0);
    int Xs = Xvalue.size();
    int Ys = Yvalue.size();
    vector<vector<int>> Map(Xs, vector<int>(Ys, 0));
    for (int i = 0; i < Xs; i++)  {
        Map[i][0] = 1;
        Map[i][Ys - 1] = 1;
    }
    for (int i = 0; i < Ys; i++) {
        Map[0][i] = 1;
        Map[Xs - 1][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (lines[i][0] == lines[i][2])
        {
            int x = X[lines[i][0]];
            int y1 = Y[lines[i][1]];
            int y2 = Y[lines[i][3]];
            if (y1 > y2)
                y1 ^= y2 ^= y1 ^= y2;
            for (int i = y1; i <= y2; i++)
                Map[x][i] = 1;
        }
        else {
            int y = Y[lines[i][1]];
            int x1 = X[lines[i][0]];
            int x2 = X[lines[i][2]];
            if (x1 > x2)
                x1 ^= x2 ^= x1 ^= x2;
            for (int i = x1; i <= x2; i++)
                Map[i][y] = 1;
        }
    }
    vector<ll> s;
    vector<vector<bool>> used(Xs, vector<bool>(Ys, false));
    for (int i = 1; i < Xs - 1; i++) {
        for (int j = 1; j < Ys - 1; j++)    {
            if (Map[i][j] == 0 && !used[i][j])
                s.push_back(dfs(Map, i, j, used, Xvalue,
                                Yvalue));
        }
    }
    sort(s.rbegin(), s.rend());
    for (auto _s : s)
        cout << _s << "\n";
}