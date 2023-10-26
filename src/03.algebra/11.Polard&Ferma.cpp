i128 func(i128 x, i128 c, i128 n)
{
    return (x * x + c) % n;
}

int po_pol(int n, int retry, int &increm)
{
    if (retry == 5)
    {
        return -1;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist_x(2, n - 1);
    uniform_int_distribution<> dist_c(1, n - 1);
    int x = dist_x(gen), c = dist_c(gen), y = x, g = 1;
    while (g == 1)
    {
        increm++;
        x = func(x, c, n);
        y = func(func(y, c, n), c, n);
        g = gcd(abs(x - y), n);
        if (g == n)
        {
            po_pol(n, retry + 1, increm);
        }
        if (increm > MAXI)
        {
            return -1;
        }
    }
    return g;
}
 
bool ferma(long long x) {
    if (x == 2)
        return true;
    srand(time(NULL));
    for (int i = 0;i < 10;i++) {
        long long a = (rand() % (x - 2)) + 2;
        if (gcd(a, x) != 1)
            return false;
        if (binpow_mod(a, x - 1, x) != 1)
            return false;
    }
    return true;
}

void factoriz(int n, vector<int>& mass, int& total)
{
    if (n==1)
        return;
    if (ferma(n))
    {
        mass.push_back(n);
        return;
    }
 
    int divisor = po_pol(n,0, total);
 
    factoriz(divisor, mass, total);
    factoriz(n / divisor, mass, total);
 
    return ;
}