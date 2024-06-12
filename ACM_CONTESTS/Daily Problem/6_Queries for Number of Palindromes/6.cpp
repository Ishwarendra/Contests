#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
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
    std::vector palin(n, std::vector(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        palin[i][i] = 1;
        if (i + 1 < n)
            palin[i][i + 1] = s[i] == s[i + 1];
    }
    
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            palin[i][j] = palin[i + 1][j - 1] and (s[i] == s[j]);
        }
    }
    
    std::vector dp(n, std::vector(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if (i + 1 < n)
            dp[i][i + 1] = 2 + palin[i][i + 1];
    }
    
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1];
            dp[i][j] += palin[i][j];
        }
    }
    
    int q;
    std::cin >> q;
    
    while (q--)
    {
        int l, r;
        std::cin >> l >> r;
        l--, r--;
        std::cout << dp[l][r] << "\n";   
    }
    
    return 0;
}