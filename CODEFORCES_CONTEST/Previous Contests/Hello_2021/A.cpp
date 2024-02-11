#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)              \
    for (int _i = (start); _i < (end); _i++) \
        cout << (v[_i]) << " ";              \
    cout << "\n";
#define log(v)                                                \
    for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
        cout << *(__i) << " ";                                \
    cout << "\n";
#define print(args...)                           \
    {                                            \
        string _s = #args;                       \
        replace(_s.begin(), _s.end(), ',', ' '); \
        stringstream _ss(_s);                    \
        istream_iterator<string> _it(_ss);       \
        err(_it, args);                          \
        cout << "\n";                            \
    };

using vi = vector<int>;
using vll = vector<long long>;
using ll = long long;
using ld = long double;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

void solve()
{
    int k, n;
    cin >> n >> k;
    vector<vector<char>> grid(n, vector<char>(n, '.'));
    bool not_pos = false;
    if (k > (n + 1) / 2)
    {
        cout << "-1\n";
        return;
    }
    else
    {
        grid[0][0] = 'R';
        int id = 2;
        
        for (int i = 0; i < k - 1; i++)
        {
            if (id >= 0 and id < n)
                grid[id][id] = 'R', id += 2;
            else
                not_pos = true;
        }
    }

    if (not_pos)
        cout << "-1\n";
    else
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << grid[i][j];
            cout << "\n";
        }
    }
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}