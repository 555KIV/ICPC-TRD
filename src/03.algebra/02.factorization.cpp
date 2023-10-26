vector<int> factorization(long long n)
{
    vector<int> result;
    for (int i = 2; i * i < n; i++)
        while (n % i == 0)
        {
            result.push_back(i);
            n /= i;
        }
    if (n != 1)
        result.push_back(n);
    return result;
}