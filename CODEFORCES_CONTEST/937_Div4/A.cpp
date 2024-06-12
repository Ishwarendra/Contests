#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    if (a < b and b < c)  
        std::cout << "STAIR\n";
    else if (a < b and b > c) 
        std::cout << "PEAK\n";
    else
        std::cout << "NONE\n";
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