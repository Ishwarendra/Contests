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
    
    int n;
    std::cin >> n;

    std::vector a(n, std::set<int>());
    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;

        for (int j = 0; j < c; j++)
        {
            int x;
            std::cin >> x;
            a[i].emplace(x);
        }
    }

    int x;
    std::cin >> x;

    int best = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i].count(x))
        {
            if (best == -1)
                best = i;
            else if (std::size(a[best]) > std::size(a[i]))
                best = i;
        }
    }

    if (best == -1)
    {
        std::cout << 0;
        return 0;
    }

    std::vector<int> cnt;
    for (int i = 0; i < n; i++)
    {
        if (a[i].count(x) and std::size(a[i]) == std::size(a[best]))
            cnt.emplace_back(i + 1);
    }

    std::cout << std::size(cnt) << "\n";
    for (auto x : cnt)
        std::cout << x << " ";

    return 0;
}