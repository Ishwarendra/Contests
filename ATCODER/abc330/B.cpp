#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l, r;
    std::cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;

        if (r <= x)
            std::cout << r << " ";
        else if (l >= x)
            std::cout << l << " ";
        else
        {
            assert(l <= x and x <= r);
            std::cout << x << " ";
        }
    }
    
    return 0;
}