#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())

#define printarr(v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

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

vi sum_except_i(vi &a)
{
	vi res(a.size());

	int sum = accumulate(all(a), 0);

	for (int i = 0; i < a.size(); i++)
		res[i] = a[i] * (sum - a[i]);

	return res;
}

// greedy fail try dp

void solve()
{
	int n; cin >> n;

	vi a(n), b(n);
	
	int s1 = 0, s2 = 0;
	
	for (int i = 0; i < n; i++)
		cin >> a[i], s1 += a[i];

	for (int i = 0; i < n; i++)
		cin >> b[i], s2 += b[i];
	
	// (ai^2 + aj^2 + bi^2 + bj^2) + 2*(ai aj + bi bj)
	// First term
	
	int sq_sum = 0;
	for(int i = 0; i < n; i++)
	{
		sq_sum += (a[i]*a[i] + b[i]*b[i]);
	}
	
	// Second term
	// dp[i][j] is true when you can make sum j with first i elements.
	vvi dp(n + 1, vi(s1 + s2 + 1));
	dp[0][0] = 1; // 0 item 0 sum :check:
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j <= s1 + s2; j++)
		{
			if (j - a[i] >= 0)
				dp[i][j] = dp[i][j] | dp[i - 1][j - a[i - 1]];
			if (j - b[i] >= 0)
				dp[i][j] = dp[i][j] | dp[i - 1][j - b[i - 1]];
		}
	}
	
	
	// pair Product time 
	// 2*sum(ai*aj) = a[i] * (sum of all ele except a[i]) + ... 
	// a[i] * (s1 - a[i]) + ....
	// s1 * (sum(a)) - a[i]*a[i] - ....;
	int pair_p = 1e9;
	for(int sum = 0; sum <= (s1 + s2); sum++)
	{
		if (dp[n][sum])
		{
			// print(sum);
			if (pair_p > sum*sum + (s1 + s2 - sum)*(s1 + s2 - sum))
				pair_p = sum*sum + (s1 + s2 - sum)*(s1 + s2 - sum);
			print(pair_p)
		}
	}
	
	
	// Final answer -> (n - 1)*sq_sum + s1^2 + s2^2 - sq_sum
	cout << (n - 2)*sq_sum + pair_p << "\n"; 
}

/* 13 
14 
15 
16 
17 
18 
19 
20 
21 */

int main()
{
	FIO;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}