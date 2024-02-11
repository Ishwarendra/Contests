#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<int> indeg(n);
    std::vector<std::pair<int, int>> adj[n];
    int can = 1;
    for (int i = 0; i < n; i++)  
    {
        int len;
        std::cin >> len;

        for (int j = 0; j < len; j++)
        {
            int x;
            std::cin >> x;
            x--;
            adj[x].emplace_back(i, x > i);
            indeg[i]++;
        }
    }

    std::vector<int> ans(n, -1);
    std::vector<int> vis(n, 0);
    constexpr int inf = 1e9;
    auto bfs = [&]()
    {
        std::queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indeg[i] == 0)
            {
                ans[i] = 1;
                vis[i] = 1;
                q.emplace(i);
            }
        }

        while (!q.empty())
        {
            auto u = q.front();
            q.pop();

            for (auto [v, w] : adj[u])
            {
                indeg[v]--;
                ans[v] = std::max(ans[v], ans[u] + w);
                if (indeg[v] == 0)
                {
                    vis[v] = 1;
                    q.emplace(v);
                }
            }
        }
    }; bfs();

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            std::cout << "-1\n";
            return;
        }
    }

    std::cout << *std::max_element(std::begin(ans), std::end(ans)) << "\n";
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