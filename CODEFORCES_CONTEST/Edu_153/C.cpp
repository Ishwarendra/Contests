#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
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

    int ans = 0;
    int pmin = a[0];
    std::set<int> s;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < pmin)
            pmin = a[i];
        else
        {
            auto it = s.lower_bound(a[i]);
            if (it == std::begin(s))
                ans++;
            
            s.emplace(a[i]);
        }
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