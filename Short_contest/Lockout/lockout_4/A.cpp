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

    auto isPermutation = [&](int i, int j)
    {
        std::vector<int> vis(j - i + 1);
        for (int k = i; k <= j; k++)
        {
            if (a[k] <= std::size(vis))
                vis[a[k] - 1]++;
        }

        for (auto x : vis)
        {
            if (x != 1)
                return false;
        }

        return true;
    };

    std::set<std::pair<int, int>> ans;
    int max_id = std::max_element(std::begin(a), std::end(a)) - std::begin(a);
    int max = a[max_id];
    
    if (isPermutation(0, max - 1) and isPermutation(max, n - 1))
        ans.emplace(max, n - max);
    if (isPermutation(0, n - max - 1) and isPermutation(n - max, n - 1))
        ans.emplace(n - max, max);

    std::cout << std::size(ans) << "\n";
    for (auto [x, y] : ans)
        std::cout << x << " " << y << "\n";
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