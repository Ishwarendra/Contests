#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    std::vector<i64> a(n);
    i64 xr = 0;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        xr ^= a[i];
    }

    auto getBit = [&](i64 x, int pos) { return x >> pos & 1; };
    auto setBit = [&](i64 x, int pos) { return x |= (1LL << pos); };

    i64 ans = xr;
    for (int i = 0; i < n; i++)
    {
        xr ^= a[i];
        i64 cur = 0;

        int can = 0;
        for (int pos = 60; pos > 0; pos--)
        {
            if (can)
                cur = setBit(cur, pos);

            if (getBit(a[i], pos) and getBit(xr, pos))
                can = 1;
            if (getBit(a[i], pos) or getBit(xr, pos))
                cur = setBit(cur, pos);
        } 
        
        if (a[i] % 2 != xr % 2)
            cur |= 1;

        ans = std::max(ans, cur);
        xr ^= a[i];
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