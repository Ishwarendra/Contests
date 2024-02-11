#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;

    auto f = [&](int s, int n)
    {
        for (int i = 1; i <= n; i += 2)
            std::cout << i + 1 + s << " " << i + s << " ";
        std::cout << "\n";
    };

    if (n == 3 or n == 1)  
        std::cout << "-1\n";
    else if (n % 2)
    {
        std::cout << "5 4 1 2 3 ";
        f(5, n - 5);
    }
    else
        f(0, n);
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