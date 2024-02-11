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
    
    std::cout << "1\n";
    int n = 1e3, m = 1e3;
    std::cout << n << ' ' << m << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            std::cout << int(1) << " ";
        std::cout << "\n";
    }
    
    return 0;
}