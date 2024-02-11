#pragma GCC optimize("Ofast")
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
using pii = pair<int, int>;
using pll = pair<long long, long long>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

bool all_found(vector<bool> &f, int n)
{
    for (int i = 1; i < n + 1; i++)
        if (f[i] == false)
            return false;

    return true;
}

void solve()
{
    int n;
    cin >> n;
    vi a(n);
    vector<bool> found(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= n)
        {
            while (found[a[i]] and a[i] != 0)
                a[i] /= 2;

            if (a[i] == 0)
            {
                cout << "NO\n";
                return;
            }

            found[a[i]] = true;
        }
        else 
        {
            while(a[i] > n)
                a[i] /= 2;
            // now a[i] <= n
            while (found[a[i]] and a[i] != 0)
                a[i] /= 2;

            if (a[i] == 0)
            {
                cout << "NO\n";
                return;
            }

            found[a[i]] = true;
        }        
    }
    // log(found);
    if (all_found(found, n))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}