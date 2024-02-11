#include "bits/stdc++.h"

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

    int n, q;
    std::cin >> n >> q;

    std::vector<int> deg(n);
    std::vector<std::set<int>> adj(n);
    std::map<int, int> m;
    m[0] = n;
    while (q--)
    {
        int t;
        std::cin >> t;

        if (t == 1)
        {
            int u, v;
            std::cin >> u >> v;
            u--, v--;

            m[deg[u]]--, m[deg[v]]--;
            deg[u]++, deg[v]++;
            m[deg[u]]++, m[deg[v]]++;
            adj[u].emplace(v);
            adj[v].emplace(u);
        }
        else
        {
            int u;
            std::cin >> u;
            u--;

            std::vector<int> rem;
            for (int v : adj[u])
                rem.emplace_back(v);

            for (auto v : rem)
            {
                adj[v].erase(u);
                adj[u].erase(v);

                m[deg[u]]--, m[deg[v]]--;
                deg[u]--, deg[v]--;
                m[deg[u]]++, m[deg[v]]++;
            }
        }
        
        std::cout << m[0] << "\n";
    }

    return 0;
}