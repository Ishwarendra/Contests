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
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    std::vector<int> adj[n], indeg(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        adj[u].emplace_back(v);
        indeg[v]++;
    }

    std::vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int v : adj[u])
            dp[v] = std::max(dp[v], dp[i] + (a[i] > a[v]));
    }

    i64 max = 0;
    for (int i = 0; i < n; i++)
        max = std::max(max, 1LL * k * dp[i] + a[i]);

    std::vector<std::pair<int, int>> nums;
    for (int i = 0; i < n; i++)
    {
        if (!dp[i])
            nums.emplace_back(a[i], i);
    }

    std::vector<int> vis(n);
    std::function<void(int)> dfs = [&](int u)
    {
        vis[u] = 1;
        dp[u]++;

        max = std::max(max, 1LL * k * dp[u] + a[u]);
        for (int v : adj[u])
        {
            if (vis[v])
                continue;

            int x = dp[u] + (a[u] > a[v]);
            if (x > dp[v])
                dfs(v);
        }
    };

    std::sort(std::begin(nums), std::end(nums));

    i64 ans = max - nums[0].first;
    for (int i = 1; i < std::size(nums); i++)
    {
        auto [val, id] = nums[i - 1];
        if (!vis[id])
            dfs(id);

        ans = std::min(ans, max - nums[i].first);
        // print(ans, max, nums[i])
    }

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