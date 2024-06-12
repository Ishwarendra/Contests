#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, p, k;
    std::cin >> n >> p >> k;

    std::vector a(n, 0);
    std::vector s(n, std::vector(p, 0));
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
            std::cin >> s[i][j];
    }

    std::vector<int> ord(n);
    std::iota(std::begin(ord), std::end(ord), 0);
    std::sort(std::begin(ord), std::end(ord),
        [&](const int &i, wakaconst int &j)
        {
            return a[i] > a[j];
        });

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    auto chmax = [&](auto &x, auto y) 
    {
        if (x < y)
            x = y;
    };

    std::vector dp(1 << p, -inf);
    dp[0] = 0;

    for (int cnt = 0; int i : ord)
    {
        std::vector ndp(1 << p, -inf);
        cnt++;
        for (int mask = 0; mask < (1 << p); mask++)
        {
            if (dp[mask] == -inf)
                continue;

            int canTake = (cnt - __builtin_popcount(mask)) <= k;
            chmax(ndp[mask], dp[mask] + a[i] * canTake);

            for (int pos = 0; pos < p; pos++)
            {
                if (!getBit(mask, pos))
                    chmax(ndp[mask | (1 << pos)], dp[mask] + s[i][pos]);
            }
        }

        dp = std::move(ndp);
    }

    std::cout << dp.back();
    
    return 0;
}