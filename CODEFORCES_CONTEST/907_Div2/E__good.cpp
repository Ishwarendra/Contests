#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];

    auto getBit = [&](int x, int pos) { return x >> pos & 1; };
    auto get = [&](auto x, int mask)
    {
        for (int i = 0; i < n; i++)
        {
            if (getBit(mask, i))
                x[i] = 0;
        }

        int ans = 0;
        for (int i = 1; i < n; i++)
            ans += std::gcd(x[i], x[i - 1]) == 1;
        return ans;
    };  

    int ans = n;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (__builtin_popcount(mask) > k)
            continue;

        ans = std::min(ans, get(a, mask));
    }

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