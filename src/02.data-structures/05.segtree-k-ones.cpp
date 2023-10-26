struct k_ones_tree  {
    // tree_sum
    int find(int k, int x, int lx, int rx)  {
        if (rx - lx == 1)   return lx;
        int m = (rx + lx) / 2;
        if (k < tree[2 * x + 1]) return find(k, 2 * x + 1,lx, m);
        else
            return find(k - tree[2 * x + 1], 2 * x + 2, m, rx);
    }
    int find(int k) {
        return find(k, 0, 0, size);
    }
};
