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
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    for (int i = 0; i < n; i++)
    {
        if (std::is_sorted(std::begin(a), std::end(a)))
        {
            std::cout << "Yes\n";
            return;
        }
        
        std::rotate(std::begin(a), std::begin(a) + 1, std::end(a));
    }
    
    std::cout << "No\n";
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