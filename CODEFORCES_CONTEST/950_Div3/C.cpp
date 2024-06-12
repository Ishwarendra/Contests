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
    
    std::vector<int> a(n), b(n);
    std::set<std::pair<int, int>> uneq;
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        std::cin >> b[i];
        if (a[i] != b[i])
            uneq.emplace(b[i], i);
    }
    
    std::set<int> in_b(std::begin(b), std::end(b));
    
    int q;
    std::cin >> q;
    
    std::vector<int> d(q);
    for (int i = 0; i < q; i++)
        std::cin >> d[i];
        
    int useless = 0;
    for (int i = 0; i < q; i++)
    {
        auto it = uneq.lower_bound({d[i], -1});
        if (in_b.count(d[i]))
        {
            useless = 0;
            if (it != std::end(uneq) and it->first == d[i])
                uneq.erase(it);
        }
        else
            useless++;
    }
    
    if (!useless and uneq.empty())
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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