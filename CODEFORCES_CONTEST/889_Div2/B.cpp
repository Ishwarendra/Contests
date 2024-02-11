#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n;
    std::cin >> n;

    for (int len = 1; len <= 1000; len++)
    {
        if (n % len == 0)
            continue;

        std::cout << len - 1 << "\n";
        return;
    }

    assert(false);
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