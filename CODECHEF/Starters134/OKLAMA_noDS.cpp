#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    std::multiset<int> S, B;
    i64 minSum = 0;
    auto add = [&](int x)
    {
        if (std::size(S) < std::size(B))
            S.emplace(x), minSum += x;
        else
            B.emplace(x);
        
        if (S.empty())
            return;
        
        while (true)
        {
            // if max element of S > min element of B swap them
            // otherwise everything is ok
            int maxS = *std::prev(std::end(S));
            int minB = *std::begin(B); 
            
            if (minB >= maxS)
                break;
            
            S.erase(std::prev(std::end(S)));
            minSum -= maxS;
            
            B.erase(std::begin(B));
            
            S.emplace(minB);
            minSum += minB;
            
            B.emplace(maxS);
        }
    };
    
    i64 pref = 0;
    std::vector<i64> ans(n);
    for (int i = 0; i < n; i++)
    {
        pref += a[i];
        add(a[i]);
        
        if (i % 2)
            continue;
        
        ans[i] = pref - 2 * minSum;
    }
    
    while (q--)
    {
        int k;
        std::cin >> k;
        std::cout << ans[k - 1] << " \n"[q == 0];
    }
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