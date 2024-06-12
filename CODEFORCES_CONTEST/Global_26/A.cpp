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
    std::map<int, int> f;
    for (int i = 0; i < n; i++)  
    {
        std::cin >> a[i];
        f[a[i]]++;
    }
    
    if (std::size(std::set(std::begin(a), std::end(a))) == 1)
    {
        std::cout << "NO\n";
        return;
    }
    
    std::cout << "YES\n";
    std::string ans(n, 'R');
    
    for (int i = 0; i < n; i++)
    {
        if (f[a[i]] > 1)
        {
            ans[i] = 'B';
            std::cout << ans << '\n';
            return;
        }
    }
    
    ans[0] = 'B';
    std::cout << ans << '\n';
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