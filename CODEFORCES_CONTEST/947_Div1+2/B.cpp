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
    
    std::sort(std::begin(a), std::end(a));
    std::set<int> f;
    int started = -1;
    
    for (int i = 1; i < n; i++)
    {
        if (a[i] % a[0] == 0)
            continue;
        
        if (started == -1)
            started = a[i];
        else
        {
            if (a[i] % started != 0)
            {
                std::cout << "No\n";
                return;
            }
        }
    }
    
    std::cout << "Yes\n";
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