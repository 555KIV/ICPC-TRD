struct DisjointSets {
    vector<int> parent;
    vector<int> size;
    vector<long long> sum;
    vector<int> Max;
    vector<int> Min;
    void init(int n)    {
        parent.resize(n + 1);
        Min.resize(n+1);
        Max.resize(n+1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            Min[i] = i;
            Max[i] = i;
        }
        size.assign(n + 1, 1);
    }
    int get(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = get(parent[v]);
    }
    void Union(int a, int b)  {
        a = get(a);
        b = get(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            Min[a] = min(Min[a], Min[b]);
            Max[a] = max(Max[a], Max[b]);
            size[a] += size[b];
        }
    }
};