#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;

void chmax(i64 &a, i64 b)
{
    if (a < b)
        a = b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, k;
    std::cin >> n >> k;

    std::vector<std::pair<int, int>> a(n);
    for (auto &[c, v] : a)
        std::cin >> c >> v;

    int col = a[0].first;
    std::vector<std::pair<i64, i64>> b(1);
    int rem = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        auto [c, v] = a[i];
        if (c == col)
        {
            b.back().first = col;
            chmax(b.back().second, v);
            cnt++;
        }
        else
        {
            b.emplace_back(c, v);
            col = c;
            rem += cnt - 1;
            cnt = 1;
        }
    }

    rem += std::max(0, cnt - 1);

    if (rem > k)
    {
        std::cout << -1;
        return 0;
    }

    if (rem == k)
    {
        i64 ans = 0;
        for (auto &[c, max] : b)
            ans += max;
        std::cout << ans;
        return 0;
    }

    k -= rem;
    n = std::size(b);
    std::vector dp(n, std::vector<i64>(k + 1, -inf));
    dp[0][0] = b[0].second;
    dp[0][1] = 0;

    std::set<std::pair<i64, int>> max;
    max.emplace(dp[0][1], b[0].second);
    max.emplace(-inf, -1);
    for (int i = 1; i < n; i++)
    {
        auto &[c, v] = b[i];
        std::set<std::pair<i64, int>> nmax;
        chmax(dp[i][0], dp[i - 1][0] + b[i].second);

        for (int x = 1; x <= k; x++)
        {
            chmax(dp[i][x], dp[i - 1][x - 1]);

            auto it = std::begin(max);
            if (it->second == c)
                it = std::next(it);

            if (it->first != -inf)
                chmax(dp[i][x], it->first + b[i].second);

            nmax.emplace(it->first + b[i].second, it->second);
            max.erase(it);
        }

        std::swap(max, nmax);
    }

    std::cout << (dp[n - 1][k] < 0 ? -1 : dp[n - 1][k]);

    return 0;
}