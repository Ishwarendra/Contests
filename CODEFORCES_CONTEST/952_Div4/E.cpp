#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x, y, z;
    i64 k;
    std::cin >> x >> y >> z >> k;
    
    i64 ans = 0;
    for (i64 a = 1; a <= x; a++)
    {
        for (i64 b = 1; b <= y; b++)
        {
            if (k % (a * b))
                continue;
            
            i64 c = k / a / b;
            
            if (c > z)
                continue;
            
            ans = std::max(ans, (x - a + 1) * (y - b + 1) * (z - c + 1));
        }
    }
    
    std::cout << ans << '\n';
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