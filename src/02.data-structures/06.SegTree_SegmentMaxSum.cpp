struct TreeMin  {
    struct node {
        long long seg, pref, suf, sum;
    };
    node combine(node a, node b) {
        return {
            /*seg*/  max(a.seg, max(b.seg, a.suf+b.pref)),   
            /*pref*/ max(a.pref, a.sum+b.pref),
            /*suf*/  max(b.suf, b.sum+a.suf),
            /*sum*/  a.sum+b.sum
        };
    }
    const node ZERO = {0,0,0,0};
    node one_eleme(int x){
        return {
            max(x,0),  //seg
            max(x,0),  //pref
            max(x,0),  //suf
            x          //sum
        };
    }
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
    node calc(int l, int r, int x, int lx, int rx) {
        if (l>=rx || lx>=r)  return ZERO;
        if (lx>=l&&rx<=r)   return tree[x];
        int m = (lx + rx) / 2;
        node sum1 = calc(l, r, 2 * x + 1, lx, m);
        node sum2 = calc(l, r, 2 * x + 2, m, rx);
        return combine(sum1, sum2);
    }
    node calc(int l, int r) {
        return calc(l, r, 0, 0, size);
    }
};
