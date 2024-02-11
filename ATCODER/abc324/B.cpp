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
    
    i64 n;
    std::cin >> n;

    while (n % 2 == 0)
        n /= 2;
    while (n % 3 == 0)
        n /= 3;

    std::cout << (n == 1 ? "Yes" : "No");
    
    return 0;
}