#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int a, b, c;
    std::cin >> a >> b >> c;

    int need = 3 - (b % 3);
    if (need == 3)
        need = 0;

    if (c >= need)
    {
        c -= need;
        int ans = a + b / 3 + (need > 0) + (c + 2) / 3;
        std::cout << ans << "\n";
    }
    else
        std::cout << "-1\n";
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