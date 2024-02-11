#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, n, m;
    std::cin >> a >> b >> n >> m;

    i64 ans1 = 1LL * b * n;
    i64 x = n / (1 + m);
    i64 ans2 = 1LL * a * m * x + 1LL * b * (n - m * x - x);
    i64 ans3 = 1LL * a * m * x + 1LL * a * (n - m * x - x);

    std::cout << std::min({ans1, ans2, ans3}) << "\n";
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