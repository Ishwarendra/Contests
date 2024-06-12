#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int h, n;
    std::cin >> h >> n;
    
    std::vector<int> a(n), c(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
        std::cin >> c[i];
    
    std::set<std::array<i64, 3>> pq;
                        
    for (int i = 0; i < n; i++)
        pq.insert({1, -a[i], i});
    
    i64 turn = 0, time = 1;
    while (h >= 0)
    {
        while ((*std::begin(pq))[0] <= time)
        {
            auto [cooldown, damage, id] = *std::begin(pq);
            h += damage;
            pq.erase(std::begin(pq));
            pq.insert({cooldown + c[id], damage, id});
        }
        
        turn++;
        if (h <= 0)
            break;
        
        time = (*std::begin(pq))[0];
        turn = time - 1;
    }
    
    std::cout << turn << "\n";
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