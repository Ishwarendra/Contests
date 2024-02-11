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

    std::vector<int> w(n), a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> w[i];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    i64 p = 0;
    std::vector<i64> suff(n + 1);
    for (int i = n - 1; i >= 0; i--)
        suff[i] = std::max(suff[i + 1] - w[i], a[i] - w[i] * 1LL);

    for (int i = 0; i < n; i++)
    {
        std::cout << std::max(a[i] - w[i] * 1LL, p + suff[i + 1] - w[i]) << " \n"[i == n - 1];
        p = std::max(p - w[i], a[i] - w[i] * 1LL);
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