int get_random_number(int l, int r) {
    random_device random_device;
    mt19937 generator(random_device());
    uniform_int_distribution<int> distribution(l, r);

    return distribution(generator);
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }

    return gcd(b, a % b);
}
int f(int x, int c, int n) {
    return ((x * x + c) % n);
}

int polard(int n) {
    int g = 1;
    for (int i = 0; i < 5; i++) {
        int x = get_random_number(1, n);
        int c = get_random_number(1, n);
        int h = 0;
        while (g == 1) {
            x = f(x, c, n) % n;
            int y = f(f(x, c, n), c, n) % n;
            g = gcd(abs(x - y), n);
            if (g == n) {
                g = 1;
            }
            h += 1;
            if (h > 4 * (int)pow(n, 1.0 / 4)) {
                break;
            }
        }

        if (g > 1) {
            return g;
        }
    }
    return -1;
}
signed main()
{
    int n = 0;
    cin >> n;
    vector<int> a;
    while (n > 1) {
        int m = ff(n);
        if (m > 0) {
            n = n / m;
            a.push_back(m);
        }
        else {
            break;
        }
    }
    vector<int> ans;
    a.push_back(n);
    for (auto& it : a) {
        int i = 2;
        int m = it;
        while (i * i <= m) {
            if (m % i == 0) {
                ans.push_back(i);
                m = m / i;
            }
            else {
                i += 1;
            }
        }
        ans.push_back(m);
    }
    sort(all(ans));
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}