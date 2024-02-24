#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> col(n);
    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        col[c - 1].emplace_back(i);
    }

    std::vector<std::vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    const int m = std::__lg(n) + 2;
    std::vector dp(n, std::vector(m, 0));
    std::vector tout(n, 0), tin(n, 0);
    int dfs_time = 0;

    auto dfs1 = [&](auto &&self, int u, int p) -> void
    {
        tin[u] = dfs_time++;
        dp[u][0] = p;
        for (int v : g[u])
        {
            if (v != p)
                self(self, v, u);
        }
        tout[u] = dfs_time;
    }; dfs1(dfs1, 0, 0);

    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }

    auto isAncestor = [&](int u, int v)
    {
        return tin[u] <= tin[v] and tout[v] <= tout[u];
    };

    auto lca = [&](int u, int v)
    {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;

        for (int i = m - 1; i >= 0; i--)
        {
            if (!isAncestor(dp[u][i], v))
                u = dp[u][i];
        }

        return dp[u][0];
    };

    auto cmp = [&](int u, int v) { return tin[u] < tin[v]; };

    i64 ans = 0;
    for (int c = 0; c < n; c++)
    {
        if (std::size(col[c]) <= 1)
            continue;

        std::vector<int> nodes;
        for (int u : col[c])
            nodes.emplace_back(u);

        std::sort(std::begin(nodes), std::end(nodes), cmp);
        int sz = std::size(nodes);
        for (int i = 1; i < sz; i++)
            nodes.emplace_back(lca(nodes[i], nodes[i - 1]));

        std::sort(std::begin(nodes), std::end(nodes), cmp);
        nodes.erase(std::unique(std::begin(nodes), std::end(nodes)), std::end(nodes));

        std::stack<int> st;
        std::map<int, std::vector<int>> adj;

        for (int i = 0; i < std::size(nodes); i++)
        {
            while (std::size(st) > 1 and !isAncestor(st.top(), nodes[i]))
            {
                int f = st.top();
                st.pop();
                adj[st.top()].emplace_back(f);
                adj[f].emplace_back(st.top());
            }

            st.emplace(nodes[i]);
        }

        while (std::size(st) > 1)
        {
            int f = st.top();
            st.pop();
            adj[st.top()].emplace_back(f);
            adj[f].emplace_back(st.top());
        }

        assert(!st.empty());
        int root = st.top();

        std::map<int, i64> sq_sum, sum, cnt;
        auto dfs2 = [&](auto &&self, int u, int p) -> void
        {
            for (int v : adj[u])
            {
                if (v == p)
                    continue;

                self(self, v, u);
                sum[u] += cnt[v];
                sq_sum[u] += 1LL * sum[v] * sum[v];
            }

            if (std::binary_search(std::begin(col[c]), std::end(col[c]), u))
            {
                cnt[u] = 1;
                ans += sum[u];
            }
            else
            {
                cnt[u] = sum[u];
                i64 cnt_sum = 0, sq_sum_cnt = 0;
                for (int v : adj[u])
                {
                    cnt_sum += cnt[v];
                    sq_sum_cnt += cnt[v] * cnt[v];
                }

                // print(cnt_sum, sq_sum)
                ans += (cnt_sum * cnt_sum - sq_sum_cnt) / 2;
            }
        }; dfs2(dfs2, root, root);
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