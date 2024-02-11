#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 sum(int n) { return 1LL * n * (n + 1) / 2; }
i64 sum(int l, int r) { return sum(r) - sum(l - 1); }

void solve()
{
    int n, x, y;
    std::cin >> n >> x >> y;

    int fx = n / x, fy = n / y;
    int fc = n / std::lcm<i64>(x, y);

    fx -= fc, fy -= fc;
    std::cout << sum(n - fx + 1, n) - sum(1, fy) << "\n"; 
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