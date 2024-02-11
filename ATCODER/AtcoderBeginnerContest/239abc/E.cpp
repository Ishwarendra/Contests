#include <bits/stdc++.h>
using namespace std;

#define FIO       ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
#define all(a)    ((a).begin()), ((a).end())
#define printarr  (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)    for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int       long long
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using maxheap  =    priority_queue<int>;
using minheap  =    priority_queue<int, vector<int>, greater<int>>;

void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cout << a << " ";
    err(++it, args...);
};

vi *adj;
int n, q;
vi val;

vvi dp;

void dfs(int cur, int par)
{
	dp[cur].push_back(val[cur]);
	for(int nb : adj[cur])
	{
		if (nb != par)
		{
			dfs(nb, cur);
			
			// sort(all(dp[nb]), greater<int>());
			int nb_sz = dp[nb].size();
			
			for(int i = 0; i < min(20LL, nb_sz); i++)
				dp[cur].push_back(dp[nb][i]);
		}
	}
	
	sort(all(dp[cur]), greater<int>());
	dp[cur].resize(min(20LL, (int)dp[cur].size()));
}

void solve()
{
	int v, k;
	cin >> v >> k;
	
	cout << dp[v][k - 1] << "\n";
}

int32_t main()
{
    FIO;
    cin >> n >> q;
	
	adj = new vi[n + 1];
	val.resize(n + 1);
	dp.resize(n + 1);
	
	for(int i = 1; i <= n; i++)
		cin >> val[i];
	
	for(int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, 0);
	
	// // for(auto &i : dp)
	// // 	sort(all(i), greater<int>());
	
	// for(auto i : dp)
	// {
	// 	for (auto j : i)
	// 		cout << j << " ";
	// cout << "\n";
	// }
	
	while(q--)
		solve();
}