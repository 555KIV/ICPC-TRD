struct TreeMin
{
    struct node {
        int min;
        int count;
    };
    node combine(node a, node b) {
        if (a.min<b.min) return a;
        if (a.min>b.min) return b;
        return {a.min, a.count+b.count};
    }
    const node ZERO = {INT_MAX,0};
    vector<node> tree;
    int size;
    void init(int n) {
        size = 1;
        while (size < n)
        {
            size *= 2;
        }
        tree.assign(2 * size - 1, {0,0});
    }
    node calc(int l, int r, int x, int lx, int rx)  {
        if (l>=rx || lx>=r) return ZERO;
        if (lx>=l&&rx<=r)  return tree[x];
        int m = (lx + rx) / 2;
        node sum1 = calc(l, r, 2 * x + 1, lx, m);
        node sum2 = calc(l, r, 2 * x + 2, m, rx);
        return combine(sum1, sum2);
    }
    node calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};