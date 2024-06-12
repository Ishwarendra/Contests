#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int x, y;
    std::cin >> x >> y;
    
    int ans = 0;
    while (x > 0 or y > 0)
    {
        int rem = 15;
        int sub = std::min(2, y);
        y -= sub;
        rem -= sub * 4;
        
        x -= std::min(x, rem);
        ans++;
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