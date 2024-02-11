#include "bits/stdc++.h"

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    int n, m;
    std::cin >> n >> m;

    std::vector a(n, std::vector<int>(m));
    std::vector ones(n, 0);
    for (int i = 0; i < n; i++)  
    {
        for (int j = 0; j < m; j++)
            std::cin >> a[i][j];

        ones[i] = std::accumulate(std::begin(a[i]), std::end(a[i]), 0);
    }

    i64 total = std::accumulate(std::begin(ones), std::end(ones), 0LL);
    if (total % n)
    {
        std::cout << "-1\n";
        return;
    }

    int need = total / n;
    std::vector<std::array<int, 3>> ans;
    std::deque<int> space;

    for (int i = 0; i < n; i++)
    {
        if (ones[i] < need)
            space.emplace_back(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (ones[i] > need)
        {
            for (int id : space)
            {
                if (ones[i] == need)
                    break;

                for (int j = 0; j < m and ones[id] < need and ones[i] > need; j++)
                {
                    if (a[id][j] == 0 and a[i][j] == 1)
                    {
                        ans.push_back({i, id, j});
                        std::swap(a[id][j], a[i][j]);
                        ones[i]--;
                        ones[id]++;
                    }
                }

                if (ones[id] == need)
                    space.pop_front();
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (std::accumulate(std::begin(a[i]), std::end(a[i]), 0) != need)
        {
            std::cout << "-1\n";
            return;
        }
    }

    std::cout << std::size(ans) << "\n";
    for (auto [i, j, k] : ans)
        std::cout << i + 1 << " " << j + 1 << " " << k + 1 << "\n";
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