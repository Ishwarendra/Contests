#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 m, n;
    std::cin >> m >> n;

    if (m < n)  
        std::cout << "NO\n";
    else
    {
        while (m % 2 == 0)
            m /= 2;

        if (n % m)
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