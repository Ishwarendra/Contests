#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n;
    std::cin >> n;
    
    i64 min = 0, max = 0;
    for (int i = 0; i < n; i++)  
    {
        int a;
        std::cin >> a;
        max = std::max(max + a, std::abs(min + a));
        min += a;
    }
    
    std::cout << max << "\n";
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