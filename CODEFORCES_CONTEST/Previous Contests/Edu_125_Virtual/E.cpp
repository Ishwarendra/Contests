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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> adj[n];
    std::vector<int> p(n), outdeg(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        
        adj[--v].emplace_back(--u);
        outdeg[u]++;
    }

    int cur = n;
    std::priority_queue<int> q;
    for (int i = n - 1; i >= 0; i--)
    {
        if (outdeg[i] == 0)
            q.emplace(i);
    }

    while (!q.empty())
    {
        auto v = q.top();
        q.pop();
        p[v] = cur--;
        for (auto u : adj[v])
        {
            outdeg[u]--;
            if (outdeg[u] == 0)
                q.emplace(u);
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << p[i] << " \n"[i == n - 1];
    
    return 0;
}