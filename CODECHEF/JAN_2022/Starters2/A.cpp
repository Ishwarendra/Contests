#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)               \
     for (int _i = (start); _i < (end); _i++) \
          cout << (v[_i]) << " ";             \
     cout << "\n";
#define log(v)                                                 \
     for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
          cout << *(__i) << " ";                               \
     cout << "\n";
#define print(args...)                             \
     {                                             \
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

bool isPowerOfTwo(ll x)
{
     return x && (!(x & (x - 1)));
}

ll highestPowerof2(ll x)
{
     // check for the set bits
     ll ans = 1;
     while(ans <= x)
          ans *= 2;
     if (ans > x)
          ans /= 2;
     return ans;
}

void solve()
{
     ll k;
     cin >> k;
     if (k % 2 == 1)
     {
          cout << "0\n";
          return;
     }

     else
     {
          int ans = 0;
          while (k % 2 == 0)
               k /= 2, ans++;
          cout << ans << "\n";
     }
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