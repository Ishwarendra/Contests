#include <bits/stdc++.h>

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
    
    int n, s;
    std::cin >> n >> s;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i] >> b[i];

    constexpr int N = 1e4 + 1;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(N));
    std::vector<std::vector<int>> choice(n + 1, std::vector<int>(N, -1));
    dp[0][0] = 1;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dp[j - 1][i])
            {
                if (i + a[j] < N)
                {
                    dp[j][i + a[j - 1]] = 1;
                    choice[j][i + a[j - 1]] = 0;
                }
                if (i + b[j] < N)
                {
                    dp[j][i + b[j - 1]] = 1;
                    choice[j][i + b[j - 1]] = 1;
                }
            }
        }
    }

    if (!dp[n][s])
    {
        std::cout << "No\n";
        std::exit(0);
    }

    int pos = n;
    std::string ans;
    while (s)
    {
        if (choice[pos][s] == 0)
        {
            ans += 'H';
            s -= a[pos - 1];
        }
        else
        {
            ans += 'T';
            s -= b[pos - 1];
        }

        pos--;
    }

    std::reverse(std::begin(ans), std::end(ans));
    std::cout << "Yes\n" << ans;
    
    return 0;
}