#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    i64 prod = 1;
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        prod *= x;
    }

    if (2023 % prod)
        std::cout << "NO\n";
    else
    {
        std::cout << "YES\n";
        for (int i = 0; i < k - 1; i++)
            std::cout << "1 ";
        std::cout << 2023 / prod << '\n';
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