#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<int> adj[n];
    for (int i = 1; i < n; i++)
    {
        int p;
        std::cin >> p;

        adj[--p].emplace_back(i);
    }

    std::vector<int> dep(n);
    dep[0] = -1;

    std::function<void(int, int)> dfs = [&](int u, int p)
    {
        dep[u] = dep[p] + 1;
        for (int v : adj[u])
            dfs(v, u);
    };
    dfs(0, 0);

    std::cout << dep[n - 1] << "\n";
    
    return 0;
}