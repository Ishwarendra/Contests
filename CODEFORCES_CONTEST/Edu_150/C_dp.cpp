#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr i64 inf = 1e18;
int pw[5] {1, 10, 100, 1000, 10000};

void chkmax(i64 &a, i64 b)
{
    if (a < b)
        a = b;
}

int add(int ch, int max)
{
    if (max > ch)
        return -pw[ch];
    return pw[ch];
}

void solve()
{
    std::string s;
    std::cin >> s;

    std::vector dp(5, std::array { -inf, -inf});
    dp[0][0] = 0;

    for (int i = std::ssize(s) - 1; i >= 0; i--)
    {
        std::vector ndp(5, std::array { -inf, -inf});
        int ch = s[i] - 'A';
        for (int m = 0; m < 5; m++)
        {
            chkmax(ndp[std::max(m, ch)][1], dp[m][1] + add(ch, m));
            chkmax(ndp[std::max(m, ch)][0], dp[m][0] + add(ch, m));

            for (int m2 = 0; m2 < 5; m2++)
                chkmax(ndp[std::max(m, m2)][1], dp[m][0] + add(m2, m));
        }

        std::swap(dp, ndp);
    }

    i64 ans = -inf;
    for (int i = 0; i < 5; i++)
        chkmax(ans, std::max(dp[i][1], dp[i][0]));

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