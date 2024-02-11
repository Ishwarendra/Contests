#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9 + 1;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector d(n, std::array {inf, inf});
    d[0][0] = 0;

    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);

    while (!q.empty())
    {
        auto [u, par] = q.front();
        q.pop();

        for (auto v : adj[u])
        {
            if (d[v][par ^ 1] != inf)
                continue;

            d[v][par ^ 1] = d[u][par] + 1;
            q.emplace(v, par ^ 1);
        }
    }

    auto good = [&](int mid)
    {
        int par = mid % 2;
        for (int i = 0; i < n; i++)
        {
            if (d[i][par] == inf or d[i][par] > mid)
                return false;
        }

        return true;
    };

    int left = 0, right = 1e7;
    int ans_even = inf;
    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (good(mid * 2))
            ans_even = mid * 2, right = mid - 1;
        else
            left = mid + 1;
    }

    left = 0, right = 1e7;
    int ans_odd = inf;

    while (left <= right)
    {
        int mid = (left + right) >> 1;
        if (good(mid * 2 + 1))
            ans_odd = mid * 2 + 1, right = mid - 1;
        else
            left = mid + 1;
    }

    int ans = std::min(ans_odd, ans_even);
    std::cout << (ans == inf ? -1 : ans) << "\n";
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