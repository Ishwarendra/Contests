#include <bits/stdc++.h>

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

    std::vector<int> par(n), c(n);
    std::vector<int> adj[n];
    int root = -1;

    for (int i = 0; i < n; i++)
    {
        std::cin >> par[i] >> c[i];
        if (par[i] == -1)
            root = i, par[i] = i;
        else
        {
            par[i]--;
            adj[par[i]].push_back(i);
        }
    }

    assert(root != -1); 
    std::set<int> del;

    std::function<void(int)> check = [&](int u)
    {
        int children = 0, ances = 1;
        for (int v : adj[u])
        {
            if (c[v] == 0)
                children = 1;
        }

        if (u != par[u] and c[u])
            ances = 0;

        if (!ances and !children)
            del.emplace(u);
    };

    for (int i = 0; i < n; ++i)
        check(i);

    for (int i : del)
        std::cout << i + 1 << " ";

    if (del.empty())
        std::cout << "-1\n";
    
    return 0;
}