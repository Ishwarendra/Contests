#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> x(n), y(m);
    for (int i = 0; i < n; i++)
        std::cin >> x[i];
    for (int i = 0; i < m; i++)
        std::cin >> y[i];

    std::vector<std::pair<int, int>> people_x, people_y;
    for (int i = 0; i < k; i++)
    {
        int u, v;
        std::cin >> u >> v;

        int on_x = std::binary_search(std::begin(x), std::end(x), u);
        int on_y = std::binary_search(std::begin(y), std::end(y), v);

        if (on_x and on_y)
            continue;
        else if (on_x)
            people_x.emplace_back(u, v);
        else if (on_y)
            people_y.emplace_back(u, v);
    }

    i64 ans = 0;
    std::map<int, int> cnt;
    std::map<int, std::vector<int>> pos;

    for (auto &[u, v] : people_x)
    {
        int up = std::upper_bound(std::begin(y), std::end(y), v) - std::begin(y);
        cnt[up]++;
        pos[up].emplace_back(u);
    }

    for (auto &[up, _] : cnt)
    {
        std::map<int, int> cnt2;
        for (auto id : pos[up])
            cnt2[id]++;

        for (auto [_, f] : cnt2)
            ans -= 1LL * f * (f - 1) / 2;
    }

    for (auto [_, f] : cnt)
        ans += 1LL * f * (f - 1) / 2;

    cnt.clear();
    pos.clear();

    for (auto &[u, v] : people_y)
    {
        int next = std::upper_bound(std::begin(x), std::end(x), u) - std::begin(x);
        cnt[next]++;
        pos[next].emplace_back(v);
    }

    for (auto &[next, _] : cnt)
    {
        std::map<int, int> cnt2;
        for (auto id : pos[next])
            cnt2[id]++;

        for (auto [_, f] : cnt2)
            ans -= 1LL * f * (f - 1) / 2;
    }
    
    for (auto [_, f] : cnt)
        ans += 1LL * f * (f - 1) / 2;

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