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
    
    i64 max = 0, ans = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        std::cin >> a;
        max = std::max<i64>(max, a);
        sum += a;
        
        if (sum == max * 2)
            ans++;
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