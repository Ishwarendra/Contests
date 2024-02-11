#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    int d1 = std::abs(a - 1);
    int d2 = std::abs(b - c) + std::abs(c - 1);

    if (d1 == d2) 
        std::cout << "3\n";
    else
        std::cout << (d1 < d2 ?  "1\n" : "2\n");
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