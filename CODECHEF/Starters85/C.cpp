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

    if (n <= 2)  
        std::cout << "0\n";
    else if (n <= 4)
        std::cout << n - 1 << "\n"; 
    else
    {
        i64 cost = 2;
        n -= 3;
        cost += (n + 1) / 2 + 2 * (n / 2);
        std::cout << cost << "\n";
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