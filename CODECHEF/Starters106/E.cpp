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

    std::vector<std::vector<int>> adj(n);
    std::vector<int> indeg(n);
    for (int i = 0; i < n - 1; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        indeg[v]++;
    }

    std::queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.emplace(i);
    }

    std::vector<int> siz(n);
    std::function<void(int)> dfs = [&](int u)
    {
        siz[u] = 1;
        for (int v : adj[u])
        {
            dfs(v);
            siz[u] += siz[v];
        }
    }; dfs(q.front());

    std::vector<int> level;
    while (!q.empty())
    {
        int sz = std::size(q);
        level.emplace_back(sz);

        for (int i = 0; i < sz; i++)
        {
            auto u = q.front();
            q.pop();

            for (int v : adj[u])
                q.emplace(v);
        }
    }

    i64 ans = 1;
    std::vector<int> bad(n);
    for (int i = 0; i < n; i++)
        bad[i] = n - siz[i] + 1;

    int id = 0;
    std::sort(std::begin(bad), std::end(bad));
    for (int i = 0; i < n; i++)
    {
        ans += i < std::size(level) ? level[i] : 0;
        std::cout << ans - 1 << " \n"[i == n - 1];

        while (id < n and i + 1 >= bad[id])
            id++, ans--;

        if (id == n)
            ans--;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}