#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h"
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, q;
    std::cin >> n >> q;

    std::vector<i64> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    std::vector<int> max[31];
    for (int i = 0; auto x : a)
    {
        int cnt = 0;
        while (x % 2 == 0)
            x /= 2, cnt++;

        max[cnt].emplace_back(i);
        i++;
    }

    while (q--)
    {
        int x;
        std::cin >> x;

        for (int y = x; y <= 30; y++)
        {
            if (max[y].empty())
                continue;

            for (int id : max[y])
            {
                a[id] += (1 << (x - 1));
                max[x - 1].emplace_back(id);
            }

            max[y].clear();
        }
    }

    for (int i = 0; i < n; i++)
        std::cout << a[i] << " \n"[i == n - 1];
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