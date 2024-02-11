#include <bits/stdc++.h>
using namespace std;

#define FIO        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
	cout << a << " ";
	err(++it, args...);
};

int max_subarray_sum(vector<int> &arr)
{
	int n = arr.size(), maxsum = INT_MIN, currsum = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		currsum = max(arr[i], currsum + arr[i]);
		maxsum = max(maxsum, currsum);
	}
	return maxsum;
}

void solve()
{
	int n, x; cin >> n >> x;
	
	vi a(n);
	
	for(auto &x: a)
		cin >> x;
	
	int sum = max_subarray_sum(a);
	
	vi dp(n + 1, INT_MIN); // dp[i] length i ke subarray ka max sum
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++)
	{
		int cur = 0;
		for(int j = i; j <= n; j++)
		{
			cur += a[j - 1];
			dp[j - i + 1] = max(cur, dp[j - i + 1]);
		}
	} 
	
	// log(dp);
	
	for(int k = 0; k <= n; k++)
	{
		int cur_ans = 0;
		for(int i = 0; i <= n; i++)
			cur_ans = max(cur_ans, dp[i] + x*min(k, i));
		
		cout << cur_ans << ' ';
	}
	cout << "\n";
}

int32_t main()
{
	FIO;
	int t = 1;
	cin >> t;
	while (t--)
		solve();
}