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
    std::string s;
    std::cin >> n >> s;

    std::array<int, 2> adj[n];
    for (int i = 0; i < n; i++)  
    {
        std::cin >> adj[i][0] >> adj[i][1];
        adj[i][0]--, adj[i][1]--;
    }

    std::function<std::pair<int, int>(int)> dfs;
    dfs = [&](int u) -> std::pair<int, int>
    {
        if (adj[u] == std::array{-1, -1})
            return std::pair {0, 0};

        std::pair ans {inf, inf};
        for (int id = 0; id < 2; id++)
        {
            if (adj[u][id] == -1)
                continue;

            auto [l, r] = dfs(adj[u][id]);
            int his = std::min(l, r);
            char ch = s[u];
            if (ch == 'L')
                ans.first = std::min({ans.first, his + (id == 1)});
            if (ch == 'R')
                ans.second = std::min({ans.second, his + (id == 0)});
            if (ch == 'U')
            {
                ans.first = std::min(ans.first, his + 1);
                ans.second = std::min(ans.second, his + 1);
            }
        }

        return ans;
    };

    auto [l, r] = dfs(0);
    int ans = std::min(l, r);
    std::cout << ans << "\n";
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