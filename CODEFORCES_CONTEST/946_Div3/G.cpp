#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

/**
 * If at any point you can buy happiness buy it.
 * If later you find a better option then we can exchange our current happiness with bad happiness bought earlier
 */

void solve()
{
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> c(n);
    for (int i = 0; i < n; i++)  
        std::cin >> c[i];
    
    std::multiset<int, std::greater<>> m;
    i64 have = 0, ans = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (have >= c[i]) 
        {
            ans++;
            m.emplace(c[i]);
            have -= c[i];
        }
        else
        {
            int worst = *std::begin(m);
            if (worst >= c[i])
            {
                have += worst - c[i];
                m.erase(std::begin(m));
                m.emplace(c[i]);    
            }
        }

        have += x;
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