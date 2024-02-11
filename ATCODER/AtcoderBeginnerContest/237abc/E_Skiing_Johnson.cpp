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
template<typename T>
using minheap  =    priority_queue<T, vector<T>, greater<T>>;
using pbds     =    tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T1, typename T2> istream &operator >> (istream& in, pair<T1, T2> &a)
{in >> a.first >> a.second; return in;}
template<typename T1, typename T2> ostream &operator << (ostream& out, pair<T1, T2> &a)
{out << a.first << " " << a.second; return out;}
void err(istream_iterator<string> it) {};
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{cout << a << " "; err(++it, args...);};

constexpr int inf = 1e18;

vi *adj, dp, vis;

void bfs(int cur, vi &h)
{
    minheap<pii> q;

    q.push({0, cur});

    while (!q.empty())
    {
        pii cur_node = q.top();
        q.pop();
        
        // print(cur_node);

        int node = cur_node.second, wt = cur_node.first;

        if (vis[node])
            continue;

        dp[node] = wt;
        vis[node] = true;

        for (int nb : adj[node])
        {
            int dist;
            if (h[node] >= h[nb])
                dist = 0;
            else
                dist = h[nb] - h[node];
            
            // print(node, nb, dist);
            
            q.push({dp[node] + dist, nb});
        }
    }
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vi h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    adj = new vi[n + 1];
    dp.resize(n + 1, -1);
    vis.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // w'(1, v) = w(1, v) + p(1) - p(v) here p = h
    // w(1, v) = w'(1, v) - p(1) + p(v) // negate this now to get longest path
    
    int ans = 0;

    bfs(1, h);

    // log(dp);

    for (int i = 1; i <= n; i++)
        ans = max(ans, h[1] - h[i] - dp[i]);

    cout << ans << "\n";

    return 0;
}