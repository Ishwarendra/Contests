#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

constexpr int inf = 1e9;

void chmin(int &a, int b)
{
    if (a > b)
        a = b;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);

    std::vector dp(n + 1, std::vector(n * n + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        std::vector ndp(n + 1, std::vector(n * n + 1, inf));
        for (int zero = 0; zero <= n; zero++)
        {
            for (int cnt01 = 0; cnt01 <= n * n; cnt01++)
            {
                if (zero + 1 <= n)
                    chmin(ndp[zero + 1][cnt01], dp[zero][cnt01] + (s[i] != '0'));
                if (cnt01 + zero <= n * n)
                    chmin(ndp[zero][cnt01 + zero], dp[zero][cnt01] + (s[i] != '1'));
            }
        }

        std::swap(dp, ndp);
    }

    int zero = std::count(std::begin(s), std::end(s), '0');
    auto ans = dp[zero][zero * (n - zero) / 2];

    std::cout << ans / 2;
    
    return 0;
}