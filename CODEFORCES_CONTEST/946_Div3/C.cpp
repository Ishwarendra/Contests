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
    
    std::map<std::pair<int, int>, int> f[3]{};
    std::map<std::tuple<int, int, int>, int> m;
    
    i64 ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        ans += f[0][{a[i + 1], a[i + 2]}];
        ans += f[1][{a[i], a[i + 2]}];
        ans += f[2][{a[i], a[i + 1]}];
        ans -= 3 * m[{a[i], a[i + 1], a[i + 2]}];
        
        f[0][{a[i + 1], a[i + 2]}]++;
        f[1][{a[i], a[i + 2]}]++;
        f[2][{a[i], a[i + 1]}]++;
        m[{a[i], a[i + 1], a[i + 2]}]++;
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