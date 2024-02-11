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
    std::sort(std::begin(a), std::end(a));

    if (n == 1)
    {
        std::cout << "1\n";
        return;
    }

    int g = 0;
    for (int i = 1; i < n; i++)
        g = std::gcd(g, a[i] - a[i - 1]);

    i64 ans = 0;
    i64 max = a.back();
    for (int i = n - 1; i > 0; i--)
    {
        if (a[i] - a[i - 1] == g)
            continue;

        ans += (max - a[i]) / g + 1;
        break;
    }

    if (ans == 0)
        max += g;
    // print(max)
    for (int i = 0; i < n; i++)
        ans += (max - a[i]) / g;

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