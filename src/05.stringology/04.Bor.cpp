// Построение бора, поиск слов в лексиграфическом порядке (dfs)

int K = 26;
// int MAXN = 10;
int MAXN = 2 * 1e5 + 1;

struct vertex
{
    vector<int> next;
    vector<int> count_v;
    bool leaf;
};

vector<vertex> t(MAXN);
int sz;

void add_string(string &s)
{
    int v = 0;
    for (size_t i = 0; i < s.length(); ++i)
    {
        char c = s[i] - 'a';
        if (t[v].next[c] == -1)
        {
            t[sz].next.assign(K, -1);
            t[sz].count_v.assign(K, 0);
            t[v].next[c] = sz++;
        }
        t[v].count_v[c]++;
        v = t[v].next[c];
    }

    t[v].leaf = true;
}

string dfs(int k)
{
    string result = "";
    int init = 0;
    while (k != 0)
    {
        int temp = 0;
        for (int i = 0; i < t[init].next.size(); i++)
        {
            if (t[init].count_v[i] && t[init].count_v[i] + temp >= k)
            {
                init = t[init].next[i];
                k -= temp;
                if (t[init].leaf)
                {
                    k--;
                }
                result += char(i + 'a');
                break;
            }
            else if (t[init].count_v[i])
            {
                temp += t[init].count_v[i];
            }
        }
    }

    return result;
}

signed main()
{
    long long _t = 1;
    // cin >> _t;
    t[0].next.assign(K, -1);
    t[0].count_v.assign(K, 0);
    sz = 1;
    for (int _i = 0; _i < _t; _i++)
    {
        int n = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            cin >> s;
            bool flag = true;
            for (int i = 0; i < s.size(); i++)
            {
                if (!isdigit(s[i]))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                int k = stoi(s);
                cout << dfs(k) << endl;
            }
            else
            {
                add_string(s);
            }
        }
    }
    return 0;
}