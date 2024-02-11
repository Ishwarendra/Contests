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
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

constexpr int INF = 1e18;

void dijkstra(int s, vector<int> & d, vector<int> & p, vector<vector<pii>> &adj) {
	int n = adj.size();
	d.assign(n, INF);
	p.assign(n, -1);
	vector<bool> u(n, false);

	d[s] = 0;
	for (int i = 0; i < n; i++) {
		int v = -1;
		for (int j = 0; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}

		if (d[v] == INF)
			break;

		u[v] = true;
		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
			}
		}
	}
}

void solve()
{
	int n, m; cin >> n >> m;

	vector<vector<pii>> adj(n);

	for (int i = 0; i < m; i++)
	{
		int u, v, c; cin >> u >> v >> c;
		u--, v--;
		adj[u].emplace_back(v, c);
		adj[v].emplace_back(u, c);
	}

	set<pair<int, int>> edges;

	for (int i = 0; i < n; i++)
	{
		vi d, p;
		dijkstra(i, d, p, adj);

		for (int t = 0; t < n; t++)
		{
			if (t == i)
				continue;
			
			for (int v = t; v != i; v = p[v])
				edges.emplace(min(v, p[v]), max(v, p[v]));
		}
	}
	
	cout << m - edges.size() << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// cin >> t;

	for (int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}