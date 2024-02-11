#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    if (n == 1 and m == 1)
    {
        std::cout << "0\n";
        return;
    }

    if (m > n)
        std::swap(n, m);

    std::cout << (n - 1 + m + m - 1) << "\n";  
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