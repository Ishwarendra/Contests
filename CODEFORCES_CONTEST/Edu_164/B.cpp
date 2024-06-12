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

    if (std::size(std::set(std::begin(a), std::end(a))) == 1)
    {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> pos(1, -1);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a.front())
            pos.emplace_back(i);
    }

    pos.emplace_back(n);

    int ans = 2 * n;
    for (int i = 1; i < std::size(pos); i++)
        ans = std::min(ans, pos[i] - pos[i - 1] - 1);

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