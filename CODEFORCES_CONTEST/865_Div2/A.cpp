#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b;
    std::cin >> a >> b;

    if (a == 1 and b == 1)
        std::cout << "1\n1 1\n";
    else
    {
        std::cout << "2\n";
        std::cout << a - 1 << " " << 1 << "\n";
        std::cout << a << " " << b << "\n";
    }
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