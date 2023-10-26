// mass assignment
struct lazy_seg_tree    {
    vector<int> tree, lazy;
    int size;
    init(int n) {
        size = 1;
        while (size < n) size <<= 1;
        tree.assign(2 * size - 1, 0);
        lazy.assign(2 * size - 1, 0);
    }
    void push(int x)    {
        tree[2 * x + 1] = lazy[x];
        lazy[2 * x + 1] = lazy[x];
        tree[2 * x + 2] = lazy[x];
        lazy[2 * x + 2] = lazy[x];
        lazy[x] = -1;
    }
    void update(int v, int l, int r, int x, int lx, int rx) {
        if (rx <= l && r <= lx) return;
        if (l <= lx && rx <= r) {
            push(x);
            tree[x] = v;
            lazy[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        tree[x] = v;
        lazy[x] = v;
        update(v, l, r, 2 * x + 1, lx, m);
        update(v, l, r, 2 * x + 2, m, rx);
    }
    void update(int v, int l, int r)    {
        update(v, l, r, 0, 0, size);
    }
    int get(int i, int x, int lx, int rx)   {
        if (rx - lx == 1)   return tree[x];
        int m = (lx + rx) / 2;
        if (i < m) get(i, 2 * x + 1, lx, m);
        else    get(i, 2 * x + 2, m, rx);
    }
    int get(int i)  {
        return get(i, 0, 0, size);
    }
};
