#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, f, k;
    std::cin >> n >> f >> k;
    f--, k--;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)  
        std::cin >> a[i];
    
    int fav = a[f];
    std::sort(std::rbegin(a), std::rend(a));
    
    int st = -1, en = -1;
    for (int i = 0; i < n; i++)
    {
        if (fav == a[i])
        {
            if (st == -1)
                st = i;
            en = i;
        }
    }
    
    if (en <= k)
        std::cout << "YES\n";
    else if (k < st)
        std::cout << "NO\n";
    else
        std::cout << "MAYBE\n";
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