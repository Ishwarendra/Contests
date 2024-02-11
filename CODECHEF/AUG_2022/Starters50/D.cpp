#include <bits/stdc++.h>

#ifdef LOCAL
#include <F:\CPP\Debug\debug.h> 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x, y;
    std::cin >> n >> x >> y;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i)  
        std::cin >> a[i];

    int op = 0;
    if (y >= x)
    {
        int max = *std::max_element(std::begin(a), std::end(a));
        std::cout << (max + y - 1) / y << "\n";
    }
    else
    {
        int ans = 0;
        int to_sub = 0;

        for (int i = n - 1; i >= 0; --i)        
        {
            a[i] -= 1LL * to_sub * y;
            if (a[i] <= 0)
                continue;

            int need = (a[i] + x - 1) / x;
            ans += need;
            to_sub += need; 
        }

        std::cout << ans << "\n";
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    
    while (t--)
        solve();
    
    return 0;
}