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

    std::function<i64(int, int)> C = [&](int n, int r)
    {
        if (r == 0)
            return 1LL;
        return 1LL * n * C(n - 1, r - 1) / r;
    };

    for (int x = 0; x <= n; x++)
    {
        int y = n - x;
        if (C(x, 2) + C(y, 2) == k)
        {
            std::cout << "YES\n";
            for (int j = 0; j < x; j++)
                std::cout << "1 ";
            for (int j = 0; j < y; j++)
                std::cout << "-1 ";

            std::cout << "\n";
            return;
        }
    }

    std::cout << "NO\n";
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