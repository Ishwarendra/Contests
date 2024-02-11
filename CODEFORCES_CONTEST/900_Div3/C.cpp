#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

i64 f(int n) { return 1LL * n * (n + 1) / 2; }
i64 f(int x, int y) { return f(y) - f(x - 1); }

void solve()
{
    int n, k;
    i64 x;
    std::cin >> n >> k >> x;

    if (f(k) <= x and x <= f(n - k + 1, n))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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