#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * tree hashing:
 * Form a tree from the given sequence (Each walk from a node represent a RBS)
 * If we fix starting edge then our walk is a good bracket sequences
 * Count the number of identical subtrees at each level
 */

void solve()
{
    int n;
    std::string s;
    std::cin >> n >> s;  
    
    std::map<std::vector<int>, int> vals;
    int num = 0;
    
    std::vector<std::vector<int>> adj(n / 2 + 1);
    std::vector<int> hash(n / 2 + 1);
    std::vector<int> par(n);
    int sz = 1, cur = 0;
    
    for (auto ch : s)
    {
        if (ch == ')')
            cur = par[cur];
        else
        {
            adj[cur].emplace_back(sz);
            par[sz] = cur;
            cur = sz;
            sz++;
        }
    }
    
    auto dfs = [&](auto &&self, int u) -> void
    {
        std::vector<int> nodes;
        for (int v : adj[u])  
        {
            self(self, v);
            nodes.emplace_back(hash[v]);
        }
        
        if (!vals.count(nodes))
            vals[nodes] = std::size(vals);
        
        hash[u] = vals[nodes];
    }; dfs(dfs, 0);
    
    i64 ans = 0;
    std::map<int, int> cnt;
    for (auto h : hash)
        cnt[h]++;
    
    for (auto &[p, f] : cnt)
        ans += f * (f - 1LL) / 2;

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