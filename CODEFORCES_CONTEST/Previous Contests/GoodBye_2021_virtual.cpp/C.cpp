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

int cur = -1;
int dp[103][202]; // upto i-th index max subset length which are in AP with common diff d

void f(int n, vi &a)
{
    for(int d = -100; d <= 100; d++)   { 
        dp[0][d + 100] = 0;
        dp[1][d + 100] = 1;
        dp[2][d + 100] = (a[1] - a[0] == d ? 2 : 1);
    }

    for(int i = 3; i <= n; i++)
    {
        for(int k = 1; k < i; k++)
        {
            for(int d = -100; d <= 100; d++)
            {
                dp[i][d + 100] = max(dp[i][d + 100], dp[i - k - 1][d + 100] + (a[i - 1] - a[i - k - 1] == d ? 2 : ));
            }
        }
    }
}

void solve()
{
    memset(dp, 0, sizeof dp);
    int n; cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    
    f(n, a);

    int max_len = 0;
    for(int d = -100; d <= 100; d++)
        max_len = max(max_len, dp[n][d + 100]);
    cout << n - max_len << "\n";
    // printarr(dp[3], 100, 110);
}

int main()
{
    FIO;
    int t = 1;
    cin >> t;
    while(t--)
        solve();
}