#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    auto good = [&](int mid)
    {
        auto dfs = [&](auto &&self, int u, int p) -> std::pair<int, int>
        {
            int tot = 1, ans = 0;
            for (int v : adj[u])
            {
                if (v == p)
                    continue;

                auto [cnt, sum] = self(self, v, u);
                ans += cnt;
                tot += sum;
            }

            if (tot >= mid and p != u)
                tot = 0, ans++;
            else if (p == u and tot < mid)
                ans--;

            return { ans, tot };
        };

        auto [ans, tot] = dfs(dfs, 0, 0);
        return ans >= k;
    };

    int left = 1, right = n;
    int ans = 0;
    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (good(mid))
            ans = mid, left = mid + 1;
        else
            right = mid - 1;
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