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

    if (k % 2 == 0)    
        std::cout << (n % 2 ? "NO\n" : "YES\n");
    else
    {
        if (n < k)
            std::cout << (n % 2 ? "NO\n" : "YES\n");
        else
            std::cout << "YES\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}