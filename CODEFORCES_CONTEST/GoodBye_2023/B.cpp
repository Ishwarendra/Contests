#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

int smallest(int a)
{
    for (int i = 2; 1LL * i * i <= a; i++)
    {
        if (a % i == 0)
            return i;
    }

    return a;
}

void solve()
{
    int a, b;
    std::cin >> a >> b;

    i64 ans = b;
    if (a == 1) 
        ans *= b;
    else
        ans *= std::min(smallest(a), smallest(b));

    std::cout << ans << "\n";
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