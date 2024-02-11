#include <bits/stdc++.h>

#ifdef LOCAL
#include "F:\CPP\Debug\debug.h" 
#else
#define trace(...) 1;
#define print(...) 1;
#endif

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;

    std::vector<std::pair<i64, int>> event(n << 1); 
    for (int i = 0; i < n; ++i)
    {
        i64 x, y;
        std::cin >> x >> y;

        event[i << 1] = {x, 1};
        event[i << 1 | 1] = {y + 1, -1};
    }

    std::sort(std::begin(event), std::end(event));
    std::vector<i64> ans(n + 1);

    i64 lastEve = 0;
    int id = 0;

    for (int i = 0; i < n * 2; )
    {
        i64 curEve = event[i].first;

        if (id < n + 1)
            ans[id] += curEve - lastEve;

        while (i < 2 * n and event[i].first == curEve)
        {
            id += event[i].second;
            i++;
        }

        lastEve = curEve; 
    }

    for (int i = 1; i <= n; ++i)
        std::cout << ans[i] << " \n"[i == n];
    
    return 0;
}