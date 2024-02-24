#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++)  
    {
        int p;
        std::cin >> p;
        p--;
        adj[i].emplace_back(p);
        adj[p].emplace_back(i);
    }

    std::string s;
    std::cin >> s;

    std::vector dp(n, std::array<i64, 2> { -1, -1 });
    auto dfs = [&](auto &&self, int u, int p, int noisy) -> i64
    {
        if (dp[u][noisy] != -1)
            return dp[u][noisy];

        i64 ans = 0;
        for (int v : adj[u])
        {
            if (v == p)
                continue;

            if (noisy)
            {
                if (s[v] == 'S')
                    ans += self(self, v, u, 0) + 1;
                else if (s[v] == 'P')
                    ans += self(self, v, u, 1);
                else
                    ans += std::min(self(self, v, u, 0) + 1, self(self, v, u, 1));
            }
            else
            {
                if (s[v] == 'S')
                    ans += self(self, v, u, 0);
                else if (s[v] == 'P')
                    ans += self(self, v, u, 1) + 1;
                else
                    ans += std::min(self(self, v, u, 0), self(self, v, u, 1) + 1);
            }
        }

        dp[u][noisy] = ans;
        return dp[u][noisy];
    };

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'P')
        {
            std::cout << dfs(dfs, i, i, 1) << "\n";
            return;
        }
    }

    std::cout << "0\n";
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