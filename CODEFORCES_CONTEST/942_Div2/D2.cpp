#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;
    
    i64 ans = 0;
    for (int A = 1; A * A <= n; A++)
    {
        for (int B = 1; B * B <= m; B++)
        {
            int g = std::gcd(A, B);
            if (g != 1 or A * g > n or B * g > m)
                continue;
            
            ans += (std::min(n / A, m / B)) / (A + B);
        }
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