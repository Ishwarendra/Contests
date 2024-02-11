#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k, q;
    std::cin >> n >> k >> q;

    std::vector a(n, 0);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    int i = 0, j = 0;
    i64 ans = 0;
    while (j < n)
    {
        while (i < n and a[i] > q)
            i++;
        
        if (a[j] <= q)
            ans += std::max(0, j - i + 1 - (k - 1));
        else
            i = j + 1;

        j++;
    }

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