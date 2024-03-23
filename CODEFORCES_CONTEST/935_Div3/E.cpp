#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, x;
    std::cin >> n >> x;

    std::vector<int> p(n + 1), pos(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> p[i];
        pos[p[i]] = i;
    }

    std::vector<std::pair<int, int>> ans;
    auto add = [&](int x, int y)
    {
        ans.emplace_back(x, y);
        std::swap(p[x], p[y]);
        std::swap(pos[p[x]], pos[p[y]]);
    };

    int l = 1, r = n + 1;
    add(1, pos[x]);

    while (r - l != 1)
    {
        int m = (l + r) / 2;

        if (p[m] <= x)
            l = m;
        else
            r = m;
    }

    add(pos[x], l);
    std::cout << std::size(ans) << "\n";

    for (auto &[i, j] : ans)
        std::cout << i << " " << j << "\n";
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