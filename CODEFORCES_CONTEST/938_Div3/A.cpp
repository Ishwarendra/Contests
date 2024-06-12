#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, a, b;
    std::cin >> n >> a >> b;

    if (2 * a <= b)  
        std::cout << a * n << "\n";
    else
        std::cout << (b * (n / 2)) + a * (n % 2) << "\n";
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