#include <bits/stdc++.h>

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
    
    int x, y, n;
    std::cin >> x >> y >> n;

    if (y >= x * 3)   
        std::cout << n * x;
    else
    {
        if (n <= 2)
            std::cout << x * n;
        else if (n % 3 == 0)
            std::cout << y * (n / 3) << "\n";
        else if (n % 3 == 1)
            std::cout << y * (n - 1) / 3 + x;
        else
            std::cout << y * (n - 2) / 3 + 2 * x << "\n";
    }
    
    return 0;
}