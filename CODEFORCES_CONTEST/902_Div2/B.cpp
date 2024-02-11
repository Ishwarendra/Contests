#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, p;
    std::cin >> n >> p;

    std::vector a(n, std::array<int, 2>());
    for (int i = 0; i < n; i++)  
        std::cin >> a[i][0];

    for (int i = 0; i < n; i++)
        std::cin >> a[i][1];

    std::sort(std::begin(a), std::end(a), [&](auto &x, auto &y)
    {
        if (x[1] == y[1])
            return x[0] > y[0];
        return x[1] < y[1];
    });

    i64 ans = p;
    int min = 0;
    for (int i = 1; i < n;)
    {
        while (i < n and a[min][0]--)
            ans += std::min(p, a[min][1]), i++;
        min++;
    }

    std::cout << std::min(1LL * n * p, ans) << "\n";
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