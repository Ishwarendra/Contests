#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    if (k == 1)  
        std::cout << "1\n";
    else if (k == 2)
        std::cout << m / n + std::min(m, n - 1) << "\n";
    else if (k == 3)
    {
        if (m - n <= 0)
            std::cout << "0\n";
        else
        {
            int diff = m - n;
            diff -= diff / n;
            std::cout << diff << "\n";
        }
    }
    else
        std::cout << "0\n";
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