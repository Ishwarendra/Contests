#include <bits/stdc++.h>

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
    
    int n;
    std::cin >> n;

    i64 ans = 0;
    auto get = [&](int x)
    {
        i64 a = 1;
        while (x)
        {
            a *= x % 10;
            x /= 10;
        }

        return a;
    };

    for (int i = n; i >= std::max(0, n - 100); i--)
        ans = std::max(ans, get(i));

    std::cout << ans << "\n";
    
    return 0;
}