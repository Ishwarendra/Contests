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
    
    std::string s;
    std::cin >> s;

    int n = std::size(s);

    std::vector dp(n, std::array<int, 26>{});
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];
        dp[i][ch - 'a']++;

        if (i)
        {
            for (int j = 0; j < 26; j++)
                dp[i][j] += dp[i - 1][j];
        }
    }

    int q;
    std::cin >> q;

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        r--, l--;

        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            int have = dp[r][i] - (l == 0 ? 0 : dp[l - 1][i]);
            count += have > 0;
        }
        
        std::cout << (count > 2 or s[l] != s[r] or r == l ? "Yes\n" : "No\n");
    }
    
    return 0;
}