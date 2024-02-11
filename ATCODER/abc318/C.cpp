#include "bits/stdc++.h"

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
    
    int n, D, P;
    std::cin >> n >> D >> P;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::sort(std::begin(a), std::end(a));
    std::vector<i64> p(n);
    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] += p[i - 1] + a[i];

    i64 ans = (n + D - 1LL) / D * P;
    for (int i = 0; i < n; i += D)
        ans = std::min(ans, p[n - i - 1] + P * 1LL * (i / D));

    std::cout << ans;
    
    return 0;
}