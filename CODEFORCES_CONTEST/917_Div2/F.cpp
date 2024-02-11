#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 2001;

void solve()
{
    int n, d;
    std::cin >> n >> d;

    std::vector<int> w(n);
    for (int i = 0; i < n; i++)
        std::cin >> w[i];

    std::sort(std::begin(w), std::end(w));
    if (w[n - 1] + w[n - 2] > d)
    {
        std::cout << "No\n";
        return;
    }

    // x and d - x (x >= w[n - 1] and d - x >= w[n - 1])
    std::vector dp(n + 1, std::bitset<N>());
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        dp[i + 1] = dp[i] | (dp[i] << w[i]);

    if (dp[n - 1][d - w[n - 1]])
        std::cout << "Yes\n";
    else if (!dp[n - 1][d])
        std::cout << "No\n";
    else
    {
        // dp[x][y] = 1 => Can choose two subset with sum x and y
        std::vector dp(d + 1, std::bitset<N>());
        dp[0][0] = 1;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = d; j >= 0; j--)
            {
                // dp[j][x] => dp[j + w[i]][x] and dp[j][x + w[i]]
                if (j + w[i] <= d)
                    dp[j + w[i]] |= dp[j];

                dp[j] |= dp[j] << w[i];
            }
        }

        for (int x = w[n - 1]; d - x >= w[n - 1]; x++)
        {
            if (dp[x][d - x])
            {
                std::cout << "Yes\n";
                return;
            }
        }

        std::cout << "No\n";
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