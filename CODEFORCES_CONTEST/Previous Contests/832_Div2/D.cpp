#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n), xsum(n + 1), zeroes(n + 1);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
        xsum[i + 1] = xsum[i] ^ a[i];
        zeroes[i + 1] = zeroes[i] + (a[i] == 0);
    }

    std::array<std::map<int, std::vector<int>>, 2> adj;
    for (int i = 0; i < n + 1; i++)
        adj[i % 2][xsum[i]].emplace_back(i);

    auto query = [&](int l, int r) -> int
    {
        if (zeroes[r] - zeroes[l - 1] == r - l + 1)
            return 0;
        if ((r - l + 1) % 2)
            return ((xsum[r] ^ xsum[l - 1]) == 0 ? 1 : -1);
        if (a[l - 1] == 0)
            return ((xsum[r] ^ xsum[l]) == 0 ? 1 : -1);
        if (a[r - 1] == 0)
            return ((xsum[r - 1] ^ xsum[l - 1]) == 0 ? 1 : -1);

        auto &p1 = adj[l % 2][xsum[l - 1]];
        auto &p2 = adj[r % 2 == 0][xsum[r]];

        auto it1 = std::lower_bound(std::begin(p1), std::end(p1), l);
        auto it2 = std::lower_bound(std::begin(p2), std::end(p2), l - 1);

        int moves = 3;
        if (it1 != std::end(p1) and *it1 <= r)
            moves -= ((xsum[r] ^ xsum[*it1]) == 0);
        else if (it2 != std::end(p2) and *it2 <= r)
            moves -= ((xsum[l - 1] ^ xsum[*it2])== 0);

        return (moves == 3 ? -1 : moves);
    };

    while (q--)
    {
        int l, r;
        std::cin >> l >> r;

        std::cout << query(l, r) << "\n";
    }

    return 0;
}