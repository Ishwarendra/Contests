#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

class Solution 
{
public:
    i64 countPalindromePaths(std::vector<int>& parent, std::string s) 
    {
        std::map<int, i64> dp;
        int n = std::size(parent);

        std::vector<std::vector<int>> adj(n);
        for (int i = 1; i < n; i++)
            adj[parent[i]].emplace_back(i);

        i64 ans = 0;
        auto dfs = [&](auto self, int u, int mask) -> void
        {
            ans += dp[mask];
            for (int i = 0; i < 26; i++)
                ans += dp[mask ^ (1 << i)];

            dp[mask]++;
            for (int v : adj[u])
                self(self, v, mask ^ (1 << (s[v] - 'a')));
        }; dfs(dfs, 0, 0);

        return ans;
    }
};

int main()
{
    return 0; 
}    