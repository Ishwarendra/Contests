#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    if (n & (n + 1))  
    {
        int ans = 1;
        while (ans <= n)
            ans *= 2;

        std::cout << ans - 1 << "\n";
    }
    else
    {
        int ans = 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                ans = std::max({ans, i, n / i});
        }

        std::cout << std::max(1, ans) << "\n";
    }
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