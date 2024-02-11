#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n, k;
    std::cin >> n >> k;

    auto odd = (n + 1) / 2;
    auto even = n - odd;
    if (std::min(odd, even) - k + 1 < 0 or (odd - k + 1) % 2 == 0)  
        std::cout << "NO\n";
    else
    {
        odd -= k - 1;
        even -= k - 1;
        if (odd <= 1 and even == 0)
            std::cout << "NO\n";
        else
            std::cout << "YES\n";
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