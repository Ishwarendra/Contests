#include "bits/stdc++.h"

#ifdef LOCAL
#include "/Users/ishwar/Debug/debug.h" 
#else
#define print(...) 1;
#endif

using i64 = long long;

void solve()
{
    std::array<int, 3> a{};
    for (int i = 0; i < 3; i++)
        std::cin >> a[i];

    if (a[0] == 0 and a[1] == 0)
    {
        std::cout << (a[2] <= 1 ? 0 : -1) << "\n";
        return;
    }

    std::queue<std::pair<int, int>> q;

    if (a[0])
        q.emplace(2, 0), a[0]--;
    else
        q.emplace(1, 0), a[1]--;

    int max = 0;
    while (!q.empty())
    {
        auto [sz, dep] = q.front();
        q.pop();
        max = std::max(max, dep);

        if (a[3 - sz] < 0)
        {
            std::cout << "-1\n";
            return;
        }

        for (int i = 0; i < sz; i++)
        {
            if (a[0] > 0)
                q.emplace(2, dep + 1), a[0]--;
            else if (a[1] > 0)
                q.emplace(1, dep + 1), a[1]--;
            else if (a[2] > 0)
                q.emplace(0, dep + 1), a[2]--;
            else
            {
                std::cout << "-1\n";
                return;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (a[i] != 0)
        {
            std::cout << "-1\n";
            return;
        }
    }
    
    std::cout << max << "\n";
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