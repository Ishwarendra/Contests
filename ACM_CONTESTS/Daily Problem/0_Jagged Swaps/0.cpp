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

    auto maxima = [&](int i)
    {
        return a[i] > std::max(a[i - 1], a[i + 1]);
    };

    int can = 1;
    while (can)
    {
        can = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (maxima(i))
            {
                std::swap(a[i], a[i + 1]);
                can = 1;
            }
        }
    }

    if (std::is_sorted(std::begin(a), std::end(a)))
        std::cout << "YES\n";
    else
        std::cout << "NO\n";
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