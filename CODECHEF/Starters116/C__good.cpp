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

    int sum = 1;
    int cur = 1;
    int ans = n % 2;
    for (int i = 1; i <= n; i++)  
    {
        int last = n - sum;
        ans += last > cur and (last % 2);
        cur += 2;
        sum += cur;
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