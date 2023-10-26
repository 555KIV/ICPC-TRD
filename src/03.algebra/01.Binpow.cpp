int binpow_mod(int a, int pow, int MOD) {
    if (!pow) {
        return 1;
    }
    if (pow % 2 == 1) {
        return (__int128_t)binpow_mod(a, pow - 1, MOD) * a % MOD;
    }
    else    {
        __int128_t tmp = binpow_mod(a, pow / 2, MOD);
        __int128_t temp = (tmp * tmp) % MOD;
        return temp;
    }
}

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int binmul(int a, int b)    {
    int res = 0;
    while (b)
    {
        if (b & 1)
            res += a;
        a *= 2;
        b >>= 1;
    }
    return res;
}