#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, c;
    std::cin >> n >> c;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    i64 ans = (c + 1LL) * (c + 2) / 2;
    for (int i = 0; i < n; i++)
    {
        ans -= a[i] / 2 + 1;
        ans -= c - a[i] + 1;
    }

    int odd = 0, even = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2)
            ans += ++odd;
        else
            ans += ++even;
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