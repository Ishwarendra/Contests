#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};
#define int       long long

using vi   =  vector<int>;
using vvi  =  vector<vector<int>>;
using vll  =  vector<long long>;
using vvll =  vector<vector<long long>>;
using ll   =  long long;
using ld   =  long double;
using ull  =  unsigned long long;
using pii  =  pair<int, int>;
using pll  =  pair<long long, long long>;

void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << a << " ";
	err(++it, args...);
};


void solve()
{
	int n; cin >> n;

	vi a(n), b(n);
	
	int s = 0;

	for (auto &x : a) {cin >> x; s += x;};
	for (auto &x : b) {cin >> x; s += x;};

	int sq_sum = 0;

	for (int i = 0; i < n; i++)
		sq_sum += a[i] * a[i] + b[i] * b[i];

	sq_sum *= (n - 2);

	vvi dp(n + 1, vi(s + 1, 0));
	dp[0][0] = 1;
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= s; j++)
		{
			if (dp[i][j])
			{
				if (j + a[i] <= s)
					dp[i + 1][j + a[i]] = 1;
				if (j + b[i] <= s)
					dp[i + 1][j + b[i]] = 1;
			}
		}
	}
	
	int pair_p = 1e9;
	
	for(int i = 0; i <= s; i++)
	{
		if (dp[n][i])
		{
			pair_p = min(pair_p, i*i + (s - i)*(s - i));
			print(pair_p)
		}
	}
	// print(sq_sum, pair_p)
	cout << sq_sum + pair_p <<"\n";
}

int32_t main()
{
	FIO;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}
