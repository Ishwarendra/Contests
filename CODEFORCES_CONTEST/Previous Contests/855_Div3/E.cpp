#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::string s, t;
    std::cin >> n >> k >> s >> t;

    std::vector<int> adj[n];

    for (int i = 0; i < n; i++)
    {
        if (i + k < n)
        {
            adj[i + k].emplace_back(i);
            adj[i].emplace_back(i + k);
        }
        if (i + k + 1 < n)
        {
            adj[i + k + 1].emplace_back(i);
            adj[i].emplace_back(i + k + 1);
        }
    }

    std::vector<std::vector<int>> ans;
    std::vector<int> vis(n);

    std::function<void(int)> dfs = [&](int u)
    {
        vis[u] = 1;
        ans.back().emplace_back(u);
        for (int v : adj[u])
        {
            if (!vis[v])
                dfs(v);
        }
    };

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            ans.emplace_back();
            dfs(i);
        }
    }

    for (auto id : ans)
    {
        std::array<int, 26> cnts{}, cntt{};

        for (auto x : id)
            cnts[s[x] - 'a']++, cntt[t[x] - 'a']++;

        if (cnts != cntt)
        {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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