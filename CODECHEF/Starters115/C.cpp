#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    if (n == 1 and x == 0)
        std::cout << "1\n";
    else if (x >= n - 1)
        std::cout << "-1\n";
    else
    {
        for (int i = 1; i <= n - x - 2; i++)
            std::cout << i << " ";

        std::cout << n << " ";

        for (int i = n - 1 - x; i < n; i++)
            std::cout << i << " ";
        std::cout << "\n";
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