#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, a, b, da, db;
    std::cin >> n >> a >> b >> da >> db;

    std::vector<int> adj[n];
    a--, b--;

    for (int i = 0; i < n - 1; ++i)  
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    auto bfs = [&](int u)
    {
        std::queue<std::pair<int, int>> q;
        q.emplace(u, 0);
        std::vector<int> d(n, - 1);
        d[u] = 0;

        while (!q.empty())
        {
            auto [node, _] = q.front();
            q.pop();

            for (int v : adj[node])
            {
                if (d[v] == -1)
                {
                    d[v] = d[node] + 1;
                    q.emplace(v, d[v]);
                }
            }
        }

        return d;
    };

    auto fa = bfs(a);
    auto fb = bfs(b);

    int max_fa = 0; // node at max distance from alice
    for (int i = 1; i < n; i++)
        if (fa[max_fa] < fa[i])
            max_fa = i;

    auto fmax_fa = bfs(max_fa);
    int di = *std::max_element(std::begin(fmax_fa), std::end(fmax_fa)); 
    std::string alice = "Alice", bob = "Bob";
    // print(fa, fb, max_fa, di)

    // alice can one jump or two jump bob 
    if (fa[b] <= da or 2 * da >= di or db <= 2 * da)
        std::cout << alice << "\n";
    else
    {
        std::cout << bob << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}