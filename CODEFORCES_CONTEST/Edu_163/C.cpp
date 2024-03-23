#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

std::vector<std::pair<int, int>> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void solve()
{
    const int n = 2;
    int m;
    std::cin >> m;

    std::string s[2];
    std::cin >> s[0] >> s[1];

    auto safe = [&](int i, int j)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    };

    std::vector dp(n, std::vector(m, 0));
    std::queue<std::pair<int, int>> q;
    q.emplace(0, 0);
    dp[0][0] = 1;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : dirs)
        {
            if (!safe(x + dx, y + dy))
                continue;

            int add = s[x + dx][y + dy] == '>' ? 1 : -1;
            if (dp[x + dx][y + dy + add])
                continue;

            q.emplace(x + dx, y + dy + add);
            dp[x + dx][y + dy + add] = 1;
        }
    }

    std::cout << (dp[n - 1][m - 1] ? "YES\n" : "NO\n");
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