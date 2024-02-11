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
    
    int n;
    std::cin >> n;

    int lastz = 0, lasto = 0;
    for (int i = 0; i < n; ++i)
    {
        int x;
        std::cin >> x;

        if (x == 0)
            lastz = i + 1;
        else
            lasto = i + 1;
    }

    std::cout << std::min(lastz, lasto) << "\n";
    
    return 0;
}