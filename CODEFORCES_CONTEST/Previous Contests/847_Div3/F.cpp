#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> c(n);
    std::cin >> c[0];
    c[0]--;

    for (int i = 1; i < n; i++)
    {
        std::cin >> c[i];
        c[i]--;
    }

    std::vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;

        adj[--u].emplace_back(--v);
        adj[v].emplace_back(u);
    }

    std::vector<int> dist(n, inf);
    int ans = n + 1;
    
    for (int i = 0; i < n; i++)
    {
        std::queue<int> q;
        q.emplace(c[i]);
        ans = std::min(ans, dist[c[i]]);
        dist[c[i]] = 0;

        if (i)
            std::cout << ans << " ";

        bool enter = true;
        while (!q.empty() and enter)
        {
            auto u = q.front();
            q.pop();
            enter = true;

            for (int v : adj[u])
            {
                if (dist[v] > dist[u] + 1)
                {
                    dist[v] = dist[u] + 1;
                    q.emplace(v);
                    if (dist[v] > ans)
                    {
                        enter = false;
                        break;
                    }
                }
            }
        }
    }

    std::cout << "\n";
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