#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    i64 R;
    std::cin >> R;

    int n = std::size(std::to_string(R));

    auto f = [&](i64 x, const int mod) -> i64
    {
        std::vector<int> digits;
        while (x)
        {
            digits.emplace_back(x % 10);
            x /= 10;
        }

        std::reverse(std::begin(digits), std::end(digits));
        std::vector dp(n + 1, std::vector(n * 9 + 10, std::vector(n * 9 + 10, std::array<i64, 2> { 0, 0 })));

        dp[0][0][0][1] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= mod; j++)
            {
                for (int k = 0; k < mod; k++)
                {
                    for (int t = 0; t < 2; t++)
                    {
                        int ub = t ? digits[i] + 1 : 10;
                        for (int dig = 0; dig < ub; dig++)
                        {
                            int modsum = k * 10 + dig;
                            modsum %= mod;
                            int sum = j + dig;

                            if (t and dig == ub - 1)
                                dp[i + 1][sum][modsum][1] += dp[i][j][k][t];
                            else
                                dp[i + 1][sum][modsum][0] += dp[i][j][k][t];
                        }
                    }
                }
            }
        }

        return dp[n][mod][0][1] + dp[n][mod][0][0];
    };

    i64 ans = 0;
    for (int i = 1; i <= n * 9; i++)
        ans += f(R, i);

    std::cout << ans;

    return 0;
}