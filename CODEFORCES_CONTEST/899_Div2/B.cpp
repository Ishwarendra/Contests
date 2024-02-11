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

    std::vector<std::vector<int>> a(n);

    for (int i = 0; i < n; i++)  
    {
        int len;
        std::cin >> len;
        a[i].resize(len);

        for (int j = 0; j < len; j++)
            std::cin >> a[i][j];
    }

    int ans = 0;
    for (int leave = 1; leave <= 50; leave++)
    {
        std::set<int> s;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (std::binary_search(std::begin(a[i]), std::end(a[i]), leave))
                continue;

            cnt++;
            s.insert(std::begin(a[i]), std::end(a[i]));
        }
        
        if (cnt != n and cnt != 0)
            ans = std::max<int>(ans, std::size(s));
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