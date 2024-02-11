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

    std::multiset<int, std::greater<>> options;
    i64 ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
            options.emplace(a[i]);
        else
        {
            if (!options.empty())
            {
                ans += *std::begin(options);
                options.erase(std::begin(options));
            }
        }
    }

    std::cout << ans << "\n";
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