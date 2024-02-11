#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int N = 1e5 + 5;
constexpr int MOD = 1e9 + 7;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector dp(N, std::array<int, 2>());
    dp[0][0] = 1;
    dp[0][1] = 0;

    for (int i = 0; i < N - 4; i++)
    {
        for (int turn = 0; turn < 2; turn++)
        {
            for (int j = 1; j <= 4; j++)
                dp[i + j][turn] = (dp[i + j][turn] + dp[i][j > 1 ? turn : (turn ^ 1)]) % MOD;
        }
    }

    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int ans = 0;
        for (int i = n - 1; i >= std::max(0, n - 4); i--)
            ans = (ans + dp[i][0]) % MOD;

        std::cout << ans << "\n";
    }
    
    return 0;
}