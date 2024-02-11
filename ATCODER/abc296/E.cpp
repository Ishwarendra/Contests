#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    std::vector<std::vector<int>> adj(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        adj[i].emplace_back(--a[i]);
    }

    std::vector<int> vis(n);
    std::multiset<int> stack;
    int cycle = -1;

    std::function<void(int)> dfs;
    dfs = [&](int u)
    {
        vis[u] = 1;
        stack.emplace(u);

        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v);
            else
            {
                if (stack.count(v))
                    cycle = v;
            }
        }

        stack.erase(stack.find(u));
    };

    std::set<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cycle = -1;
            dfs(i);
            int u = cycle;
            while (u != -1 and !s.count(u))
            {
                s.emplace(u);
                u = adj[u][0];
            }
        }
    }
 
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += s.count(i);
 
    std::cout << ans;


    return 0;
}