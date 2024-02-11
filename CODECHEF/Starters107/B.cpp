#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    int c = n % k;
    auto f = [&](int x)
    {
        if (x > n)
            x = 0;
        
        i64 res = 1LL * (x % k) * ((n - x) % k);
        return std::array<i64, 2> {res, x};
    };

    std::array<i64, 2> ans{};
    ans = std::max({ans, f(c / 2), f((c + k) / 2)});
    std::cout << ans[1] << "\n";
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