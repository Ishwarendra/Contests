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
    
    int a, b, d;
    std::cin >> a >> b >> d;

    while (a <= b)
    {
        std::cout << a << " ";
        a += d;
    }
    
    return 0;
}