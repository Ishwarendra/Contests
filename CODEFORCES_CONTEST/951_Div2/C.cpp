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
    
    std::vector<std::pair<int, int>> a(n);
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    
    std::sort(std::begin(a), std::end(a));
    std::vector<i64> ans(n, -1);
    
    auto good = [&](int mid)
    {
        i64 prod = 1LL * a[0].first * mid;
        i64 sum = mid;
        std::vector<i64> r(n);
        r[0] = mid;
        r[a[0].second] = mid;
        
        for (int i = 1; i < n; i++)  
        {
            i64 need = (prod + a[i].first - 1) / a[i].first;
            if (1LL * need * a[i].first > int(1e9))
                return false;
            
            sum += need;
            r[a[i].second] = need;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (r[a[i].second] * a[i].first <= sum)
                return false;
        }
        
        ans = r;
        return true;
    };
    
    int left = 100, right = 1e9 / 20;
    
    while (left <= right)
    {
        int mid = std::midpoint(left, right);
        if (!good(mid))
             left = mid + 1;
         else
            right = mid - 1;
    }
    
    if (ans[0] == -1)
    {
        std::cout << -1 << "\n";
        return;
    }
    
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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