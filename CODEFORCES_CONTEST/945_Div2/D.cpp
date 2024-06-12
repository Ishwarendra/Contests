#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, k;
    std::cin >> n >> k;
    
    auto query = [&](int l, int x)
    {
        std::cout << "? " << l + 1 << " " << x << std::endl;
        int res;
        std::cin >> res;
        return res;  
    };
    
    int max = n;
    while (max > 1)
    {
        if (query(0, n * max) == n + 1)
            max--;
        else
            break;
    }
    
    int ans = -1;
    for (int f = 1; f <= n / k; f++)
    {
        int need = max * f;
        int id = 0;
        int cnt = 0;
        while (cnt < k and id < n)
        {
            int next = query(id, need);
            id = next;
            cnt++;
            
            if (next == n + 1)
                cnt = 0;
        }
        
        if (cnt == k and id == n)
            ans = std::max(ans, need);
    }
    
    std::cout << "! " << ans << std::endl;
    int res;
    std::cin >> res;
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