#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    i64 x;
    std::cin >> x;

    if (x < 0)
        std::cout << x / 10;
    else
        std::cout << (x + 9) / 10;
    
    return 0;
}