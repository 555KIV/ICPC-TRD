struct first_above_tree
{
    // tree_max
    int first_above(int v, int x, int lx, int rx)   {
        if (tree[x] < v) return -1;
        if (rx - lx == 1) return lx;
        int m = (lx + rx) / 2;
        int res = first_above(v, 2 * x + 1, lx, m);
        if (res == -1)  res = first_above(v, 2 * x + 2, m, rx);
        return res;
    }
    int first_above(int v) {
        return first_above(v, 0, 0, size);
    }
};
struct first_above_left_tree    {
    // tree_max
    int first_above(int v, int l, int x, int lx, int rx) {
        if (tree[x] < v || rx <= l) return -1;
        if (rx - lx == 1)  return lx;
        int m = (lx + rx) / 2;
        int res = first_above(v, l, 2 * x + 1, lx, m);
        if (res == -1) res = first_above(v, l, 2 * x + 2, m, rx);
        return res;
    }
    int first_above(int v, int l) {
        return first_above(v, l, 0, 0, size);
    }
};