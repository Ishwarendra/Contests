#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> adj[n];

    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        x--, y--;

        std::string s;
        std::cin >> s;
        int z = (s == "imposter");

        adj[x].emplace_back(y, z);
        adj[y].emplace_back(x, z);
    }

    bool possible = true;
    std::vector<int> color(n, -1);
    std::array<int, 2> cnt{};

    std::function<void(int, int)> dfs = [&](int u, int c)
    {
        color[u] = c;
        cnt[c]++;

        for (auto [v, w] : adj[u])
        {
            if (color[v] == -1)
                dfs(v, c ^ w);
            else if (w != (color[u] ^ color[v]))
                possible = false;
        }
    }; 

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            cnt = {0, 0};
            dfs(i, 0);
            ans += std::max(cnt[0], cnt[1]);
        }
    }

    if (!possible)
        std::cout << "-1\n";
    else
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