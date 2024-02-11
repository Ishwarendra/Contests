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
    
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n);
    std::vector<i64> pref(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];

    std::vector<i64> dp(n - m + 1);
    for (int i = 0; i < m; i++)
        dp[0] += 1LL * (i + 1) * a[i];

    for (int i = m; i < n; i++)
    {
        dp[i - m + 1] = dp[i - m];
        dp[i - m + 1] -= (pref[i - 1] - (i - m - 1 >= 0 ? pref[i - m - 1] : 0LL));
        dp[i - m + 1] += 1LL * m * a[i];
    }   
    

    std::cout << *std::max_element(std::begin(dp), std::end(dp));
    
    return 0;
}