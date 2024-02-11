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
using vvi = vector<vector<int>>;
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

void solve()
{
    ll n;
    cin >> n;
    set<ll> s;

    for (int i = 0; i < n; i++)
        s.insert(i + 1);

    ll ans = 0;
    while (!s.empty())
    {
        ll maxi = *(s.rbegin());
        ll bitcnt = log2(maxi) + 1;
        ll high = (1 << bitcnt) - 1;
        print(maxi, high);

        if (maxi != high)
            s.erase(maxi ^ high), s.erase(maxi), ans += (high * 2);
        else
            s.erase(maxi);
    }

    cout << ans << "\n";
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