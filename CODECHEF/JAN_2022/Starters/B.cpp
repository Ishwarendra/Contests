#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v) for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

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

ll getBit(ll n, ll pos)
{
    if (n == 0)
        return 0;
    return (n & (1 << pos)) != 0;
}

void setBit(ll &n, ll pos)
{
    n = n | (1 << pos);
}

void solve()
{
    ll n; cin >> n;
    vi bit_cnt(50);

    for(ll i = 0; i < n; i++)
    {
        ll x; cin >> x;
        for(ll j = 0; j < 50; j++)
            if (getBit(x, j))
                bit_cnt[j]++;
    }
    
    ll ans = 0;
    for(ll j = 0; j < 50; j++)
    {
        if (bit_cnt[j] >= 2)
            setBit(ans, j);
    }

    cout << ans << "\n";

}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}