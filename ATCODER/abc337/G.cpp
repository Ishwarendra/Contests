#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

using namespace __gnu_pbds;

template<typename T, class C = std::less<T>>
using ordered_set = tree<T, null_type, C,
      rb_tree_tag, tree_order_statistics_node_update>; 

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

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    std::vector<i64> inv(n), big(n);
    std::vector<ordered_set<int>> nodes(n);

    auto dfs1 = [&](auto &&self, int u, int p) -> void
    {
        nodes[u].insert(u);
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            self(self, v, u);
            if (std::size(nodes[u]) > std::size(nodes[v]))
                std::swap(nodes[u], nodes[v]);

            for (auto &x : nodes[v])
                nodes[u].insert(x);
            inv[u] += inv[v];
        }

        big[u] = nodes[u].order_of_key(u); 
        inv[u] += big[u];
    }; dfs1(dfs1, 0, 0);

    std::vector<i64> ans(n);

    auto dfs2 = [&](auto &&self, int u, int p) -> void
    {
        ans[u] = inv[u];
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            i64 inv_v = inv[v], inv_u = inv[u];
            i64 big_v = big[v], big_u = big[u];
            auto nv = nodes[v];
            auto nu = nodes[u];

            if (nodes[v].find(v) == nodes[v].end())
                std::swap(nodes[u], nodes[v]);
            else
            {
                for (int x : nodes[v])
                    nodes[u].erase(x);
                for (int x : nodes[u])
                    nodes[v].insert(x);
            }

            inv[u] -= big[u];
            i64 nbig_u = nodes[u].order_of_key(u);
            inv[u] -= inv[v] - nbig_u;

            inv[v] += inv[u];
            inv[v] -= big[v];
            inv[v] += v;

            big[v] = v;
            big[u] = nbig_u;

            self(self, v, u);

            nodes[v] = nv, nodes[u] = nu;
            big[v] = big_v, big[u] = big_u;
            inv[v] = inv_v, inv[u] = inv_u;
        }
    }; dfs2(dfs2, 0, 0);

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
    
    return 0;
}