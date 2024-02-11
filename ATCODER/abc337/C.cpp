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

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;

        if (a == -1)
            root = i;
        else
            adj[a - 1].emplace_back(i);
    }

    auto dfs = [&](auto && self, int u)-> void
    {
        std::cout << u + 1 << " ";
        for (int v : adj[u])
            self(self, v);
    }; dfs(dfs, root);

    return 0;
}