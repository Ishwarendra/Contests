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

vi ans(501), pref(501); 

void preprocess()
{
     ans[0] = 1, pref[1] = 1;
     int cur = 2;
     for (int i = 1; i < 500; i++)
     {
          while (1)
          {
               bool ok = false;
               for (int j = i - 1; j >= 0; j--)
               {
                    int len = i - j + 1;
                    if (((cur + pref[i] - pref[j]) % len) == 0)
                    {
                         ok = true;
                         break;
                    }
               }

               if (ok)
                    cur++;
               else
                    break;

          }
          ans[i] = cur;
          pref[i + 1] = pref[i] + cur;
          cur++;
     }
}

void solve()
{
     int n;
     cin >> n;
     
     for(int i = 0; i < n; i++)
     {
          cout << ans[i] << " ";
     }

    
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