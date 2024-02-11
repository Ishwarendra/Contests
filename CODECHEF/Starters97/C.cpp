#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n;
    int q;
    std::cin >> n >> q;

    int msb = 63 - __builtin_clzll(n);

    while (q--)
    {
        i64 l, r;
        std::cin >> l >> r;

        auto f = [&](auto x, int k) { return x / (1LL << k); };
        i64 ans = f(r + 1, msb + 1) - f(l, msb + 1);
        ans += f(r, msb + 1) - f(l - 1, msb + 1);

        std::cout << ans << "\n";
    }
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