// a ^ (x) = b (mod p), (a, p) = 1
// a ^ (i * m + j) = b (mod p), m = ceil(sqrt(p))
// a ^ (i * m) = b * a ^ (-j) (mod p)
int baby_giant_step(int a, int b, int p)    {
   // a ^ (-1) = a ^ (p - 2) mod p
    int m = ceil(sqrt(p)), _a = binpow(a, p - 2, p);
    // s[b * a ^ (-j)] = j
    unordered_map<int, int> s;
    for (int j = 0, t = b; j < m; j++, t = t * _a % p)
        s[t] = j;
    for (int i = 0; i < m; i++) {
        // s.find(a ^ (i * m))
        auto f = s.find(binpow(a, i * m, p));
        // i * m + j
        if (f != s.end())
            return i * m + f->ss;
    }
    return -1;
}