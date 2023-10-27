//simple gcd
int gcd(int a, int b)   {
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
// euclidean algorithm
int advanced_gcd(int a, int b, int &x, int &y) {
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = advanced_gcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

//rev element
int rev_elem(int a, int m)  {
    int x, y;
    int g = advanced_gcd(a, m, x, y);
    if (g!=1) return 0;
    else return (x % m + m) % m;
}