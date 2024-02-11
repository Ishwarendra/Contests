#include <bits/stdc++.h>
using namespace std;

#define FIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a) ((a).begin()), ((a).end())
#define printarr(v, start, end)                \
      for (int _i = (start); _i < (end); _i++) \
            cout << (v[_i]) << " ";            \
      cout << "\n";
#define log(v)                                                  \
      for (auto __i = ((v).begin()); __i != ((v).end()); __i++) \
            cout << *(__i) << " ";                              \
      cout << "\n";
#define print(args...)                               \
      {                                              \
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

int setBit(int x, int pos)
{
      return (x | (1 << pos));
}

int dp[1005];
void preprocess()
{
      int pos = 0;
      for(int i = 0; i < (1 << 20); i++)
      {
            if (__builtin_popcount(i) % 2 == 0)
                  dp[pos++] = i;
            if (pos == 1003)
                  return; 
      }
}

void solve()
{
      int n; cin >> n;
      for(int i = 0; i < n; i++)
            cout << dp[i] << " ";
      cout << "\n";
}

int main()
{
      FIO;
      preprocess();
      int t = 1;
      cin >> t;
      while (t--)
            solve();
      return 0;
}