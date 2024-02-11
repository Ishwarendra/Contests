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

    std::vector p(n, std::vector<int>(n - 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
            std::cin >> p[i][j];
    }

    std::vector<int> ans1(n), vis(n);

    for (int i = 0; i < n - 1; i++)
    {
        std::vector<int> cnt(n + 1);
        for (int j = 0; j < n; j++)
            cnt[p[j][i]]++;

        for (int j = 1; j <= n; j++)
        {
            if (cnt[j] == i + 1 and !vis[j - 1])
            {
                ans1[i + 1] = j, vis[j - 1] = 1;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            ans1.front() = i + 1;
    }
    
    auto ans2 = ans1;
    if (n % 2 == 0)
        std::swap(ans2[n / 2], ans2[n / 2 - 1]);

    auto get = [&](auto x)
    {
        std::set<std::vector<int>> s;
        for (int i = 0; i < n; i++)
        {
            std::vector<int> temp;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;

                temp.emplace_back(x[j]);
            }

            s.emplace(temp);
        }

        return s;
    };

    auto ans = get(ans1) == std::set(std::begin(p), std::end(p)) ? ans1 : ans2;

    for (int i = 0; i < n; i++)
        std::cout << ans[i] << " \n"[i == n - 1];
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