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

const ll inf = 1e16;

void solve()
{
    int n; cin >> n;

    pair<ll, ll> low{inf, inf}; // {l, c} simply min ok
    pair<ll, ll> high{-inf, -inf}; // {r, -c} since max r and min cost so -c
    pair<ll, ll> single{-inf, -inf}; // {r - l + 1, -c} since r-l max and min cost so -c

    for(int i = 0; i < n; i++)
    {
        ll l, r, c;
        cin >> l >> r >> c;

        low = min(low, {l, c});
        high = max(high, {r, -c});
        single = max(single, {r - l + 1, -c});

        // 1-segment wins ez
        if (single.first > high.first - low.first + 1)
            cout << (-single.second) << "\n";

        // 1-segment (if both have same int range)
        else if (single.first == high.first - low.first + 1)
            cout << min(-single.second, low.second + (-high.second)) << "\n";
        
        // 2-seg easy win
        else 
            cout << low.second + (-high.second) << "\n";
    }
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}