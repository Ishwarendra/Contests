#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

class DSU
{
    std::vector<int> rnk, par;
public:
    DSU(int n) : rnk(n, 1), par(n) { std::iota(par.begin(), par.end(), 0); }
    int get(int x)
    {
        while (x != par[x]) x = par[x] = par[par[x]];
        return x;
    }
    bool unite(int x, int y)
    {
        int p1 = get(x), p2 = get(y);
        if (p1 == p2)
            return false;
        else
        {
            if (rnk[p2] > rnk[p1])
                std::swap(p1, p2);
                
            par[p2] = p1, rnk[p1] += rnk[p2], rnk[p2] = 0;                
            return true;
        }
    }
    bool same(int x, int y)
    {
        return get(x) == get(y);
    }
    int size(int x)
    {
        return rnk[get(x)];
    }
}; 

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> indeg(n), outdeg(n);
    std::vector<int> adj[n];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        u--, v--;

        indeg[v]++;
        outdeg[u]++;
        adj[u].emplace_back(v);
    }

    std::set<std::pair<int, int>> q;
    for (int i = 0; i < n; i++)
        q.emplace(indeg[i], i);

    int ele = 1;
    std::vector<int> a(n);

    while (!q.empty())
    {
        auto cur = *std::begin(q);
        q.erase(std::begin(q));

        if (!q.empty())
        {
            if (std::begin(q)->first == cur.first)
            {
                std::cout << "No\n";
                std::exit(0);
            }
        }

        a[cur.second] = ele++;

        for (auto v : adj[cur.second])
        {
            auto it = q.find({indeg[v], v});
            q.erase(it);
            indeg[v]--;
            q.emplace(indeg[v], v);
        }
    }

    std::cout << "Yes\n";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];

    return 0;
}