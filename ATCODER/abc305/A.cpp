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
    
    int n;
    std::cin >> n;

    int ans = 100;
    int p = 5;
    for (int i = 0; i <= 100; i += 5)
    {
        if (ans > std::abs(n - i))
        {
            ans = std::abs(n - i);
            p = i;
        }
    }

    std::cout << p;
    
    return 0;
}