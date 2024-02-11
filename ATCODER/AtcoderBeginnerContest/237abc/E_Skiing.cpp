#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)     ((a).begin()), ((a).end())
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
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
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

constexpr int inf = 1e18;

vi *adj, dp;

void bfs(int cur, int n, vi &h)
{
	vector<int> vis(n + 1);
	
	queue<int> q;
	q.push(cur);
	vis[cur] = true;
	
	while (!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		
		vis[cur_node] = true;
				
		for(int nb : adj[cur_node])
		{
			if (not vis[nb])
			{
				// update dp[nb]
				if (h[cur_node] > h[nb])
					dp[nb] = max(dp[nb], dp[cur_node] + h[cur_node] - h[nb]);
				else
					dp[nb] = max(dp[nb], dp[cur_node] - 2 * (h[nb] - h[cur_node])); 
				
				q.push(nb);
			}
		}
	}
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	
	adj = new vi[n + 1];
	dp.resize(n + 1, -inf);
		
	dp[1] = 0;
	
	vi h(n + 1);
	
	for(int i = 1; i <= n; i++)
		std::cin >> h[i];
	
	while(m--)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	bfs(1, n, h);
	
	int maxi = *std::max_element(all(dp));
	
	cout << maxi << "\n";
	
	return 0;
}