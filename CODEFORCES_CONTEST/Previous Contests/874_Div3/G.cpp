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

    std::vector<int> adj[n];
    std::map<std::pair<int, int>, int> m;
    for (int i = 0; i < n - 1; i++)  
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        m[{u, v}] = m[{v, u}] = i + 1;

        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<int> rem;
    std::vector<int> cnt(n, 1);
    std::function<void(int, int)> dfs;
    dfs = [&](int u, int p)
    {
        for (int v : adj[u])
        {
            if (v == p)
                continue;
            dfs(v, u);
            cnt[u] += cnt[v];
        }

        if (cnt[u] == 3)
        {
            cnt[u] = 0;
            if (u != p)
                rem.emplace_back(m[{u, p}]);
        }
    }; dfs(0, 0);

    if (cnt[0])
    {
        std::cout << "-1\n";
        return;
    }

    int sz = std::size(rem);
    std::cout << sz << "\n";
    for (int i = 0; i < sz; i++)
        std::cout << rem[i] << " \n"[i == sz - 1];
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