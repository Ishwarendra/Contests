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

    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    auto get = [&]()
    {
        std::vector pr(n, std::vector(m, 0));
        auto pc = pr;

        for (int i = 0; i < n; i++)
        {
            pr[i][0] = a[i][0] == '#';
            for (int j = 1; j < m; j++)
                pr[i][j] = pr[i][j - 1] + (a[i][j] == '#');
        }

        for (int j = 0; j < m; j++)
        {
            pc[0][j] = a[0][j] == '#';
            for (int i = 1; i < n; i++)
                pc[i][j] = pc[i - 1][j] + (a[i][j] == '#');
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int r = std::min(k + 1, n - i);
                int c = std::min(k + 1, m - j);

                int cur = 0;
                if (r <= c)
                {
                    int range = k;
                    for (int id = i; id < i + r; id++)
                    {
                        cur += pr[id][std::min(j + range, m - 1)];
                        if (j)
                            cur -= pr[id][j - 1];

                        range--;
                    }
                }
                else
                {
                    int range = k;
                    for (int id = j; id < j + c; id++)
                    {
                        cur += pc[std::min(i + range, n - 1)][id];
                        if (i)
                            cur -= pc[i - 1][id];

                        range--;
                    }
                }

                ans = std::max(ans, cur);
            }
        }

        return ans;
    };

    int ans = get();
    std::reverse(std::begin(a), std::end(a));
    ans = std::max(ans, get());

    for (auto &x : a)
        std::reverse(std::begin(x), std::end(x));
    ans = std::max(ans, get());

    std::reverse(std::begin(a), std::end(a));
    ans = std::max(ans, get());

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