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

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int p;
        std::cin >> p;
        adj[p - 1].emplace_back(i);
    }

    std::vector<int> dep(n);
    auto dfs = [&](auto &&self, int u, int d) -> void
    {   
        dep[u] = d;
        for (int v : adj[u])
            self(self, v, d + 1);
    }; dfs(dfs, 0, 0);

    int max = *std::max_element(std::begin(dep), std::end(dep));
    std::map<int, i64> sum;
    for (int i = 0; i < n; i++)
        sum[dep[i]] += a[i];

    while (max >= 0)
    {
        i64 add = sum[max];
        if (add == 0)
            max--;
        else
        {
            std::cout << (add < 0 ? '-' : '+');
            return 0;
        }
    }

    std::cout << 0;
    
    return 0;
}