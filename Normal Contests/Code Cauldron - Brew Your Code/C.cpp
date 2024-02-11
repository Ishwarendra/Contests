#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n, p;
    std::cin >> n >> p;

    if (p / 3 + p % 3 > n)  
        std::cout << "-1\n";
    else
        std::cout << p / 3 << " " << std::max(0LL, (p - n + 1) / 2) << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}