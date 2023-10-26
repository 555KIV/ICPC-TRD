// number of numbers x < n so that gcd(x, n) = 1
int phi(int n)
{
    if (n == 1)
        return 1;
    // f = vector<pair<prime, count>>
    auto f = factorization(n);
    int res = n;
    for (auto p : f)
    {
        res = res - res / p.first;
    }
    return res;
}