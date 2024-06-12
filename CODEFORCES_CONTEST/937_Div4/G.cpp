#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::map<std::string, int> singer, genre;
    std::vector<std::pair<int, int>> a;

    int sid = 0, gid = 0;
    for (int i = 0; i < n; i++)
    {
        std::string g, s;
        std::cin >> g >> s;

        if (!singer.contains(s))
            singer[s] = sid++;
        if (!genre.contains(g))
            genre[g] = gid++;

        a.emplace_back(singer[s], genre[g]);
    }

    const int m = 1 << n;

    auto chmin = [&](int &x, int y)
    {
        if (x > y)
            x = y;
    };  

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };

    std::vector dp(n, std::vector(m, n));
    for (int i = 0; i < n; i++)
        dp[i][1 << i] = 0;

    for (int mask = 0; mask < m; mask++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int last = 0; last < n; last++)
            {
                auto [sl, gl] = a[last];
                auto [si, gi] = a[i];

                if (getBit(mask, i) || !getBit(mask, last))
                    continue;

                if (sl == si || gl == gi)
                {
                    chmin(dp[i][mask | (1 << i)], dp[last][mask]);
                }

                chmin(dp[last][mask | (1 << i)], dp[last][mask] + 1);
            }
        }
    }

    int ans = n;
    for (int i = 0; i < n; i++)
        chmin(ans, dp[i][m - 1]);

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