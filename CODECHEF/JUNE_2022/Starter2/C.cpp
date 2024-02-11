#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(x...) 1;
#define print(x...) 1;
#endif

using i64 = long long;

void solve()
{
    i64 n, k;
    std::cin >> n >> k;

    if (n == 1)
    {
        std::cout << __builtin_popcountll(k) << "\n";
        return;
    }

    long long ans = 0;

    for (i64 i = 0; i < 30 && k > 0; i++)
    {
        if ((k & 1) != (n & 1))
        {
            ans += std::min(n - 1, k);
            k -= std::min(n - 1, k);
        }
        else
        {
            ans += std::min(n, k);
            k -= std::min(n, k);
        }

        k >>= 1;
    } 

    std::cout << ans << "\n";
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while(t--)
        solve();
    
    return 0;
}