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

    std::map<int, int> m;
    int pxor = 0;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        m[pxor]++;
        pxor ^= a[i];

        for (int num = 0; num < (1 << 8); num++)
        {
            if (m.contains(num ^ pxor))
                ans = std::max(ans, num);
        }
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