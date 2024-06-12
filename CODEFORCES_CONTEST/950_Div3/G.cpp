#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * If u to v has odd edges include xor of all numbers in type-1
 * else not.
 * Two tries for even and odd depth. 
 * Find the best xor for same depth parity as v with `d[v]`
 * Find the best xor for diff depth parity as v with `d[v] ^ (type1_xors)`
 */

struct TrieNode
{
    TrieNode* next[2];
    int cnt[2];
    TrieNode() 
    { 
        next[0] = next[1] = nullptr; 
        cnt[0] = cnt[1] = 0;
    }  
    bool contains(int x) { return !!next[x]; }
    TrieNode* get(int x) { return next[x]; }
    void put(int x, TrieNode *p) { next[x] = p; }
    void increment(int x) { ++cnt[x]; }
    void decrement(int x) { --cnt[x]; }
    int count(int x) { return cnt[x]; }
};

struct Trie
{
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    int getBit(int x, int pos) { return x >> pos & 1; }
    void insert(int x)  
    {
        TrieNode* node = root;
        for (int i = 30; i >= 0; i--)
        {
            int bit = getBit(x, i);
            if (!node->contains(bit))
                node->put(bit, new TrieNode());
            
            node->increment(bit);
            node = node->get(bit);
        }
    }
    void remove(int x)
    {
        TrieNode* node = root;
        for (int i = 30; i >= 0; i--)
        {
            int bit = getBit(x, i);
            node->decrement(bit);
            node = node->get(bit);
        }
    }
    int maxXor(int x)
    {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 30; i >= 0; i--)   
        {
            int bit = getBit(x, i) ^ 1;
            
            if (node->count(bit))
                ans |= 1 << i;
            else if (node->count(bit ^ 1))
                bit ^= 1;
            else
                return 0;
            
            node = node->get(bit);
        }
        return ans;
    }
};

void solve()
{
    int n, q;
    std::cin >> n >> q;  
    
    Trie trie[2]{};
    std::vector adj(n, std::vector<std::pair<int, int>>());
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        u--, v--;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    
    std::vector dep(n, 1), xr(n, 0);
    auto dfs = [&](auto &&self, int u, int p) -> void
    {
        dep[u] = dep[p] ^ 1;
        for (auto [v, w] : adj[u])
        {
            if (v == p)
                continue;
            
            xr[v] = xr[u] ^ w;
            self(self, v, u);
        }
    }; dfs(dfs, 0, 0);
        
    for (int i = 0; i < n; i++)
        trie[dep[i]].insert(xr[i]);
    
    int tot = 0;
    while (q--)
    {
        char type;
        std::cin >> type;
        
        if (type == '^')
        {
            int x;
            std::cin >> x;
            tot ^= x;
        }
        else
        {
            int u, x;
            std::cin >> u >> x;
            u--;
            
            int xor_ = xr[u] ^ x;
            int ans = trie[dep[u] ^ 1].maxXor(xor_ ^ tot);
            
            trie[dep[u]].remove(xr[u]);
            ans = std::max(ans, trie[dep[u]].maxXor(xor_));
            trie[dep[u]].insert(xr[u]);
            
            std::cout << ans << " \n"[q == 0];
        }
    }
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