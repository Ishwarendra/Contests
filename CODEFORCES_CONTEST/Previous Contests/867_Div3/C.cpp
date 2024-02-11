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

    auto apSum = [&](int f, int l)
    {
        int n = l - f + 1;
        return 1LL * n * (f + l);
    };

    i64 ans = apSum(2, n - 2);
    ans += 3 + n - 1;
    ans += 4LL * n;

    std::cout << ans << "\n";
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