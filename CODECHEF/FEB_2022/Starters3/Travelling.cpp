#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(a)     ((a).begin()), ((a).end())
#define printarr   (v, start, end)for (int _i = (start); _i < (end); _i++) cout << (v[_i]) << " ";cout << "\n";
#define log(v)     for(auto __i = ((v).begin()); __i != ((v).end()); __i++) cout << *(__i) << " "; cout << "\n";
#define int        long long
#define fps(x, y)  fixed<<setprecision((y))<<(x)

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
{in >> a.first >> a.ssecond; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.ssecond; return out;}
void err(istream_iterator<string> it){};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

class DSU
{
    int *par, *rnk;
    int _connected;

public:
    DSU(int n)
    {
        par = new int[n], rnk = new int[n], _connected = n;
        for (int i = 0; i < n; i++)
            par[i] = i, rnk[i] = 1;
    }

    ~DSU()
    {
        delete[] par; delete[] rnk;
    }

    int get(int x)
    {
        if (par[x] == x) return x;
        return par[x] = get(par[x]);
    }

    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p1] > rnk[p2])
                par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;
            else
                par[p1] = p2, rnk[p2] += rnk[p1], rnk[p1] = 0;
                
            _connected--;
            return true;
        }
    }
    
    int connected_comp()
    {
        return _connected;
    }
    
}; 

void solve()
{
	int n, m; cin >> n >> m;
	
	DSU d(n);
	
	for(int i = 0; i < m; i++)
	{
		int u, v; cin >> u >> v;
		u--, v--;
		d.unite(u, v);
	}
	
	vector<vector<int>> adj(n);
	
	for(int i = 0; i < n - 1; i++)
	{
		int p1 = d.get(i), p2 = d.get(i + 1);
		if (p1 != p2)
			adj[p1].push_back(p2),
			adj[p2].push_back(p1);
	}
	
	int root = d.get(0);
	
	queue<int> q;
	q.push(root);
	
	vi dist(n, -1);
	dist[root] = 0;
	
	while(!q.empty())
	{
		int cur_node = q.front();
		q.pop();
		
		for(int nb : adj[cur_node])
		{
			if (dist[nb] == -1)
			{
				dist[nb] = dist[cur_node] + 1;
				q.push(nb);
			}
		}
	}
	
	cout << dist[d.get(n - 1)] << "\n";
}

int32_t main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int t = 1;
	cin >> t;
	
	for(int i = 1; i <= t; i++)
	{
		// cout << "Case #" << i << ": ";
		solve();
	}
	
	return 0;
}