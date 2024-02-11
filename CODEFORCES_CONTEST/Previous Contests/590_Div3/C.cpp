#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::vector<std::string> a(2);
    std::cin >> n >> a[0] >> a[1];

    for (int i = 0; i < 2; i++)
    {
        for (auto &ch : a[i])
        {
            if (ch <= '2')
                ch = '0';
            else
                ch = '1';
        }
    }

    std::vector dp(2, std::vector<int>(n + 2));
    dp[0][0] = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 2; i++)
        {
            if (!dp[i][j])
                continue;

            if (a[i][j] == '0')
                dp[i][j + 1] = 1;
            else if (a[i][j] == '1' and a[i ^ 1][j] == '1')
                dp[i ^ 1][j + 1] = 1;
        }
    }
    
    std::cout << (dp[1][n] ? "YES\n" : "NO\n");
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;

    while (t--)
        solve();

    return 0;
}