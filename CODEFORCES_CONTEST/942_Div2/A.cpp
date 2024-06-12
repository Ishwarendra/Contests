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
    
    std::multiset<int> a;
    std::vector<int> b(n);
    for (int i = 0; i < n; i++)  
    {
        int x;
        std::cin >> x;
        a.emplace(x);
    }
    
    for (int i = 0; i < n; i++)
        std::cin >> b[i];
    
    int ans = 0, i = 0;
    while (!a.empty())
    {
        int min = *std::begin(a);
        a.erase(std::begin(a));
        
        if (min > b[i])
        {
            if (!a.empty())
            {
                a.erase(std::prev(std::end(a)));
                a.emplace(min);
            }
            ans++;
        }
        
        i++;
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