#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 x, k;
    std::cin >> x >> k;

    auto get = [&](i64 n)
    {
        int sum = 0;
        while (n)
            sum += n % 10, n /= 10;

        return sum;
    };

    while (get(x) % k)
        x++;

    std::cout << x << "\n";
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