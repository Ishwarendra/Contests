#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
    {
        std::cin >> a[i];
        a[i]--;
    }

    std::vector<int> adj[n];
    for (int i = 0; i < n; i++)
        adj[i].push_back(a[i]);

    std::function<void(int, int)> dfs;
    std::vector<int> path, vis(n);
    dfs = [&](int u, int p)
    {
        vis[u] = 1;
        path.push_back(u);
        for (int v : adj[u])
        {
            if (not vis[v])
                dfs(v, u);
        }
    };   

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (not vis[i])
        {
            path.clear();
            dfs(i, -1);

            int m = std::size(path);
            for (int i = 0; i < m - 1; i++)
                ans = std::gcd(ans, std::abs(path[i] - path[i + 1]));
        }
    }

    std::cout << ans << "\n";
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