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
    std::cin >> n;

    std::vector<int> a(n);  
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto ok = [&](int len)
    {
        int g = 0;
        for (int i = 0; i < len; i++)
        {
            for (int j = i + len; j < n; j += len)
                g = std::gcd(g, a[j] - a[j - len]);
        }

        return g != 1;
    };

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            ans += ok(i);
    }

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