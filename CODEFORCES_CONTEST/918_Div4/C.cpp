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

    i64 sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        sum += x;
    }

    int s = std::sqrt(sum) - 1;
    s = std::max(0, s);
    while (1LL * s * s < sum)
        s++;

    std::cout << (1LL * s * s == sum ? "YES\n" : "NO\n");
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