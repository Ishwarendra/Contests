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

void solve()
{
      int n; cin >> n;
      string a, b;
      cin >> a >> b;
      
      vi pa(n + 1), pb(n + 1);
      pa[0] = (a[0] == '1');
      pb[0] = (b[0] == '1');
      for(int i = 1; i < n; i++)
      {
            pa[i] = pa[i - 1] + (a[i] == '1');
            pb[i] = pb[i - 1] + (b[i] == '1');
      }

      vector<vi> dp(n + 1, vi(n + 1, INT_MAX));

      // Base Cases
      dp[0][0] = 0;
      for(int i = 1; i <= n; i++)
      {
            dp[0][i] = dp[0][i - 1] + (b[i - 1] == '0' ? pb[i - 1] : 0);
            dp[i][0] = dp[i - 1][0] + (a[i - 1] == '0' ? pa[i - 1] : 0);
      }

      for(int i = 1; i <= n; i++)
      {
            for(int j = 1; j <= n; j++)
            {
                  // check a
                  if (a[i - 1] == '1')
                        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
                  else
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + pa[i - 2] + pb[j - 1]);

                  // Check-b
                  if (b[j - 1] == '1')
                        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
                  else
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + pa[i - 1] + pb[j - 2]);       
            }
      }

      cout << dp[n][n] << "\n";
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