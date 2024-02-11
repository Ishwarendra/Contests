#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    auto check = [&](int x)
    {
        for (int i = 1; 1LL * i * i <= x; i++)
        {
            if (x % i == 0)
            {
                int f1 = i;
                int f2 = x / i;
                if (f1 != 1 and f1 <= m)
                    return true;
                if (f2 != 1 and f2 <= m)
                    return true;
            }
        }

        return false;
    };     

    if (check(n))
        std::cout << "NO\n";
    else
        std::cout << "YES\n";
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