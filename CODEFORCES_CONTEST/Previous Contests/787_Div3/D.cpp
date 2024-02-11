#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)      ((a).begin()), ((a).end())
#define log(v)      for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int         long long
#define fps(x, y)   fixed<<setprecision((y))<<(x)

#define printarr(v, start, end) for(int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define print(args...){string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);cout<<"\n";};

using ll       =    long long;
using vi       =    vector<int>;
using vvi      =    vector<vector<int>>;
using ld       =    long double;
using pii      =    pair<int, int>;
using mii      =    map<int, int>;
using umii     =    unordered_map<int, int>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using maxheap  =    priority_queue<T>;
template<typename T>
using minheap  =    priority_queue<T, vector<T>, greater<T>>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

constexpr int inf = 7e18;

vi *adj;

void dfs(int cur, vi &vis, vvi &ans, vi &path)
{
	vis[cur] = true;
	// cout << cur << " ";
	path.push_back(cur);
	// log(path)
	bool leaf = true;
	
	for (int nb : adj[cur])
	{
		if (not vis[nb])
			dfs(nb, vis, ans, path);
		
		leaf = false;
	}
	
	if (!path.empty())
		ans.push_back(path);
	
	path.clear();
}

void solve()
{
	int n; cin >> n;
	
	vi p(n), vis(n + 1);
	adj = new vi[n + 1];
	
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	
	int root;
	
	for (int i = 0; i < n; ++i)
	{
		if (i + 1 == p[i])
			root = i + 1;
		else
		{
			adj[i + 1].push_back(p[i]);
			adj[p[i]].push_back(i + 1);
		}
	}
	
	vvi ans;
	vi path;
	
	dfs(root, vis, ans, path);
	
	cout << ans.size() << "\n";
	for (auto i : ans)
	{
		cout << i.size() << "\n";
		log(i);
	}
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	std::cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// std::cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}
/* credits: harasees_singh :maaf_karo:
*think brute force first.
*try proving the algorithm on pen n paper first.
*floating point precision errors ?
*implementation too lengthy ? logic might be incorrect.
*read the question again.
*/